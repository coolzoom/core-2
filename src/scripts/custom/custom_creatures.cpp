/* Copyright (C) 2009 - 2010 ScriptDevZero <http://github.com/scriptdevzero/scriptdevzero>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "scriptPCH.h"
#include "custom.h"
#include "ScriptedAI.h"
#include <ctime>

// TELEPORT NPC
  
bool GossipHello_TeleportNPC(Player *player, Creature *_Creature)   
{
    // HORDE
    if (player->GetTeam() == HORDE)
    {
        // player->ADD_GOSSIP_ITEM(5, "[GM 岛]"                  , GOSSIP_SENDER_MAIN, 74);
		player->ADD_GOSSIP_ITEM(7, "[主城传送]"                  , GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(7, "[出生地点]"                  , GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(7, "[副本传送]"                  , GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(7, "[团队副本]"                  , GOSSIP_SENDER_MAIN, 101);
		player->ADD_GOSSIP_ITEM(5, "[古拉巴什竞技场]"            , GOSSIP_SENDER_MAIN, 4015);
		player->ADD_GOSSIP_ITEM(7, "[卡利姆多]"                  , GOSSIP_SENDER_MAIN, 6010);
		player->ADD_GOSSIP_ITEM(7, "[东部王国]"                  , GOSSIP_SENDER_MAIN, 6020);
		player->ADD_GOSSIP_ITEM(7, "[风景传送]", GOSSIP_SENDER_MAIN, 6030);
		//player->ADD_GOSSIP_ITEM(7, "[飞行全开]", GOSSIP_SENDER_MAIN, 6040);
		//player->ADD_GOSSIP_ITEM(7, "[拍卖行]", GOSSIP_SENDER_MAIN, 6050);
		player->ADD_GOSSIP_ITEM(7, "[银行]", GOSSIP_SENDER_MAIN, 6060);
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    }
    // ALLIANCE
    else
    {
        //player->ADD_GOSSIP_ITEM(5, "[GM 岛]"                   , GOSSIP_SENDER_MAIN, 74);
		player->ADD_GOSSIP_ITEM(7, "[主城传送]"                  , GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(7, "[出生地点]"                  , GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM(7, "[副本传送]"                  , GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(7, "[团队副本]"                  , GOSSIP_SENDER_MAIN, 101);
		player->ADD_GOSSIP_ITEM(5, "[古拉巴什竞技场]"            , GOSSIP_SENDER_MAIN, 4015);
		player->ADD_GOSSIP_ITEM(7, "[卡利姆多]"                  , GOSSIP_SENDER_MAIN, 6010);
		player->ADD_GOSSIP_ITEM(7, "[东部王国]"                  , GOSSIP_SENDER_MAIN, 6020);
		player->ADD_GOSSIP_ITEM(7, "[风景传送]", GOSSIP_SENDER_MAIN, 6030);
		//player->ADD_GOSSIP_ITEM(7, "[飞行全开]", GOSSIP_SENDER_MAIN, 6040);
		//player->ADD_GOSSIP_ITEM(7, "[拍卖行]", GOSSIP_SENDER_MAIN, 6050);
		player->ADD_GOSSIP_ITEM(7, "[银行]", GOSSIP_SENDER_MAIN, 6060);
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    }
    return true;
}

void SendDefaultMenu_TeleportNPC(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1: // Cities [HORDE]
            player->ADD_GOSSIP_ITEM(5, "[奥格瑞玛]"              , GOSSIP_SENDER_MAIN, 20);
            player->ADD_GOSSIP_ITEM(5, "[幽暗城]"                , GOSSIP_SENDER_MAIN, 21);
            player->ADD_GOSSIP_ITEM(5, "[雷霆崖]"                , GOSSIP_SENDER_MAIN, 22);
			//BL战场
			player->ADD_GOSSIP_ITEM(5, "[奥特兰克战场]", GOSSIP_SENDER_MAIN, 26);
			player->ADD_GOSSIP_ITEM(5, "[战歌峡谷]", GOSSIP_SENDER_MAIN, 27);
			player->ADD_GOSSIP_ITEM(5, "[阿拉希战场]", GOSSIP_SENDER_MAIN, 28);

			//player->ADD_GOSSIP_ITEM(5, "[剃刀岭]"                , GOSSIP_SENDER_MAIN, 4017);
            player->ADD_GOSSIP_ITEM(0, "[返回]"                  , GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 2: // Cities [ALLIANCE]
            player->ADD_GOSSIP_ITEM(5, "[暴风城]"                , GOSSIP_SENDER_MAIN, 23);
            player->ADD_GOSSIP_ITEM(5, "[铁炉堡]"                , GOSSIP_SENDER_MAIN, 24);
            player->ADD_GOSSIP_ITEM(5, "[达纳苏斯]"              , GOSSIP_SENDER_MAIN, 25);
			//LM战场
			player->ADD_GOSSIP_ITEM(5, "[奥特兰克战场]", GOSSIP_SENDER_MAIN, 29);
			player->ADD_GOSSIP_ITEM(5, "[战歌峡谷]", GOSSIP_SENDER_MAIN, 30);
			player->ADD_GOSSIP_ITEM(5, "[阿拉希战场]", GOSSIP_SENDER_MAIN, 31);
			//player->ADD_GOSSIP_ITEM(5, "[闪金镇]"                , GOSSIP_SENDER_MAIN, 4018);
			player->ADD_GOSSIP_ITEM(0, "[返回]"                  , GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3: // Starting Places [HORDE]
            player->ADD_GOSSIP_ITEM(5, "[灰影墓穴]"              , GOSSIP_SENDER_MAIN, 40);
            player->ADD_GOSSIP_ITEM(5, "[试炼谷]"                , GOSSIP_SENDER_MAIN, 41);
            player->ADD_GOSSIP_ITEM(5, "[纳拉其营地]"            , GOSSIP_SENDER_MAIN, 42);
			player->ADD_GOSSIP_ITEM(0, "[返回]"                  , GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 4: // Starting Places [ALLIANCE]
            player->ADD_GOSSIP_ITEM(5, "[北郡山谷]"              , GOSSIP_SENDER_MAIN, 43);
            player->ADD_GOSSIP_ITEM(5, "[寒脊山谷]"              , GOSSIP_SENDER_MAIN, 44);
            player->ADD_GOSSIP_ITEM(5, "[幽影谷]"                , GOSSIP_SENDER_MAIN, 45);
			player->ADD_GOSSIP_ITEM(0, "[返回]"                  , GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 5: // Instances [PAGE 1]
            player->ADD_GOSSIP_ITEM(5, "[哀嚎洞穴]"              , GOSSIP_SENDER_MAIN, 1249);
            player->ADD_GOSSIP_ITEM(5, "[死亡矿井]"              , GOSSIP_SENDER_MAIN, 1250);
            player->ADD_GOSSIP_ITEM(5, "[影牙城堡]"              , GOSSIP_SENDER_MAIN, 1251);
            player->ADD_GOSSIP_ITEM(5, "[黑暗深渊]"              , GOSSIP_SENDER_MAIN, 1252);
            player->ADD_GOSSIP_ITEM(5, "[剃刀沼泽]"              , GOSSIP_SENDER_MAIN, 1254);
            player->ADD_GOSSIP_ITEM(5, "[剃刀高地]"              , GOSSIP_SENDER_MAIN, 1256);
            player->ADD_GOSSIP_ITEM(5, "[血色修道院]"            , GOSSIP_SENDER_MAIN, 1257);
			player->ADD_GOSSIP_ITEM(5, "[奥达曼]"                , GOSSIP_SENDER_MAIN, 1258);
            player->ADD_GOSSIP_ITEM(7, "[下一页]"                , GOSSIP_SENDER_MAIN, 5551);
            player->ADD_GOSSIP_ITEM(0, "[返回]"                  , GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 5551: // Instances [PAGE 2]
            player->ADD_GOSSIP_ITEM(5, "[祖尔法拉克]"            , GOSSIP_SENDER_MAIN, 1259);
            player->ADD_GOSSIP_ITEM(5, "[玛拉顿]"                , GOSSIP_SENDER_MAIN, 1260);
            player->ADD_GOSSIP_ITEM(5, "[阿塔哈卡神庙]"          , GOSSIP_SENDER_MAIN, 1261);
            player->ADD_GOSSIP_ITEM(5, "[黑石深渊]"              , GOSSIP_SENDER_MAIN, 1262);
            player->ADD_GOSSIP_ITEM(5, "[厄运之槌]"              , GOSSIP_SENDER_MAIN, 1263);
            player->ADD_GOSSIP_ITEM(5, "[斯坦索姆]"              , GOSSIP_SENDER_MAIN, 1265);
            player->ADD_GOSSIP_ITEM(5, "[通灵学院]"              , GOSSIP_SENDER_MAIN, 1266);
			player->ADD_GOSSIP_ITEM(5, "[黑石塔]"                , GOSSIP_SENDER_MAIN, 1264);
            player->ADD_GOSSIP_ITEM(7, "[上一页]"                , GOSSIP_SENDER_MAIN, 5);
            player->ADD_GOSSIP_ITEM(0, "[返回]"                  , GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 101: // Raids
            player->ADD_GOSSIP_ITEM(5, "[祖尔格拉布]"            , GOSSIP_SENDER_MAIN, 4000);
            player->ADD_GOSSIP_ITEM(5, "[奥妮克希亚的巢穴]"      , GOSSIP_SENDER_MAIN, 4001);
            player->ADD_GOSSIP_ITEM(5, "[熔火之心]"              , GOSSIP_SENDER_MAIN, 4002);
            player->ADD_GOSSIP_ITEM(5, "[黑翼之巢]"              , GOSSIP_SENDER_MAIN, 4003);
            player->ADD_GOSSIP_ITEM(5, "[安其拉废墟]"            , GOSSIP_SENDER_MAIN, 4004);
            player->ADD_GOSSIP_ITEM(5, "[安其拉神庙]"            , GOSSIP_SENDER_MAIN, 4005);
            player->ADD_GOSSIP_ITEM(5, "[纳克萨玛斯]"            , GOSSIP_SENDER_MAIN, 4006);
			player->ADD_GOSSIP_ITEM(5, "[冰龙巢穴]"              , GOSSIP_SENDER_MAIN, 4007);
            player->ADD_GOSSIP_ITEM(0, "[返回]"                  , GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 6010: // Kalimdor
            player->ADD_GOSSIP_ITEM(5, "[灰谷]"                  , GOSSIP_SENDER_MAIN, 601);
            player->ADD_GOSSIP_ITEM(5, "[黑海岸]"                , GOSSIP_SENDER_MAIN, 602);
            player->ADD_GOSSIP_ITEM(5, "[凄凉之地]"              , GOSSIP_SENDER_MAIN, 603);
            player->ADD_GOSSIP_ITEM(5, "[杜隆塔尔]"              , GOSSIP_SENDER_MAIN, 604);
            player->ADD_GOSSIP_ITEM(5, "[尘泥沼泽]"              , GOSSIP_SENDER_MAIN, 605);
            player->ADD_GOSSIP_ITEM(5, "[菲拉斯]"                , GOSSIP_SENDER_MAIN, 606);
            player->ADD_GOSSIP_ITEM(5, "[希利苏斯]"              , GOSSIP_SENDER_MAIN, 607);
            player->ADD_GOSSIP_ITEM(5, "[石爪山脉]"              , GOSSIP_SENDER_MAIN, 608);
            player->ADD_GOSSIP_ITEM(5, "[塔纳利斯]"              , GOSSIP_SENDER_MAIN, 609);
            player->ADD_GOSSIP_ITEM(5, "[贫瘠之地]"              , GOSSIP_SENDER_MAIN, 610);
            player->ADD_GOSSIP_ITEM(5, "[千针石林]"              , GOSSIP_SENDER_MAIN, 611);
            player->ADD_GOSSIP_ITEM(5, "[冬泉谷]"                , GOSSIP_SENDER_MAIN, 612);
            player->ADD_GOSSIP_ITEM(0, "[返回"                  , GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 6020: // Eastern Kingdoms
            player->ADD_GOSSIP_ITEM(5, "[阿拉希高地]"            , GOSSIP_SENDER_MAIN, 613);
            player->ADD_GOSSIP_ITEM(5, "[荒芜之地]"              , GOSSIP_SENDER_MAIN, 614);
            player->ADD_GOSSIP_ITEM(5, "[丹莫罗]"                , GOSSIP_SENDER_MAIN, 615);
            player->ADD_GOSSIP_ITEM(5, "[暮色森林]"              , GOSSIP_SENDER_MAIN, 616);
            player->ADD_GOSSIP_ITEM(5, "[东瘟疫之地]"            , GOSSIP_SENDER_MAIN, 617);
            player->ADD_GOSSIP_ITEM(5, "[艾尔文森林]"            , GOSSIP_SENDER_MAIN, 618);
            player->ADD_GOSSIP_ITEM(5, "[希尔斯布莱德丘陵]"      , GOSSIP_SENDER_MAIN, 619);
            player->ADD_GOSSIP_ITEM(5, "[赤脊山]"                , GOSSIP_SENDER_MAIN, 620);
            player->ADD_GOSSIP_ITEM(5, "[银松森林]"              , GOSSIP_SENDER_MAIN, 621);
            player->ADD_GOSSIP_ITEM(5, "[荆棘谷]"                , GOSSIP_SENDER_MAIN, 622);
            player->ADD_GOSSIP_ITEM(5, "[悲伤沼泽]"              , GOSSIP_SENDER_MAIN, 623);
            player->ADD_GOSSIP_ITEM(5, "[辛特兰]"                , GOSSIP_SENDER_MAIN, 624);
            player->ADD_GOSSIP_ITEM(5, "[提瑞斯法林地]"          , GOSSIP_SENDER_MAIN, 625);
            player->ADD_GOSSIP_ITEM(5, "[西部荒野]"              , GOSSIP_SENDER_MAIN, 626);
            player->ADD_GOSSIP_ITEM(5, "[湿地]"                  , GOSSIP_SENDER_MAIN, 627);
            player->ADD_GOSSIP_ITEM(0, "[返回]"                  , GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;

			
		case 6030: // 風景傳送
			player->ADD_GOSSIP_ITEM(0, " 海加尔山 ", GOSSIP_SENDER_MAIN, 628);
			player->ADD_GOSSIP_ITEM(0, " 海山龙洞 ", GOSSIP_SENDER_MAIN, 646);
			//player->ADD_GOSSIP_ITEM(0, " 翡翠圣地 ", GOSSIP_SENDER_MAIN, 629);
			//player->ADD_GOSSIP_ITEM(0, " 时光之穴 ", GOSSIP_SENDER_MAIN, 630);
			player->ADD_GOSSIP_ITEM(0, " 黑暗之门 ", GOSSIP_SENDER_MAIN, 631);
			//player->ADD_GOSSIP_ITEM(0, " [双塔山]", GOSSIP_SENDER_MAIN, 632);
			player->ADD_GOSSIP_ITEM(0, " 梦境之树 ", GOSSIP_SENDER_MAIN, 633);
			//player->ADD_GOSSIP_ITEM(0, " [恐怖之岛]", GOSSIP_SENDER_MAIN, 634);
			player->ADD_GOSSIP_ITEM(0, " 暴雪路障 ", GOSSIP_SENDER_MAIN, 635);
			player->ADD_GOSSIP_ITEM(0, " 天涯海滩 ", GOSSIP_SENDER_MAIN, 636);
			player->ADD_GOSSIP_ITEM(0, " 安戈洛环形山 ", GOSSIP_SENDER_MAIN, 637);
			//player->ADD_GOSSIP_ITEM(0, " 比吉尔的飞艇残骸 ", GOSSIP_SENDER_MAIN, 638);
			player->ADD_GOSSIP_ITEM(0, " 石堡瀑布", GOSSIP_SENDER_MAIN, 639);
			player->ADD_GOSSIP_ITEM(0, " 一个很美的地方", GOSSIP_SENDER_MAIN, 640);
			player->ADD_GOSSIP_ITEM(0, " 翡翠森林", GOSSIP_SENDER_MAIN, 641);
			player->ADD_GOSSIP_ITEM(0, " 地铁海底", GOSSIP_SENDER_MAIN, 642);
			player->ADD_GOSSIP_ITEM(0, " 旧铁炉堡", GOSSIP_SENDER_MAIN, 643);
			player->ADD_GOSSIP_ITEM(0, " 巨石水坝", GOSSIP_SENDER_MAIN, 644);
			player->ADD_GOSSIP_ITEM(0, " 迷宫探险", GOSSIP_SENDER_MAIN, 645);
			player->ADD_GOSSIP_ITEM(0, " [返回]", GOSSIP_SENDER_MAIN, 100);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
			
			break;
		//case 6040: //飞行全开
		//	/*for (uint8 i = 0; i < 8; i++)
		//	{
		//		player->SetTaximask(i,0xFFFFFFFF);
		//	}*/
		//	player->SetTaxiCheater(true);
		//	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID()); 
		//	break;

			
		//case 6050:  // 拍賣行
		//	player->SEND_AUCTIONLIST(_Creature->GetGUID(), _Creature);
		//	break;
			
		case 6060://銀行
			player->SEND_BANKERLIST(_Creature->GetGUID());
			break;
