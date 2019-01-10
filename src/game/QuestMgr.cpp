#include "Database/DatabaseEnv.h"
#include "Policies/SingletonImp.h"
#include "World.h"
#include "ObjectMgr.h"
#include "QuestDef.h"
#include "QuestMgr.h"

INSTANTIATE_SINGLETON_1(QuestMgr);

QuestMgr::QuestMgr()
{
}

// Setting a worldstate will save it to DB
void QuestMgr::setWorldState(uint32 index, uint64 value)
{
	  static SqlStatementID insState;
	  static SqlStatementID updState;
    WorldStatesMap::const_iterator it = m_worldstates.find(index);
    if (it != m_worldstates.end())
    {
        SqlStatement stateUpdate = CharacterDatabase.CreateStatement(updState, "UPDATE worldstates SET value = ? WHERE entry = ?");
        stateUpdate.addUInt32(uint32(value));
        stateUpdate.addUInt32(index);

        stateUpdate.Execute();
    }
    else
    {
        SqlStatement stateInsert = CharacterDatabase.CreateStatement(insState, "INSERT INTO worldstates (entry, value) VALUES (?, ?)");
        stateInsert.addUInt32(index);
        stateInsert.addUInt32(uint32(value));
        stateInsert.Execute();
    }
    m_worldstates[index] = value;
}

void QuestMgr::initialize()
{
    LoadWorldStates();
    InitDailyQuestResetTime();
    InitWeeklyQuestResetTime();
}

uint64 QuestMgr::getWorldState(uint32 index) const
{
    WorldStatesMap::const_iterator it = m_worldstates.find(index);
    return it != m_worldstates.end() ? it->second : 0;
}

void QuestMgr::InitDailyQuestResetTime()
{
    time_t wstime = time_t(getWorldState(WS_DAILY_QUEST_RESET_TIME));
    m_NextDailyQuestReset = wstime ? wstime : GetNextTimeWithDayAndHour(-1, 6);
    if (!wstime)
        setWorldState(WS_DAILY_QUEST_RESET_TIME, uint64(m_NextDailyQuestReset));
}

void QuestMgr::InitWeeklyQuestResetTime()
{
    time_t wstime = time_t(getWorldState(WS_WEEKLY_QUEST_RESET_TIME));
    m_NextWeeklyQuestReset = wstime ? wstime : GetNextTimeWithDayAndHour(4, 6);
    if (!wstime)
        setWorldState(WS_WEEKLY_QUEST_RESET_TIME, uint64(m_NextWeeklyQuestReset));
}

void QuestMgr::LoadWorldStates()
{
    QueryResult* result = CharacterDatabase.Query("SELECT entry, value FROM worldstates");

    if (!result)
    {
        sLog.outString(">> Loaded 0 world states. DB table `worldstates` is empty!");
        sLog.outString();
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        m_worldstates[fields[0].GetUInt32()] = fields[1].GetUInt32();
        ++count;
    }
    while (result->NextRow());
    
    delete result;
    
    sLog.outString(">> Loaded %u world states", count);
    sLog.outString();
}

// int8 dayOfWeek: 0 (sunday) to 6 (saturday)
time_t QuestMgr::GetNextTimeWithDayAndHour(int8 dayOfWeek, int8 hour)
{
    if (hour < 0 || hour > 23)
        hour = 0;
    time_t curr = time(NULL);
    tm localTm;
    localtime_r(&curr, &localTm);
    localTm.tm_hour = hour;
    localTm.tm_min  = 0;
    localTm.tm_sec  = 0;
    uint32 add;
    if (dayOfWeek < 0 || dayOfWeek > 6)
        dayOfWeek = (localTm.tm_wday+1)%7;
    if (localTm.tm_wday >= dayOfWeek)
        add = (7 - (localTm.tm_wday - dayOfWeek)) * DAY;
    else
        add = (dayOfWeek - localTm.tm_wday) * DAY;
    return mktime(&localTm) + add;
}

void QuestMgr::Update(time_t gametime)
{
	if (gametime > m_NextDailyQuestReset)
		ResetDailyQuests();
  if (gametime > m_NextWeeklyQuestReset)
  	ResetWeeklyQuests();
}

void QuestMgr::ResetWeeklyQuests()
{
	static SqlStatementID updQuest;
	
	for (auto& v : sObjectMgr.GetQuestTemplates())
	{
		if (v.second->GetQuestFlags() & QUEST_FLAGS_WEEKLY)
		{
			SqlStatement questUpdate = CharacterDatabase.CreateStatement(updQuest, "UPDATE character_queststatus SET status = 0, rewarded = 0 WHERE quest = ? and status = 1 and rewarded = 1");
      questUpdate.addUInt32(v.first);
      questUpdate.Execute();
      
      
      // Reregister all players
      auto const& sessions = sWorld.GetAllSessions();

      for (auto& session : sessions)
      {
        Player* player = session.second->GetPlayer();
        if (!player)
            continue;
        
        const QuestStatusData* qStatusData = player->GetQuestStatusData(v.first);
        if (!qStatusData)
        	continue;
        	
        if (qStatusData->m_status == QUEST_STATUS_COMPLETE && 
        	  qStatusData->m_rewarded)
        {
          player->SetQuestStatus(v.first, QUEST_STATUS_NONE);
          player->getQuestStatusMap()[v.first].m_rewarded = false;
        }
      }
		}
	}
	m_NextWeeklyQuestReset = GetNextTimeWithDayAndHour(4, 6);
	setWorldState(WS_WEEKLY_QUEST_RESET_TIME, uint64(m_NextWeeklyQuestReset));
}

void QuestMgr::ResetDailyQuests()
{
	static SqlStatementID updQuest;
	
	for (auto& v : sObjectMgr.GetQuestTemplates())
	{
		if (v.second->GetQuestFlags() & QUEST_FLAGS_DAILY)
		{
			SqlStatement questUpdate = CharacterDatabase.CreateStatement(updQuest, "UPDATE character_queststatus SET status = 0, rewarded = 0 WHERE quest = ? and status = 1 and rewarded = 1");
      questUpdate.addUInt32(v.first);
      questUpdate.Execute();
      
      
      // Reregister all players
      auto const& sessions = sWorld.GetAllSessions();

      for (auto& session : sessions)
      {
        Player* player = session.second->GetPlayer();
        if (!player)
            continue;
        
        const QuestStatusData* qStatusData = player->GetQuestStatusData(v.first);
        if (!qStatusData)
        	continue;
        
        if (qStatusData->m_status == QUEST_STATUS_COMPLETE && 
        	  qStatusData->m_rewarded)
        {
          player->SetQuestStatus(v.first, QUEST_STATUS_NONE);
          player->getQuestStatusMap()[v.first].m_rewarded = false;
        }
      }
		}
	}
	m_NextDailyQuestReset = GetNextTimeWithDayAndHour(-1, 6);
	setWorldState(WS_DAILY_QUEST_RESET_TIME, uint64(m_NextDailyQuestReset));
}
