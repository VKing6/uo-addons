class RscStandardDisplay;
class RscVignette;
class RscControlsGroupNoScrollbars;
class RscText;
class RscFrame;
class RscTitle;
class RscActiveText;
class RscListBox;
class RscControlsGroup;

class RscButtonMenu;
class RscButtonMenuSteam;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class ScrollBar;

class UO_RscControlsGroup {
	type = 15;
	idc = -1;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	shadow = 0;
	style = 16;
	class VScrollbar: ScrollBar
	{
		width = 0.021;
		autoScrollEnabled = 1;
	};
	class HScrollbar: ScrollBar
	{
		height = 0.028;
	};
	class Controls{};
};

class UO_RscListBox : RscListBox {
	idc = 0;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	
	sizeEx = 0.025;
	
	colorText[] = {1,1,1,1.0};
	colorDisabled[] = {1,1,1,0.25};
	
	colorSelect[] = {1,1,1,1.0};
	colorSelect2[] = {1,1,1,1.0};
	
	colorBackground[] = {0,0,0,0};
	colorSelectBackground[] = {0,0,0,0};
	colorSelectBackground2[] = {0,0,0,0};
	
	onLBSelChanged = QUOTE(_this call FUNC(onSlottingLBSelectionChanged));
	onMouseButtonClick = QUOTE(_this call FUNC(onSlottingMouseButtonClick));
};

class UO_ZeusSlottingSelectionDisplay : RscStandardDisplay {
	idd = 31337;
	
	onLoad = QUOTE(_this call FUNC(onLoadSlotSelectionDialog));
	onUnload = QUOTE(_this call FUNC(onUnloadSlotSelectionDialog));
	