// ----### CITIES ###----

// ### HORDE ###

        case 20: // Orgrimmar
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 1437.0f, -4421.0f, 25.24f, 1.65f);
            break;
        case 21: // Undercity
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 1822.0999f, 238.638855f, 60.694809f, 0.0f);
            break;
        case 22: // Thunderbluff
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -1272.703735f, 116.886490f, 131.016861f, 0.0f);
            break;
// ----### CITIES ###----
// ### ALLIANCE ###

        case 23: // Stormwind
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -8828.231445f, 627.927490f, 94.055664f, 0.0f);
            break;
        case 24: // Ironforge
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -4917.0f, -955.0f, 502.0f, 0.0f);
            break;
        case 25: // Darnassus
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 9962.712891f, 2280.142822f, 1341.394409f, 0.0f);
            break;

// ----### 战场 ###----

			// ### HORDE ###

		case 26: // [部落]奧特蘭戰場
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(30, -1237.976318,321.319366, 60.7065730, 0);
			break;
		case 27: // [部落]戰歌峽穀
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(489, 1123.168823, 1462.474976, 315.564148, 3.464511, 0);
			break;
		case 28: // [部落]阿拉希戰場
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(529, 855.156128, 828.636108,57.707348, 2.812707, 0);
			break;

			// ### ALLIANCE ###

		case 29: // [聯盟]奧特蘭戰場
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(30, 606.597351, 24.840078, 42.931183, 0);
			break;
		case 30: // [聯盟]戰歌峽穀
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(489, 1413.284302, 1412.571411, 345.538391, 0);
			break;
		case 31: // [聯盟]阿拉希戰場
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(529, 1169.572266, 1157.919312, 56.533646, 0);
			break;



