#ifndef MANGOSSERVER_QUESTMGR_H
#define MANGOSSERVER_QUESTMGR_H
#include "Common.h"
#include "Timer.h"
#include "Policies/Singleton.h"
#include "SharedDefines.h"
#include "ace/Atomic_Op.h"

#define QUEST_FLAGS_DAILY                   0x00001000   // Used to know quest is Daily one
#define QUEST_FLAGS_WEEKLY                  0x00008000

enum WorldStates
{
    WS_ARENA_DISTRIBUTION_TIME  = 20001,                     // Next arena distribution time
    WS_WEEKLY_QUEST_RESET_TIME  = 20002,                     // Next weekly reset time
    WS_BG_DAILY_RESET_TIME      = 20003,                     // Next daily BG reset time
    WS_CLEANING_FLAGS           = 20004,                     // Cleaning Flags
    WS_DAILY_QUEST_RESET_TIME   = 20005,                     // Next daily reset time
    WS_GUILD_DAILY_RESET_TIME   = 20006,                     // Next guild cap reset time
    WS_MONTHLY_QUEST_RESET_TIME = 20007,                     // Next monthly reset time
};

class QuestMgr
{
public:
	QuestMgr();
	void initialize();
  void Update(time_t gametime);
  uint64 getWorldState(uint32 index) const;
  void setWorldState(uint32 index, uint64 value);
  time_t GetNextTimeWithDayAndHour(int8 dayOfWeek, int8 hour);
  
  	
private:
	void InitDailyQuestResetTime();
	void InitWeeklyQuestResetTime();
	void LoadWorldStates();
	
	void ResetDailyQuests();
	void ResetWeeklyQuests();

private:
	time_t m_NextDailyQuestReset;
	time_t m_NextWeeklyQuestReset;
	typedef std::map<uint32, uint64> WorldStatesMap;
  WorldStatesMap m_worldstates;
};

#define sQuestMgr MaNGOS::Singleton<QuestMgr>::Instance()

#endif