	west = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_bluefor_ca.paa";
	east = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_ca.paa";
	guer = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_ca.paa";
	civl = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_ca.paa";
	none = "#(argb,8,8,3)color(0,0,0,0)";
	westUnlocked = "A3\ui_f\data\map\diary\icons\playerWest_ca.paa";
	westLocked = "A3\ui_f\data\map\diary\icons\playerBriefWest_ca.paa";
	eastUnlocked = "A3\ui_f\data\map\diary\icons\playerEast_ca.paa";
	eastLocked = "A3\ui_f\data\map\diary\icons\playerBriefEast_ca.paa";
	guerUnlocked = "A3\ui_f\data\map\diary\icons\playerGuer_ca.paa";
	guerLocked = "A3\ui_f\data\map\diary\icons\playerBriefGuer_ca.paa";
	civlUnlocked = "A3\ui_f\data\map\diary\icons\playerCiv_ca.paa";
	civlLocked = "A3\ui_f\data\map\diary\icons\playerBriefCiv_ca.paa";
	virtUnlocked = "A3\ui_f\data\map\diary\icons\playerVirtual_ca.paa";
	virtLocked = "A3\ui_f\data\map\diary\icons\playerBriefVirtual_ca.paa";
	disabledAllAI = "$STR_DISP_MULTI_ENABLE_AI";
	enabledAllAI = "$STR_DISP_MULTI_DISABLE_AI";
	hostLocked = "$STR_DISP_MULTI_UNLOCK";
	hostUnlocked = "$STR_DISP_MULTI_LOCK";
	colorNotAssigned[] = {1,1,1,0.25};
	colorAssigned[] = {1,1,1,1};
	colorConfirmed[] = {0,1,0,1};
	class controlsbackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class RscTitleBackground: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "SafezoneW - (2 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class MainBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1081;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "SafezoneW - (2 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "SafezoneH - (4.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class MissionSettingsBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1082;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(29.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "3.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class NumOfPlayersBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1083;
			x = "31.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "7.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class SideBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1084;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "(10.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		class RolesBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1085;
			x = "4.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "(10.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		class ChatBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1086;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "17.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "(18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "(5.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))+ 0.3*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		class PlayersPoolBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1087;
			x = "safezoneX + (19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "SafezoneH - (9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
	};
	class controls
	{
		delete B_Civilian;
		delete B_Guerrila;
		delete B_East;
		delete B_West;
		delete B_Side;
		delete B_OK;
		delete B_Cancel;
		delete B_Kick;
		delete B_EnableAll;
		delete B_Lock;
		delete TextDescription;
		delete ValueDescription;
		delete TextMessage;
		delete ValueRoles;
		delete TextParam1;
		delete TextParam2;
		delete ValueParam1;
		delete ValueParam2;
		delete ValuePool;
		delete B_Params;
		delete TextPool;
		delete TextRoles;
		class Title: RscTitle
		{
			w = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1000;
			text = "$STR_A3_RscDisplayMultiplayerSetup_Title";
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class PlayersName: RscTitle
		{
			idc = 701;
			style = 1;
			shadow = 0;
			x = "(SafezoneX) + (24 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			w = "(15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ValueMission: RscTitle
		{
			idc = 101;
			style = 0;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(25.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			x = "5.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_TextDescription: RscText
		{
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1004;
			text = "$STR_DISP_SRVSETUP_DESC";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_ValueDescription: RscText
		{
			idc = 103;
			style = "0x10 + 0x200";
			linespacing = 1;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(25.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			x = "5.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TextIsland: RscText
		{
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1006;
			text = "$STR_DISP_SRVSETUP_ISLAND";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ValueIsland: RscText
		{
			idc = 102;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(25.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			x = "5.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TextSide: RscText
		{
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1008;
			text = "$STR_DISP_MPSETUP_SIDE";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,1};
		};
		class CA_B_West: RscActiveText
		{
			picture = "\A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_bluefor_empty_ca.paa";
			text = "$STR_WEST";
			idc = 104;
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_bluefor_ca.paa";
			sideDisabled = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_none_ca.paa";
			pictureHeight = 1;
			pictureWidth = 1;
			color[] = {"(profilenamespace getvariable ['Map_BLUFOR_R',0])","(profilenamespace getvariable ['Map_BLUFOR_G',1])","(profilenamespace getvariable ['Map_BLUFOR_B',1])",0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_BLUFOR_R',0])","(profilenamespace getvariable ['Map_BLUFOR_G',1])","(profilenamespace getvariable ['Map_BLUFOR_B',1])",1};
			colorDisabled[] = {1,1,1,0};
			colorShade[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			textHeight = 0.38;
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_B_East: CA_B_West
		{
			text = "$STR_EAST";
			idc = 105;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_ca.paa";
			color[] = {"(profilenamespace getvariable ['Map_OPFOR_R',0])","(profilenamespace getvariable ['Map_OPFOR_G',1])","(profilenamespace getvariable ['Map_OPFOR_B',1])",0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_OPFOR_R',0])","(profilenamespace getvariable ['Map_OPFOR_G',1])","(profilenamespace getvariable ['Map_OPFOR_B',1])",1};
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "8.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_B_Guerrila: CA_B_West
		{
			text = "$STR_GUERRILA";
			idc = 106;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_ca.paa";
			color[] = {"(profilenamespace getvariable ['Map_Independent_R',0])","(profilenamespace getvariable ['Map_Independent_G',1])","(profilenamespace getvariable ['Map_Independent_B',1])",0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_Independent_R',0])","(profilenamespace getvariable ['Map_Independent_G',1])","(profilenamespace getvariable ['Map_Independent_B',1])",1};
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "10.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_B_Civilian: CA_B_West
		{
			text = "$STR_CIVILIAN";
			idc = 107;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_ca.paa";
			color[] = {"(profilenamespace getvariable ['Map_Civilian_R',0])","(profilenamespace getvariable ['Map_Civilian_G',1])","(profilenamespace getvariable ['Map_Civilian_B',1])",0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_Civilian_R',0])","(profilenamespace getvariable ['Map_Civilian_G',1])","(profilenamespace getvariable ['Map_Civilian_B',1])",1};
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "12.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_B_Virtual: CA_B_West
		{
			text = "$STR_A3_CFGFACTIONCLASSES_VIRTUAL_F";
			idc = 132;
			show = 0;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_virtual_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_virtual_ca.paa";
			color[] = {1,1,1,0.75};
			colorActive[] = {1,1,1,1};
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "13.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class UO_ValueRoles : UO_RscControlsGroup
		{
			idc = 666;
			rowHeight = "1.75 * 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			x = "4.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "(14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "(9.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
		};
		
		class CA_ValuePool: RscListBox
		{
			idc = 114;
			canDrag = 1;
			rows = 25;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "safezoneX + (19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			w = "(19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "SafezoneH - (9.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorSelectBackground[] = {1,1,1,0.3};
			colorSelectBackground2[] = {1,1,1,0.3};
			colorPictureSelected[] = {1,1,1,1};
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
		};
		class CA_B_Lock: RscButtonMenu
		{
			idc = 118;
			x = "safezoneX + SafezoneW - (13.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_B_Params: RscButtonMenu
		{
			idc = 128;
			shortcuts[] = {"0x00050000 + 2"};
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "(25.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			text = "$STR_DISP_XBOX_EDITOR_WIZARD_PARAMS";
			y = "4.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_B_Kick: RscButtonMenu
		{
			idc = 116;
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "safezoneX + SafezoneW - (7.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = "$STR_DISP_MP_KICKOFF";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_ButtonContinue: RscButtonMenuOK
		{
			x = "safezoneX + SafezoneW - (7.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_ButtonCancel: RscButtonMenuCancel
		{
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = "$STR_DISP_BACK";
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};

class UO_VANILLA : RscStandardDisplay
{
	idd = -1;
	
	onLoad = QUOTE(_this call FUNC(onLoadSlotSelectionDialog));
	onUnload = QUOTE(_this call FUNC(onUnloadSlotSelectionDialog));
	
	west = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_bluefor_ca.paa";
	east = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_ca.paa";
	guer = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_ca.paa";
	civl = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_ca.paa";
	none = "#(argb,8,8,3)color(0,0,0,0)";
	westUnlocked = "A3\ui_f\data\map\diary\icons\playerWest_ca.paa";
	westLocked = "A3\ui_f\data\map\diary\icons\playerBriefWest_ca.paa";
	eastUnlocked = "A3\ui_f\data\map\diary\icons\playerEast_ca.paa";
	eastLocked = "A3\ui_f\data\map\diary\icons\playerBriefEast_ca.paa";
	guerUnlocked = "A3\ui_f\data\map\diary\icons\playerGuer_ca.paa";
	guerLocked = "A3\ui_f\data\map\diary\icons\playerBriefGuer_ca.paa";
	civlUnlocked = "A3\ui_f\data\map\diary\icons\playerCiv_ca.paa";
	civlLocked = "A3\ui_f\data\map\diary\icons\playerBriefCiv_ca.paa";
	virtUnlocked = "A3\ui_f\data\map\diary\icons\playerVirtual_ca.paa";
	virtLocked = "A3\ui_f\data\map\diary\icons\playerBriefVirtual_ca.paa";
	disabledAllAI = "$STR_DISP_MULTI_ENABLE_AI";
	enabledAllAI = "$STR_DISP_MULTI_DISABLE_AI";
	hostLocked = "$STR_DISP_MULTI_UNLOCK";
	hostUnlocked = "$STR_DISP_MULTI_LOCK";
	colorNotAssigned[] = {1,1,1,0.25};
	colorAssigned[] = {1,1,1,1};
	colorConfirmed[] = {0,1,0,1};
	class controlsbackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class RscTitleBackground: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "SafezoneW - (2 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class MainBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1081;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "SafezoneW - (2 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "SafezoneH - (4.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class MissionSettingsBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1082;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(29.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "3.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class NumOfPlayersBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1083;
			x = "31.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "7.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class SideBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1084;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "(10.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		class RolesBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1085;
			x = "4.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "(10.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		class ChatBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1086;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "17.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "(18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "(5.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))+ 0.3*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		class PlayersPoolBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1087;
			x = "safezoneX + (19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "SafezoneH - (9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
	};
	class controls
	{
		delete B_Civilian;
		delete B_Guerrila;
		delete B_East;
		delete B_West;
		delete B_Side;
		delete B_OK;
		delete B_Cancel;
		delete B_Kick;
		delete B_EnableAll;
		delete B_Lock;
		delete TextDescription;
		delete ValueDescription;
		delete TextMessage;
		delete ValueRoles;
		delete TextParam1;
		delete TextParam2;
		delete ValueParam1;
		delete ValueParam2;
		delete ValuePool;
		delete B_Params;
		delete TextPool;
		delete TextRoles;
		class Title: RscTitle
		{
			w = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1000;
			text = "$STR_A3_RscDisplayMultiplayerSetup_Title";
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class PlayersName: RscTitle
		{
			idc = 701;
			style = 1;
			shadow = 0;
			x = "(SafezoneX) + (24 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			w = "(15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_TextVotingTimeLeft: RscTitle
		{
			idc = 121;
			style = 0;
			x = "17 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ValueMission: RscTitle
		{
			idc = 101;
			style = 0;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(25.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			x = "5.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_TextDescription: RscText
		{
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1004;
			text = "$STR_DISP_SRVSETUP_DESC";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_ValueDescription: RscText
		{
			idc = 103;
			style = "0x10 + 0x200";
			linespacing = 1;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(25.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			x = "5.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TextIsland: RscText
		{
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1006;
			text = "$STR_DISP_SRVSETUP_ISLAND";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ValueIsland: RscText
		{
			idc = 102;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(25.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			x = "5.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TextSide: RscText
		{
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1008;
			text = "$STR_DISP_MPSETUP_SIDE";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,1};
		};
		class CA_B_West: RscActiveText
		{
			picture = "\A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_bluefor_empty_ca.paa";
			text = "$STR_WEST";
			idc = 104;
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_bluefor_ca.paa";
			sideDisabled = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_none_ca.paa";
			pictureHeight = 1;
			pictureWidth = 1;
			color[] = {"(profilenamespace getvariable ['Map_BLUFOR_R',0])","(profilenamespace getvariable ['Map_BLUFOR_G',1])","(profilenamespace getvariable ['Map_BLUFOR_B',1])",0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_BLUFOR_R',0])","(profilenamespace getvariable ['Map_BLUFOR_G',1])","(profilenamespace getvariable ['Map_BLUFOR_B',1])",1};
			colorDisabled[] = {1,1,1,0};
			colorShade[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			textHeight = 0.38;
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_B_East: CA_B_West
		{
			text = "$STR_EAST";
			idc = 105;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_ca.paa";
			color[] = {"(profilenamespace getvariable ['Map_OPFOR_R',0])","(profilenamespace getvariable ['Map_OPFOR_G',1])","(profilenamespace getvariable ['Map_OPFOR_B',1])",0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_OPFOR_R',0])","(profilenamespace getvariable ['Map_OPFOR_G',1])","(profilenamespace getvariable ['Map_OPFOR_B',1])",1};
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "8.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_B_Guerrila: CA_B_West
		{
			text = "$STR_GUERRILA";
			idc = 106;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_ca.paa";
			color[] = {"(profilenamespace getvariable ['Map_Independent_R',0])","(profilenamespace getvariable ['Map_Independent_G',1])","(profilenamespace getvariable ['Map_Independent_B',1])",0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_Independent_R',0])","(profilenamespace getvariable ['Map_Independent_G',1])","(profilenamespace getvariable ['Map_Independent_B',1])",1};
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "10.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_B_Civilian: CA_B_West
		{
			text = "$STR_CIVILIAN";
			idc = 107;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_ca.paa";
			color[] = {"(profilenamespace getvariable ['Map_Civilian_R',0])","(profilenamespace getvariable ['Map_Civilian_G',1])","(profilenamespace getvariable ['Map_Civilian_B',1])",0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_Civilian_R',0])","(profilenamespace getvariable ['Map_Civilian_G',1])","(profilenamespace getvariable ['Map_Civilian_B',1])",1};
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "12.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_B_Virtual: CA_B_West
		{
			text = "$STR_A3_CFGFACTIONCLASSES_VIRTUAL_F";
			idc = 132;
			show = 0;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_virtual_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_virtual_ca.paa";
			color[] = {1,1,1,0.75};
			colorActive[] = {1,1,1,1};
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "13.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_ValueRoles: RscListBox
		{
			idc = 109;
			style = 16;
			colorPlayer[] = {1,1,0,1};
			colorAI[] = {1,0,0,1};
			colorNobody[] = {1,1,1,0.25};
			enabledAI = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\enabledAI_ca.paa";
			disabledAI = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\disabledAI_ca.paa";
			rowHeight = "1.75 * 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			x = "4.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "(14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "(9.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			colorSelectBackground[] = {1,1,1,0.3};
			colorSelectBackground2[] = {1,1,1,0.3};
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
		};
		
		class CA_ValuePool: RscListBox
		{
			idc = 114;
			canDrag = 1;
			rows = 25;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "safezoneX + (19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			w = "(19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "SafezoneH - (9.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorSelectBackground[] = {1,1,1,0.3};
			colorSelectBackground2[] = {1,1,1,0.3};
			colorPictureSelected[] = {1,1,1,1};
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
		};
		class CA_B_EnableAll: RscButtonMenu
		{
			idc = 117;
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "13.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "16.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_B_Lock: RscButtonMenu
		{
			idc = 118;
			x = "safezoneX + SafezoneW - (13.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_B_Params: RscButtonMenu
		{
			idc = 128;
			shortcuts[] = {"0x00050000 + 2"};
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "(25.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			text = "$STR_DISP_XBOX_EDITOR_WIZARD_PARAMS";
			y = "4.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonSteamWorkshop: RscButtonMenuSteam
		{
			x = "safezoneX + SafezoneW - (19.95 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			idc = 130;
			text = "$STR_A3_RscDisplayMultiplayerSetup_ButtonSteamWorkshop";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscDisplayMultiplayerSetup_ButtonSteamWorkshop_tooltip";
		};
		class CA_B_Kick: RscButtonMenu
		{
			idc = 116;
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "safezoneX + SafezoneW - (7.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = "$STR_DISP_MP_KICKOFF";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_ButtonContinue: RscButtonMenuOK
		{
			x = "safezoneX + SafezoneW - (7.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_ButtonCancel: RscButtonMenuCancel
		{
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = "$STR_DISP_BACK";
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TextMission: RscText
		{
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1002;
			text = "$STR_DISP_SRVSETUP_NAME";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TextRole: RscText
		{
			idc = 108;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			text = "$STR_DISP_MPSETUP_ROLES_WEST";
			x = "4.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,1};
		};
		class TextPlayersPool: RscText
		{
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "safezoneX + (19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			w = "(19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1011;
			text = "$STR_A3_RscDisplayMultiplayerSetup_TextPlayersPool";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,1};
		};
		class TextListedPlayers: RscText
		{
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "31.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1013;
			text = "$STR_A3_RscDisplayMultiplayerSetup_TextListedPlayers";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "5.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ValueListedPlayers: RscText
		{
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			style = 1;
			x = "37 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1015;
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};