// ----### STARTING PLACES ####----

// ### HORDE ###
        case 40: // Shadow Grave
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 1663.517f, 1678.187744f, 120.5303f, 0.0f);
            break;
        case 41: // Valley of Trials
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -602.1253f, -4262.4208f, 38.956341f, 0.0f);
            break;
        case 42: // Camp Narache
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -2914.16992f, -266.061798f, 53.658211f, 0.0f);
            break;

// ### ALLIANCE ###

        case 43: // Nortshire Valley
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -8943.133789f, -132.934921f, 83.704269f, 0.0f);
            break;
        case 44: // Coldridge Valley
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -6231.106445f, 332.270477f, 383.153931f, 0.0f);
            break;
        case 45: // Shadowglen
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 10329.918945f, 833.500305f, 1326.260620f, 0.0f);
            break;

// ----### INSTANCES ###----

        case 50: // Dire Maul
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -3762.340820f, 1216.537598f, 127.434608f, 0.0f);
            break;
        case 51: // Blackrock Spire
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -7528.554688f, -1222.907227f, 285.732941f, 0.0f);
            break;
        case 52: // Zul'Gurub
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -11916.179688f, -1190.977051f, 85.137901f, 0.0f);
            break;
        case 53: // Onyxia's Lair
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4682.391602f, -3709.857422f, 46.792862f, 0.0f);
            break;
        case 54: // Searing Gorge (Moltencore, Blackwinglair)
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -7342.270020f, -1096.863892f, 277.06930f, 0.0f);
            break;
        case 55: // Naxxramas
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 3121.061768f, -3689.973389f, 133.458786f, 0.0f);
            break;
        case 56: // Stratholme Backdoor Entrance
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 3160.416992f, -4038.750244f, 104.177376f, 0.0f);
            break;
        case 57: // Stratholme Main Entrance
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 3357.214355f, -3379.713135f, 144.780853f, 0.0f);
            break;
        case 58: // Scholomance
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 1252.319824f, -2587.151123f, 92.886772f, 0.0f);
            break;

