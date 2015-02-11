////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.87
//Thu Dec 18 09:06:51 2014 : Source 'file' date Thu Dec 18 09:06:51 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class a3_nametags : config.bin{
class CfgPatches
{
	class a3_nametags
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_UI_F"};
	};
};
class Extended_PreInit_EventHandlers
{
	uo_nametags_preinit = "call compile preprocessFileLineNumbers '\x\uo\addons\a3_nametags\xeh_preInit.sqf'";
};
class Extended_PostInit_EventHandlers
{
	uo_nametags_postInit = "call compile preprocessFileLineNumbers '\x\uo\addons\a3_nametags\xeh_postInit.sqf'";
};
class CfgFunctions
{
	class uo
	{
		class nametags
		{
			class nameHUD_get_near_units
			{
				file = "\x\uo\addons\a3_nametags\fn\fn_nameHUD_get_near_units.sqf";
			};
			class nameHUD_set_name_tag
			{
				file = "\x\uo\addons\a3_nametags\fn\fn_nameHUD_set_name_tag.sqf";
			};
			class nameHUD_toggle_name_tag
			{
				file = "\x\uo\addons\a3_nametags\fn\fn_nameHUD_toggle_name_tag.sqf";
			};
			class nameHUD_toggle_group_tag
			{
				file = "\x\uo\addons\a3_nametags\fn\fn_nameHUD_toggle_group_tag.sqf";
			};
			class nameHUD_selfInteractMenu
			{
				file = "\x\uo\addons\a3_nametags\fn\fn_nameHUD_selfInteractMenu.sqf";
			};
		};
	};
};
class RscTitles
{
	class a3_nameHUD
	{
		idd = -1;
		movingEnable = 0;
		fadein = 0;
		duration = 0.5;
		fadeout = 0.5;
		name = "a3_nameHUD";
		onLoad = "uiNamespace setVariable ['a3_nameHUD',_this select 0]";
		controlsBackground[] = {};
		objects[] = {};
		class controls
		{
			class hud1
			{
				type = 0;
				idc = 23501;
				style = 530;
				x = -1;
				y = -1;
				w = 0.4;
				h = 0.4;
				sizeEx = 0.02;
				size = 1;
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,0.5,0.5,0.6};
				shadow = 1;
				text = "";
				lineSpacing = 1;
			};
			class hud2: hud1
			{
				idc = 23502;
			};
			class hud3: hud1
			{
				idc = 23503;
			};
			class hud4: hud1
			{
				idc = 23504;
			};
			class hud5: hud1
			{
				idc = 23505;
			};
			class hud6: hud1
			{
				idc = 23506;
			};
			class hud7: hud1
			{
				idc = 23507;
			};
			class hud8: hud1
			{
				idc = 23508;
			};
			class hud9: hud1
			{
				idc = 23509;
			};
			class hud10: hud1
			{
				idc = 23510;
			};
			class hud11: hud1
			{
				idc = 23511;
			};
			class hud12: hud1
			{
				idc = 23512;
			};
			class hud13: hud1
			{
				idc = 23513;
			};
			class hud14: hud1
			{
				idc = 23514;
			};
			class hud15: hud1
			{
				idc = 23515;
			};
			class hud16: hud1
			{
				idc = 23516;
			};
			class hud17: hud1
			{
				idc = 23517;
			};
			class hud18: hud1
			{
				idc = 23518;
			};
			class hud19: hud1
			{
				idc = 23519;
			};
			class hud20: hud1
			{
				idc = 23520;
			};
			class hud21: hud1
			{
				idc = 23521;
			};
			class hud22: hud1
			{
				idc = 23522;
			};
			class hud23: hud1
			{
				idc = 23523;
			};
			class hud24: hud1
			{
				idc = 23524;
			};
			class hud25: hud1
			{
				idc = 23525;
			};
			class hud26: hud1
			{
				idc = 23526;
			};
			class hud27: hud1
			{
				idc = 23527;
			};
			class hud28: hud1
			{
				idc = 23528;
			};
			class hud29: hud1
			{
				idc = 23529;
			};
			class hud30: hud1
			{
				idc = 23530;
			};
		};
	};
};
//};