// ---### ZONES ###---

        case 70: // Silithus
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -7430.070313f, 1002.554565f, 1.249787f, 0.0f);
            break;
        case 71: // Durotar
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 1006.426819f, -4439.258789f, 11.352882f, 0.0f);
            break;
        case 72: // Ashenvale
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 1922.842651f, -2169.429688f, 94.327400f, 0.0f);
            break;
        case 73: // Tanaris
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -7180.401367f, -3773.328369f, 8.728320f, 0.0f);
            break;
        case 74: // Pretbc Mall
            //player->CLOSE_GOSSIP_MENU();
            //player->TeleportTo(1, 16201.107422f, 16205.1875f, 0.140072f, 1.630427f);
            break;
        case 4015:// Gurubashi
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -13261.3f, 168.294f, 35.0792f, 1.00688f);
            break;
        case 4017:// Razor Hill
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 315.721f, -4743.4f, 10.4867f, 0.0f);
            break;
        case 4018:// Goldshire
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -9464.0f, 62.0f, 56.0f, 0.0f);
            break;
        case 1249://teleport player to the Wailing Caverns
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -722.53f, -2226.30f, 16.94f, 2.71f);
            break;
        case 1250://teleport player to the Deadmines
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -11212.04f, 1658.58f, 25.67f, 1.45f);
            break;
        case 1251://teleport player to Shadowfang Keep
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -254.47f, 1524.68f, 76.89f, 1.56f);
            break;
        case 1252://teleport player to Blackfathom Deeps
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 4254.58f, 664.74f, -29.04f, 1.97f);
            break;
        case 1254://teleport player to Razorfen Kraul
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4484.04f, -1739.40f, 86.47f, 1.23f);
            break;
        case 1256://teleport player to Razorfen Downs
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4645.08f, -2470.85f, 85.53f, 4.39f);
            break;
        case 1257://teleport player to the Scarlet Monastery
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 2843.89f, -693.74f, 139.32f, 5.11f);
            break;
        case 1258://teleport player to Uldaman
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -6119.70f, -2957.30f, 204.11f, 0.03f);
            break;
        case 1259://teleport player to Zul'Farrak
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -6839.39f, -2911.03f, 8.87f, 0.41f);
            break;
        case 1260://teleport player to Maraudon
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -1433.33f, 2955.34f, 96.21f, 4.82f);
            break;
        case 1261://teleport player to the Sunken Temple
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -10346.92f, -3851.90f, -43.41f, 6.09f);
            break;
        case 1262://teleport player to Blackrock Depths
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -7301.03f, -913.19f, 165.37f, 0.08f);
            break;
        case 1263://teleport player to Dire Maul
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -3982.47f, 1127.79f, 161.02f, 0.05f);
            break;
        case 1264://teleport player to Blackrock Spire
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -7535.43f, -1212.04f, 285.45f, 5.29f);
            break;
        case 1265://teleport player to Stratholme
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 3263.54f, -3379.46f, 143.59f, 0.00f);
            break;
        case 1266://teleport player to Scholomance
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 1219.01f, -2604.66f, 85.61f, 0.50f);
            break;
        case 4000:// Teleport to Zul'Gurub
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -11916.7f, -1212.82f, 92.2868f, 4.6095f);
            break;
        case 4001:// Teleport to Onyxia's Lair
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4707.44f, -3726.82f, 54.6723f, 3.8f);
            break;
        case 4002:// Teleport to Molten Core
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(230, 1121.451172f, -454.316772f, -101.329536f, 3.5f);
            break;
        case 4003:// Teleport to Blackwing Lair
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(469, -7665.55f, -1102.49f, 400.679f, 0.0f);
            break;
        case 4004:// Ruins of Ahn'Qiraj
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -8409.032227f, 1498.830933f, 27.361542f, 2.497567f);
            break;
        case 4005:// Temple of Ahn'Qiraj
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -8245.837891f, 1983.736206f, 129.071686f, 0.936195f);
            break;
        case 4006:// Naxxramas
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(533, 3005.87f, -3435.0f, 293.89f, 0.0f);
            break;
        case 4007:// 冰龙巢穴
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(533, 3498.27f, -5349.45f, 144.967f, 0.0f);
            break;
        case 601: // Kalimdor -> Ashenvale
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 3469.43f, 847.62f, 6.36476f, 0.0f);
            break;
        case 602: // Kalimdor -> Darkshore
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 6207.5f, -152.833f, 80.8185f, 0.0f);
            break;
        case 603: // Kalimdor -> Desolace
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -93.1614f, 1691.15f, 90.0649f, 0.0f);
            break;
        case 604: // Kalimdor -> Durotar
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 341.42f, -4684.7f, 31.9493f, 0.0f);
            break;
        case 605: // Kalimdor -> Duswallow Marsh
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -3463.26f, -4123.13f, 18.1043f, 0.0f);
            break;
        case 606: // Kalimdor -> Ferelas
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4458.93f, 243.415f, 65.6136f, 0.0f);
            break;
        case 607: // Kalimdor -> Silithus
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -6824.15f, 821.273f, 50.6675f, 0.0f);
            break;
        case 608: // Kalimdor -> Stonetalon Mountains
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 1145.00f, 85.664f, -6.64f, 0.0f);
            break;
        case 609: // Kalimdor -> Tanaris
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -7373.69f, -2950.2f, 11.7598f, 0.0f);
            break;
        case 610: // Kalimdor -> The Barrens
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -456.263f, -2652.7f, 96.615f, 0.0f);
            break;
        case 611: // Kalimdor -> Thousand Needles
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4941.66f, -1595.42f, -33.07f, 0.0f);
            break;
        case 612: // Kalimdor -> Winterspring
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 6107.62f, -4181.6f, 853.322f, 0.0f);
            break;
        case 613: // Eastern Kingdoms -> Arathi Highlands
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -1544.93f, -2495.01f, 54.11f, 0.0f);
            break;
        case 614: // Eastern Kingdoms -> Badlands
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -6084.95f, -3328.44f, 253.76f, 0.0f);
            break;
        case 615: // Eastern Kingdoms -> Dun Morogh
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -5660.33f, 755.299f, 390.605f, 0.0f);
            break;
        case 616: // Eastern Kingdoms -> Duskwood
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -10879.85f, -327.06f, 37.78f, 0.0f);
            break;
        case 617: // Eastern Kingdoms -> Eastern Plaguelands
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 2280.12f, -5313.16f, 87.74f, 0.0f);
            break;
        case 618: // Eastern Kingdoms -> Elwynn Forest
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -9545.78f, -51.81f, 56.72f, 0.0f);
            break;
        case 619: // Eastern Kingdoms -> Hillsbrad Foothills
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -436.03f, -583.27f, 53.58f, 0.0f);
            break;
        case 620: // Eastern Kingdoms -> Reridge Mountains
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -9633.80f, -1875.09f, 68.39f, 0.0f);
            break;
        case 621: // Eastern Kingdoms -> Silverpine Forest
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 641.48f, 1297.84f, 85.45f, 0.0f);
            break;
        case 622: // Eastern Kingdoms -> Stranglethorn Vale
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -11393.77f, -288.94f, 58.99f, 0.0f);
            break;
        case 623: // Eastern Kingdoms -> Swamp of Sorrows
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -10522.55f, -3028.30f, 21.79f, 0.0f);
            break;
        case 624: // Eastern Kingdoms -> The Hinterlands
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 155.14f, -2014.95f, 122.55f, 0.0f);
            break;
        case 625: // Eastern Kingdoms -> Tirishfal Glades
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 2255.5f, 288.511f, 35.1138f, 0.0f);
            break;
        case 626: // Eastern Kingdoms -> Westfall
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -10919.09f, 998.47f, 35.47f, 0.0f);
            break;
        case 627: // Eastern Kingdoms -> Wetlands
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -4086.36f, -2610.95f, 47.0143f, 0.0f);
            break;

			// 風景傳送
		case 628:
				//海加爾山 統一格式說明：(MapID, X, Y, Z, 0);
				player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(1, 4603.946777,-3879.250977, 944.183472, 1);
				break;
		case 629:
				//翡翠聖地 統一格式說明：(MapID, X, Y, Z, 0);
				player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(1, 3968.264648, -1290.036011, 240.326889, 5.927989);
				break;
		case 630:
				//時光之穴 統一格式說明：(MapID, X, Y, Z, 0);
				player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(1, -8173.930176, -4737.463867, 33.777351, 4.772119);
				break;
		case 631:
				//黑暗之門 統一格式說明：(MapID, X, Y, Z, 0);
				player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(0, -11849.031250, -3201.170654, -28.885090, 3.280838);
				break;
		case 632:
				//雙塔山 統一格式說明：(MapID, X, Y, Z, 0);
				player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(1, -3331.353271, 2225.728271, 30.987701, 6.267522);
				break;
		case 633:
				//夢境之樹 統一格式說明：(MapID, X, Y, Z, 0);
				player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(1, -2914.756104, 1902.199341, 34.741035, 5.690404);
				break;
		case 634:
				//恐怖之島 統一格式說明：(MapID, X, Y, Z, 0);
				player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(1, 4603.946777, -3879.250977, 944.183472, 1);
				break;
		case 635:
				//暴雪建設公司路障 統一格式說明：(MapID, X, Y, Z, 0);
				player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(1, 5478.060059, -3730.850098, 1593.439941, 5.610376);
				break;
		case 636:
				//天涯海灘 統一格式說明：(MapID, X, Y, Z, 0);
				player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(1, -9851.617188, -3608.474121, 8.939731, 2.513388);
				break;
		case 637:
				//安戈洛環形山 統一格式說明：(MapID, X, Y, Z, 0);
				player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(1, -8562.096680, -2106.056641, 8.852538, 0.090425);
				break;
		case 638:
				//比吉爾的飛艇殘骸 統一格式說明：(MapID, X, Y, Z, 0);
				player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(1, -4014.003418, -3768.186523, 42.123295, 5.220697);
				break;
		case 639:
				//石堡瀑布 統一格式說明：(MapID, X, Y, Z, 0);
				player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(0, -9481.493164, -3326.915283, 8.864347, 0.846896);
		case 640:
			//死亡矿井一个很美的地方 統一格式說明：(MapID, X, Y, Z, 0); .go -1749 471 0.85 36
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(36, -1749, 471, 0.85, 0.846896);
				break;
		case 641:
			//翡翠森林 統一格式說明：(MapID, X, Y, Z, 0); .go -1749 471 0.85 36
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(169, 3105.41, 3096.78, 27.0032,  0.846896);
			break;
		case 642:
			//地铁海底 統一格式說明：(MapID, X, Y, Z, 0); .go -1749 471 0.85 36
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(369, -79.3722, 1171.28, -122.208, 0.68);
			break;
		case 643:
			//旧铁炉堡 統一格式說明：(MapID, X, Y, Z, 0); .go -1749 471 0.85 36
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(0, -4819, - 975, 464.7, 0.68);
			break;
		case 644:
			//巨石水坝 統一格式說明：(MapID, X, Y, Z, 0); .go -1749 471 0.85 36
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(0, -4717.5, -3389.22, 322.53, 1.69);
			break;
		case 645:
			//迷宫探险 統一格式說明：(MapID, X, Y, Z, 0); .go -1749 471 0.85 36
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(0, -7398.118164, 795.607544, 131.408005, 1.69);
			break;
		case 646:
			//海山龙洞 統一格式說明：(MapID, X, Y, Z, 0); .go 4814.1 -1736.4 1157.33 1
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(1, 4814.1, -1736.4, 1157.33, 5.31);
			break;
        case 100: // Main Menu
            // HORDE
            if (player->GetTeam() == HORDE)
            {
                //player->ADD_GOSSIP_ITEM(5, "[GM 岛]"                , GOSSIP_SENDER_MAIN, 74);
                player->ADD_GOSSIP_ITEM(7, "[主城传送]"               , GOSSIP_SENDER_MAIN, 1);
                player->ADD_GOSSIP_ITEM(7, "[出生地点]"               , GOSSIP_SENDER_MAIN, 3);
                player->ADD_GOSSIP_ITEM(7, "[副本传送]"               , GOSSIP_SENDER_MAIN, 5);
                player->ADD_GOSSIP_ITEM(7, "[团队副本]"               , GOSSIP_SENDER_MAIN, 101);
                player->ADD_GOSSIP_ITEM(5, "[古拉巴什竞技场]"         , GOSSIP_SENDER_MAIN, 4015);
                player->ADD_GOSSIP_ITEM(7, "[卡利姆多]"               , GOSSIP_SENDER_MAIN, 6010);
                player->ADD_GOSSIP_ITEM(7, "[东部王国]"               , GOSSIP_SENDER_MAIN, 6020);
				player->ADD_GOSSIP_ITEM(7, "[风景传送]", GOSSIP_SENDER_MAIN, 6030);
				//player->ADD_GOSSIP_ITEM(7, "[飞行全开]", GOSSIP_SENDER_MAIN, 6040);
				//player->ADD_GOSSIP_ITEM(7, "[拍卖行]", GOSSIP_SENDER_MAIN, 6050);
				player->ADD_GOSSIP_ITEM(7, "[银行]", GOSSIP_SENDER_MAIN, 6060);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            }
            // ALLIANCE
            else
            {
                //player->ADD_GOSSIP_ITEM(5, "PreTBC Mall"          , GOSSIP_SENDER_MAIN, 74);
                player->ADD_GOSSIP_ITEM(7, "[主城传送]"               , GOSSIP_SENDER_MAIN, 2);
                player->ADD_GOSSIP_ITEM(7, "[出生地点]"               , GOSSIP_SENDER_MAIN, 4);
                player->ADD_GOSSIP_ITEM(7, "[副本传送]"               , GOSSIP_SENDER_MAIN, 5);
                player->ADD_GOSSIP_ITEM(7, "[团队副本]"               , GOSSIP_SENDER_MAIN, 101);
                player->ADD_GOSSIP_ITEM(5, "[古拉巴什竞技场]"         , GOSSIP_SENDER_MAIN, 4015);
                player->ADD_GOSSIP_ITEM(7, "[卡利姆多]"               , GOSSIP_SENDER_MAIN, 6010);
                player->ADD_GOSSIP_ITEM(7, "[东部王国]"               , GOSSIP_SENDER_MAIN, 6020);
				player->ADD_GOSSIP_ITEM(7, "[风景传送]", GOSSIP_SENDER_MAIN, 6030);
				//player->ADD_GOSSIP_ITEM(7, "[飞行全开]", GOSSIP_SENDER_MAIN, 6040);
				//player->ADD_GOSSIP_ITEM(7, "[拍卖行]", GOSSIP_SENDER_MAIN, 6050);
				player->ADD_GOSSIP_ITEM(7, "[银行]", GOSSIP_SENDER_MAIN, 6060);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            }
            break;
    }
}
bool GossipSelect_TeleportNPC(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_TeleportNPC(player, _Creature, action);

    return true;
}

enum Enchants
{
    WEP2H_SUPERIOR_IMPACT = 20,
    WEP2H_AGILITY,
    WEP_CRUSADER,
    WEP1H_AGILITY,
    WEP_SPELLPOWER,
    WEP_HEAL,
    OFFHAND_SPIRIT,
    OFFHAND_STAM,
    OFFHAND_FROSTRES,
    CHEST_STATS,
    CLOAK_DODGE,
    CLOAK_SUB,
    CLOAK_ARMOR,
    CLOAK_AGILITY,
    BRACER_STAM,
    BRACER_STR,
    BRACER_HEAL,
    BRACER_INT,
    GLOVES_AGI,
    GLOVES_FIRE,
    GLOVES_FROST,
    GLOVES_SHADOW,
    GLOVES_HEALING,
    BOOTS_AGI,
    BOOTS_SPEED,
    BOOTS_STAM,
};

void Enchant(Player* player, Item* item, uint32 enchantid)
{
    if (!item)
    {
        player->GetSession()->SendNotification("You must first equip the item you are trying to enchant.");
        return;
    }

    if (!enchantid)
    {
        player->GetSession()->SendNotification("Something went wrong.");
        return;
    }

    item->ClearEnchantment(PERM_ENCHANTMENT_SLOT);
    item->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchantid, 0, 0);
    player->GetSession()->SendNotification("%s succesfully enchanted", item->GetProto()->Name1);
}

bool GossipHello_EnchantNPC(Player* player, Creature* creature)
{

    player->ADD_GOSSIP_ITEM(5, "Chest", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_CHEST);
    player->ADD_GOSSIP_ITEM(5, "Cloak", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_BACK);
    player->ADD_GOSSIP_ITEM(5, "Bracers", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_WRISTS);
    player->ADD_GOSSIP_ITEM(5, "Gloves", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_HANDS);
    player->ADD_GOSSIP_ITEM(5, "Boots", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_FEET);
    player->ADD_GOSSIP_ITEM(5, "Mainhand", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_MAINHAND);
    player->ADD_GOSSIP_ITEM(5, "Offhand", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_OFFHAND);

    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    return true;
}
bool GossipSelect_EnchantNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    if (sender != GOSSIP_SENDER_MAIN)
        return true;

    if (action < 20)
    {
        switch (action)
        {
        case EQUIPMENT_SLOT_CHEST:
            player->ADD_GOSSIP_ITEM(5, "Greater Stats", GOSSIP_SENDER_MAIN, CHEST_STATS);
            break;
        case EQUIPMENT_SLOT_BACK:
            player->ADD_GOSSIP_ITEM(5, "Agility", GOSSIP_SENDER_MAIN, CLOAK_AGILITY);
            player->ADD_GOSSIP_ITEM(5, "Armor", GOSSIP_SENDER_MAIN, CLOAK_ARMOR);
            player->ADD_GOSSIP_ITEM(5, "Dodge", GOSSIP_SENDER_MAIN, CLOAK_DODGE);
            player->ADD_GOSSIP_ITEM(5, "Subtlety", GOSSIP_SENDER_MAIN, CLOAK_SUB);
        break;
        case EQUIPMENT_SLOT_WRISTS:
            player->ADD_GOSSIP_ITEM(5, "Stamina", GOSSIP_SENDER_MAIN, BRACER_STAM);
            player->ADD_GOSSIP_ITEM(5, "Strength", GOSSIP_SENDER_MAIN, BRACER_STR);
            player->ADD_GOSSIP_ITEM(5, "Healing", GOSSIP_SENDER_MAIN, BRACER_HEAL);
            player->ADD_GOSSIP_ITEM(5, "Intellect", GOSSIP_SENDER_MAIN, BRACER_INT);
            break;
        case EQUIPMENT_SLOT_HANDS:
            player->ADD_GOSSIP_ITEM(5, "Agility", GOSSIP_SENDER_MAIN, GLOVES_AGI);
            player->ADD_GOSSIP_ITEM(5, "Fire Power", GOSSIP_SENDER_MAIN, GLOVES_FIRE);
            player->ADD_GOSSIP_ITEM(5, "Frost Power", GOSSIP_SENDER_MAIN, GLOVES_FROST);
            player->ADD_GOSSIP_ITEM(5, "Shadow Power", GOSSIP_SENDER_MAIN, GLOVES_SHADOW);
            player->ADD_GOSSIP_ITEM(5, "Healing", GOSSIP_SENDER_MAIN, GLOVES_HEALING);
            break;
        case EQUIPMENT_SLOT_FEET:
            player->ADD_GOSSIP_ITEM(5, "Stamina", GOSSIP_SENDER_MAIN, BOOTS_STAM);
            player->ADD_GOSSIP_ITEM(5, "Minor Speed", GOSSIP_SENDER_MAIN, BOOTS_SPEED);
            player->ADD_GOSSIP_ITEM(5, "Agility", GOSSIP_SENDER_MAIN, BOOTS_AGI);
            break;
        case EQUIPMENT_SLOT_MAINHAND:
            player->ADD_GOSSIP_ITEM(5, "Crusader", GOSSIP_SENDER_MAIN, WEP_CRUSADER);
            player->ADD_GOSSIP_ITEM(5, "1H Agility", GOSSIP_SENDER_MAIN, WEP1H_AGILITY);
            player->ADD_GOSSIP_ITEM(5, "2H Agility", GOSSIP_SENDER_MAIN, WEP2H_AGILITY);
            player->ADD_GOSSIP_ITEM(5, "Spellpower", GOSSIP_SENDER_MAIN, WEP_SPELLPOWER);
            player->ADD_GOSSIP_ITEM(5, "Healing", GOSSIP_SENDER_MAIN, WEP_HEAL);
            break;
        case EQUIPMENT_SLOT_OFFHAND:
            player->ADD_GOSSIP_ITEM(5, "Spirit", GOSSIP_SENDER_MAIN, OFFHAND_SPIRIT);
            player->ADD_GOSSIP_ITEM(5, "Stamina", GOSSIP_SENDER_MAIN, OFFHAND_STAM);
            player->ADD_GOSSIP_ITEM(5, "Frost Resistance", GOSSIP_SENDER_MAIN, OFFHAND_FROSTRES);
            break;
        }
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    }
    else
    {
        Item* item = nullptr;
        uint32 id = 0;
        switch (action)
        {
            case WEP2H_SUPERIOR_IMPACT:
            case WEP2H_AGILITY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                if (item && (action == WEP2H_AGILITY || action == WEP2H_SUPERIOR_IMPACT))
                {
                    if (item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_AXE2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_MACE2
                        && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_SWORD2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_POLEARM
                        && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_STAFF)
                    {
                        player->GetSession()->SendNotification("Requires 2 handed weapon");
                        player->CLOSE_GOSSIP_MENU();
                        return true;
                    }
                }
                if (action == WEP2H_SUPERIOR_IMPACT)
                    id = 1896;
                else if (action == WEP2H_AGILITY)
                    id = 2646;
                break;

            case WEP_CRUSADER:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 1900;
                break;
            case WEP1H_AGILITY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 2564;
                break;
            case WEP_SPELLPOWER:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 2504;
                break;
            case WEP_HEAL:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 2505;
                break;

            case OFFHAND_SPIRIT:
            case OFFHAND_STAM:
            case OFFHAND_FROSTRES:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                if (item && item->GetProto()->SubClass != ITEM_SUBCLASS_ARMOR_SHIELD)
                {
                    player->GetSession()->SendNotification("Requires Shield");
                    player->CLOSE_GOSSIP_MENU();
                    return true;
                }
                if (action == OFFHAND_SPIRIT)
                    id = 1890;
                else if (action == OFFHAND_FROSTRES)
                    id = 926;
                else if (action == OFFHAND_STAM)
                    id = 929;
                break;
            case CHEST_STATS:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
                id = 1891;
                break;
            case CLOAK_DODGE:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 2622;
                break;
            case CLOAK_SUB:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 2621;
                break;
            case CLOAK_ARMOR:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 1889;
                break;
            case CLOAK_AGILITY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 849;
                break;
            case BRACER_STAM:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 1886;
                break;
            case BRACER_STR:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 1885;
                break;
            case BRACER_HEAL:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 2566;
                break;
            case BRACER_INT:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 1883;
                break;
            case GLOVES_AGI:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2564;
                break;
            case GLOVES_FIRE:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2616;
                break;
            case GLOVES_FROST:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2615;
                break;
            case GLOVES_SHADOW:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2614;
                break;
            case GLOVES_HEALING:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2617;
                break;
            case BOOTS_AGI:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
                id = 904;
                break;
            case BOOTS_SPEED:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
                id = 911;
                break;
            case BOOTS_STAM:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
                id = 929;
                break;
        }
        Enchant(player, item, id);
        player->CLOSE_GOSSIP_MENU();
    }
    return true;
}



void LearnSkillRecipesHelper(Player *player, uint32 skill_id)
{
    uint32 classmask = player->getClassMask();

    for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
    {
        SkillLineAbilityEntry const *skillLine = sSkillLineAbilityStore.LookupEntry(j);
        if (!skillLine)
            continue;

        // wrong skill
        if (skillLine->skillId != skill_id)
            continue;

        // not high rank
        if (skillLine->forward_spellid)
            continue;

        // skip racial skills
        if (skillLine->racemask != 0)
            continue;

        // skip wrong class skills
        if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
            continue;

        SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(skillLine->spellId);
        if (!spellEntry || !SpellMgr::IsSpellValid(spellEntry, player, false))
            continue;

        player->LearnSpell(skillLine->spellId, false);
    }
}
bool LearnAllRecipesInProfession(Player *pPlayer, SkillType skill)
{
    ChatHandler handler(pPlayer->GetSession());
    char* skill_name;

    SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(skill);
    skill_name = SkillInfo->name[sWorld.GetDefaultDbcLocale()];

    if (!SkillInfo)
    {
        sLog.outError("Profession NPC: received non-valid skill ID");
        return false;
    }

    pPlayer->SetSkill(SkillInfo->id, 300, 300);
    LearnSkillRecipesHelper(pPlayer, SkillInfo->id);
    pPlayer->GetSession()->SendNotification("All recipes for %s learned", skill_name);
    return true;
}

bool GossipHello_ProfessionNPC(Player* player, Creature* creature)
{

    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Alchemy",              GOSSIP_SENDER_MAIN, 1);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Blacksmithing",        GOSSIP_SENDER_MAIN, 2);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Leatherworking",       GOSSIP_SENDER_MAIN, 3);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Tailoring",            GOSSIP_SENDER_MAIN, 4);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Engineering",          GOSSIP_SENDER_MAIN, 5);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Enchanting",           GOSSIP_SENDER_MAIN, 6);
    //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Jewelcrafting",      GOSSIP_SENDER_MAIN, 7);
    //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Inscription",        GOSSIP_SENDER_MAIN, 8);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Herbalism",            GOSSIP_SENDER_MAIN, 9);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Skinning",             GOSSIP_SENDER_MAIN, 10);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Mining",               GOSSIP_SENDER_MAIN, 11);

    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "First Aid",            GOSSIP_SENDER_MAIN, 12);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Fishing",              GOSSIP_SENDER_MAIN, 13);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Cooking",              GOSSIP_SENDER_MAIN, 14);

    player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());

    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    return true;
}
void CompleteLearnProfession(Player *pPlayer, Creature *pCreature, SkillType skill)
{
    if (pPlayer->GetFreePrimaryProfessionPoints() == 0 && !(skill == SKILL_COOKING || skill == SKILL_FIRST_AID))
    {
        pPlayer->GetSession()->SendNotification("You already know two primary professions.");
    }
    else
    {
        if (!LearnAllRecipesInProfession(pPlayer, skill))
            pPlayer->GetSession()->SendNotification("Internal error.");
    }
}
bool GossipSelect_ProfessionNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    switch (action)
    {
    case 1:
        if (!player->HasSkill(SKILL_ALCHEMY))
            CompleteLearnProfession(player, creature, SKILL_ALCHEMY);
        break;
    case 2:
        if (!player->HasSkill(SKILL_BLACKSMITHING))
            CompleteLearnProfession(player, creature, SKILL_BLACKSMITHING);
        break;
    case 3:
        if (!player->HasSkill(SKILL_LEATHERWORKING))
            CompleteLearnProfession(player, creature, SKILL_LEATHERWORKING);
        break;
    case 4:
        if (!player->HasSkill(SKILL_TAILORING))
            CompleteLearnProfession(player, creature, SKILL_TAILORING);
        break;
    case 5:
        if (!player->HasSkill(SKILL_ENGINEERING))
            CompleteLearnProfession(player, creature, SKILL_ENGINEERING);
        break;
    case 6:
        if (!player->HasSkill(SKILL_ENCHANTING))
            CompleteLearnProfession(player, creature, SKILL_ENCHANTING);
        break;
    case 7:
    case 8:
        break;
    case 9:
        if (!player->HasSkill(SKILL_HERBALISM))
            CompleteLearnProfession(player, creature, SKILL_HERBALISM);
        break;
    case 10:
        if (!player->HasSkill(SKILL_SKINNING))
            CompleteLearnProfession(player, creature, SKILL_SKINNING);
        break;
    case 11:
        if (!player->HasSkill(SKILL_MINING))
            CompleteLearnProfession(player, creature, SKILL_MINING);
        break;
    case 12:
        if (!player->HasSkill(SKILL_FIRST_AID))
            CompleteLearnProfession(player, creature, SKILL_FIRST_AID);
        break;
    case 13:
        if (!player->HasSkill(SKILL_FISHING))
            CompleteLearnProfession(player, creature, SKILL_FISHING);
        break;
    case 14:
        if (!player->HasSkill(SKILL_COOKING))
            CompleteLearnProfession(player, creature, SKILL_COOKING);
        break;
    }

    player->CLOSE_GOSSIP_MENU();
    return true;
}






//transmog


std::map<uint64, std::map<uint32, Item*> > Items; // Items[GUID][DISPLAY] = item

char * GetSlotName(uint8 slot)
{
	switch (slot)
	{
	case EQUIPMENT_SLOT_HEAD: return "头部";
	case EQUIPMENT_SLOT_SHOULDERS: return "肩部";
	case EQUIPMENT_SLOT_BODY: return "衬衣";
	case EQUIPMENT_SLOT_CHEST: return "胸甲";
	case EQUIPMENT_SLOT_WAIST: return "腰带";
	case EQUIPMENT_SLOT_LEGS: return "腿部";
	case EQUIPMENT_SLOT_FEET: return "靴子";
	case EQUIPMENT_SLOT_WRISTS: return "手腕";
	case EQUIPMENT_SLOT_HANDS: return "双手";
	case EQUIPMENT_SLOT_BACK: return "背部";
	case EQUIPMENT_SLOT_MAINHAND: return "主手";
	case EQUIPMENT_SLOT_OFFHAND: return "副手";
	case EQUIPMENT_SLOT_RANGED: return "远程";
	case EQUIPMENT_SLOT_TABARD: return "徽章";
	default: return NULL;
	}
}
typedef std::unordered_map<ObjectGuid, uint32> TransmogMapType;
TransmogMapType transmogMap; // transmogMap[iGUID] = entry
void UpdateItem(Player* player, Item* item)
{
	sLog.outError("custom.transmog", "TransmogDisplayVendorMgr::UpdateItem");

	if (item->IsEquipped())
	{
		player->SetVisibleItemSlot(item->GetSlot(), item);
		if (player->IsInWorld())
			item->SendUpdateToPlayer(player);
	}
}
void SetFakeEntry(Player* player, Item* item, uint32 entry)
{
	sLog.outError("custom.transmog", "TransmogDisplayVendorMgr::SetFakeEntry");

	transmogMap[item->GetGUID()] = entry;
	UpdateItem(player, item);
}


bool IsSuitable(Item* pItem, Item* OLD, Player* pPlayer)
{
	if (pPlayer->CanUseItem(pItem, false) == EQUIP_ERR_OK)
	{

		ItemPrototype const *pProto = ObjectMgr::GetItemPrototype(pItem->GetEntry());
		ItemPrototype const *oldProto = ObjectMgr::GetItemPrototype(OLD->GetEntry());
		uint32 Quality = pProto->Quality;
		if (Quality == ITEM_QUALITY_UNCOMMON || Quality == ITEM_QUALITY_RARE || Quality == ITEM_QUALITY_EPIC)
		{
			uint32 NClass = pProto->Class;
			uint32 OClass = oldProto->Class;
			uint32 NSubClass = pProto->SubClass;
			uint32 OSubClass = oldProto->SubClass;
			if (NClass == OClass) // not possibly the best structure here, but atleast I got my head around this
				if (NClass == ITEM_CLASS_WEAPON)
				{
					if (NSubClass == OSubClass || ((NSubClass == ITEM_SUBCLASS_WEAPON_BOW || NSubClass == ITEM_SUBCLASS_WEAPON_GUN || NSubClass == ITEM_SUBCLASS_WEAPON_CROSSBOW) && (OSubClass == ITEM_SUBCLASS_WEAPON_BOW || OSubClass == ITEM_SUBCLASS_WEAPON_GUN || OSubClass == ITEM_SUBCLASS_WEAPON_CROSSBOW)))
					{
						return true;
					}
				}
				else if (NClass == ITEM_CLASS_ARMOR)
					if (NSubClass == OSubClass && pProto->InventoryType == oldProto->InventoryType)
					{
						return true;
					}
		}
	}
	return false;
}
std::string AreYouSure(uint8 slot, Item* pItem)
{
	ItemPrototype const *pProto = ObjectMgr::GetItemPrototype(pItem->GetEntry());
	std::string msg = "Transmogrify ";
	msg += GetSlotName(slot);
	msg += "\nTo ";
	msg += pProto->Name1;
	return msg;
}
bool GossipHello_TransmogNPC(Player* player, Creature* creature)
{

	player->PlayerTalkClass->ClearMenus();
	for (uint8 Slot = EQUIPMENT_SLOT_START; Slot < EQUIPMENT_SLOT_END; Slot++) {
		
		

		if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, Slot))
		{
			ItemPrototype const *pProto = ObjectMgr::GetItemPrototype(pItem->GetEntry());
			uint32 Quality = pProto->Quality;
			//if (Quality == ITEM_QUALITY_UNCOMMON || Quality == ITEM_QUALITY_RARE || Quality == ITEM_QUALITY_EPIC) {
				if (char* SlotName = GetSlotName(Slot))
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, SlotName, EQUIPMENT_SLOT_END, Slot);
			//}
					
		}
	
	}

	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "退出..", EQUIPMENT_SLOT_END + 2, 0);
	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
	return true;



}

bool GossipSelect_TransmogNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
	player->PlayerTalkClass->ClearMenus();
	if (sender == EQUIPMENT_SLOT_END)
	{
		
		
		if (Item* OLD = player->GetItemByPos(INVENTORY_SLOT_BAG_0, action))
		{
			ItemPrototype const *oldProto = ObjectMgr::GetItemPrototype(OLD->GetEntry());
			uint64 GUID = player->GetGUID();
			Items[GUID].clear();
			for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++)
				
				if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i)) {
					ItemPrototype const *newProto = ObjectMgr::GetItemPrototype(pItem->GetEntry());
					if (IsSuitable(pItem, OLD, player))
						if (Items[GUID].find(newProto->DisplayInfoID) == Items[GUID].end())
							Items[GUID][newProto->DisplayInfoID] = pItem, player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, newProto->Name1, action, newProto->DisplayInfoID, AreYouSure(action, pItem), 0);
				}
			for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
				if (Bag* pBag = (Bag*)player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
					for (uint32 j = 0; j < pBag->GetBagSize(); j++)
						if (Item* pItem = player->GetItemByPos(i, j)) {
							ItemPrototype const *newProto = ObjectMgr::GetItemPrototype(pItem->GetEntry());
							if (IsSuitable(pItem, OLD, player))
								if (Items[GUID].find(newProto->DisplayInfoID) == Items[GUID].end())
									Items[GUID][newProto->DisplayInfoID] = pItem, player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, newProto->Name1, action, newProto->DisplayInfoID, AreYouSure(action, pItem), 0);
						}

			if (Items[GUID].empty())
			{
				player->GetSession()->SendNotification("no suitable item in bag");
				GossipHello_TransmogNPC(player, creature);
				return true;
			}
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Back..", EQUIPMENT_SLOT_END + 1, 0);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
		}
		else
			GossipHello_TransmogNPC(player, creature);
	}
	else if (sender == EQUIPMENT_SLOT_END + 1)
		GossipHello_TransmogNPC(player, creature);
	else if (sender == EQUIPMENT_SLOT_END + 2)
		player->CLOSE_GOSSIP_MENU();
	else
	{
		uint64 GUID = player->GetGUID();
		Item* OLD = player->GetItemByPos(INVENTORY_SLOT_BAG_0, sender);
		if (!OLD || Items[GUID].find(action) == Items[GUID].end() || !IsSuitable(Items[GUID][action], OLD, player))
		{
			player->GetSession()->SendNotification("no suitable item in slot");
			return true;
		}
		else
		{
			Item* pItem = Items[GUID][action];
			player->SetVisibleItemSlot(OLD->GetSlot(), pItem);
			if (player->IsInWorld())
				pItem->SendUpdateToPlayer(player);
			//SetFakeEntry(player, OLD, Items[GUID][action]->GetEntry());
			
			player->GetSession()->SendAreaTriggerMessage("%s 幻化成功", GetSlotName(sender));

		}
		Items[GUID].clear();
		GossipHello_TransmogNPC(player, creature);
	}
	return true;
}

////TOOL NPC
//bool GossipHello_DemoNPC(Player* player, Creature* creature)
//{
//
//	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "状态恢复", GOSSIP_SENDER_MAIN, 1);
//	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "[重置副本]", GOSSIP_SENDER_MAIN, 2);
//	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "[重置冷却]", GOSSIP_SENDER_MAIN, 3);
//	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Reset Combat", GOSSIP_SENDER_MAIN, 4);
//	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "[取消虚弱复活]", GOSSIP_SENDER_MAIN, 5);
//	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "[维修物品]", GOSSIP_SENDER_MAIN, 6);
//	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "[其它]", GOSSIP_SENDER_MAIN, 7);
//	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "退出", GOSSIP_SENDER_MAIN, 8);
//	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//	return true;
//}
//
//bool GossipSelect_DemoNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
//{
//	player->PlayerTalkClass->ClearMenus();
//	switch (action)
//	{
//	case 1: // Restore HP and MP
//		if (player->isInCombat())
//		{
//			//creature->MonsterWhisper("You're in combat!", player->GetGUID(), false);
//			player->CLOSE_GOSSIP_MENU();
//			return false;
//		}
//		else if (player->getPowerType() == POWER_MANA)
//			player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
//
//		player->SetHealth(player->GetMaxHealth());
//		player->CLOSE_GOSSIP_MENU();
//		break;
//	//case 2: // Reset Instances
//	//	for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
//	//	{
//	//		Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
//	//		for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
//	//		{
//	//			player->UnbindInstance(itr, Difficulty(i));
//	//		}
//	//	}
//	//	player->CLOSE_GOSSIP_MENU();
//	//	break;
//	//case 3: // Reset Cooldowns
//	//	if (player->isInCombat())
//	//	{
//	//		creature->MonsterWhisper("You're in combat!", player->GetGUID(), false);
//	//		player->CLOSE_GOSSIP_MENU();
//	//		return false;
//	//	}
//
//	//	player->RemoveAllSpellCooldown();
//	//	player->CLOSE_GOSSIP_MENU();
//	//	break;
//	case 4: // Reset Combat
//		player->CombatStop();
//		player->CLOSE_GOSSIP_MENU();
//		break;
//	case 5: // Remove Sickness
//		
//		if (player->HasAura(15007)) {
//			if (Aura* aura = player->GetAura(15007, EFFECT_INDEX_0))
//				player->RemoveAura(aura);
//		}
//		player->CLOSE_GOSSIP_MENU();
//		break;
//	case 6: // Repair Items
//		player->DurabilityRepairAll(false, 0);
//		player->CLOSE_GOSSIP_MENU();
//		break;
//	case 7: // Others
//		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "重置天赋", GOSSIP_SENDER_MAIN, 71);
//		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "重置技能", GOSSIP_SENDER_MAIN, 72);
//		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "...返回", GOSSIP_SENDER_MAIN, 73);
//		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//		break;
//	case 8:
//		player->CLOSE_GOSSIP_MENU();
//		break;
//	case 71: // Reset Talents
//		player->resetTalents(true);
//		/*player->SendTalentsInfoData(false);*/
//		player->CLOSE_GOSSIP_MENU();
//		break;
//	case 72: // Reset Spells
//		player->resetSpells();
//		player->CLOSE_GOSSIP_MENU();
//		break;
//	case 73: // ...Back
//		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "状态恢复", GOSSIP_SENDER_MAIN, 1);
//		//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "[重置副本]", GOSSIP_SENDER_MAIN, 2);
//		//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "[重置冷却]", GOSSIP_SENDER_MAIN, 3);
//		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Reset Combat", GOSSIP_SENDER_MAIN, 4);
//		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "[取消虚弱复活]", GOSSIP_SENDER_MAIN, 5);
//		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "[维修物品]", GOSSIP_SENDER_MAIN, 6);
//		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "[其它]", GOSSIP_SENDER_MAIN, 7);
//		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "退出", GOSSIP_SENDER_MAIN, 8);
//		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//		break;
//	}
//	return true;
//}



//NPC DEMO
bool GossipHello_DemoNPC(Player* player, Creature* creature)
{


	return true;



}

bool GossipSelect_DemoNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
	
	return true;
}






/*
* Custom training dummy script
*/

struct npc_training_dummyAI : ScriptedAI
{
    explicit npc_training_dummyAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        npc_training_dummyAI::Reset();
    }

    uint32 m_uiCombatTimer;
    std::unordered_map<Unit*, time_t> attackers;

    void Reset() override
    {
        m_uiCombatTimer = 15000;
        attackers.clear();
    }

    void AttackStart(Unit* /*pWho*/) override {}

    void Aggro(Unit* pWho) override
    {
        SetCombatMovement(false);
    }

    void AddAttackerToList(Unit* pWho)
    {
        auto itr = attackers.find(pWho);
        if (itr != attackers.end())
        {
            itr->second = std::time(nullptr);
        }
        else
        {
            attackers.emplace(pWho, std::time(nullptr));
        }
    }

    void DamageTaken(Unit* pWho, uint32& /*uiDamage*/) override
    {
        if (pWho)
            AddAttackerToList(pWho);
    }

    void SpellHit(Unit* pWho, const SpellEntry* /*pSpell*/) override
    {
        if (pWho)
            AddAttackerToList(pWho);
    }

    void UpdateAI(const uint32 diff) override
    {
        if (m_creature->isInCombat())
        {
            if (m_uiCombatTimer <= diff)
            {
                for (auto itr = attackers.begin(); itr != attackers.end();)
                {
                    if (!itr->first || !itr->first->IsInWorld())
                    {
                        itr = attackers.erase(itr);
                        continue;
                    }
                    if (itr->second + 10 < std::time(nullptr))
                    {
                        m_creature->_removeAttacker(itr->first);
                        m_creature->getThreatManager().modifyThreatPercent(itr->first, -101.0f);
                        itr = attackers.erase(itr);
                        continue;
                    }
                    ++itr;
                }

                if (m_creature->getThreatManager().isThreatListEmpty())
                    EnterEvadeMode();

                m_uiCombatTimer = 15000;
            }
            else
                m_uiCombatTimer -= diff;
        }
    }
};

CreatureAI* GetAI_npc_training_dummy(Creature* pCreature)
{
    return new npc_training_dummyAI(pCreature);
}

struct npc_summon_debugAI : ScriptedAI
{
    uint32 m_maxSummonCount = 200;
    uint32 m_summonCount = 0;
    Creature *m_summons[200];

    npc_summon_debugAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_summonCount = 0;
        for (uint32 i = 0; i < m_maxSummonCount; ++i)
            m_summons[i] = nullptr;

        Reset();
    }

    void Reset() override
    {
        m_summonCount = 0;
        for (uint32 i = 0; i < m_maxSummonCount; ++i)
        {
            if (m_summons[i])
                ((TemporarySummon*)m_summons[i])->UnSummon();

            m_summons[i] = nullptr;
        }
    }


    void JustDied(Unit* /* killer */) override
    {
        Reset();
    }

    void UpdateAI(const uint32 diff) override
    {
        if (!m_creature->getVictim())
            return;

        if (m_summonCount >= m_maxSummonCount)
            return;

        m_summons[m_summonCount++] = m_creature->SummonCreature(12458, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0);
    }
};

CreatureAI* GetAI_custom_summon_debug(Creature *creature)
{
    return new npc_summon_debugAI(creature);
}

void AddSC_custom_creatures()
{
    Script *newscript;

	newscript = new Script;
	newscript->Name = "custom_transmog_npc";
	newscript->pGossipHello = &GossipHello_TransmogNPC;
	newscript->pGossipSelect = &GossipSelect_TransmogNPC;
	newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_teleport_npc";
    newscript->pGossipHello = &GossipHello_TeleportNPC;
    newscript->pGossipSelect = &GossipSelect_TeleportNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_enchant_npc";
    newscript->pGossipHello = &GossipHello_EnchantNPC;
    newscript->pGossipSelect = &GossipSelect_EnchantNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_professions_npc";
    newscript->pGossipHello = &GossipHello_ProfessionNPC;
    newscript->pGossipSelect = &GossipSelect_ProfessionNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_npc_training_dummy";
    newscript->GetAI = &GetAI_npc_training_dummy;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_npc_summon_debugAI";
    newscript->GetAI = &GetAI_custom_summon_debug;
    newscript->RegisterSelf(false);
}
