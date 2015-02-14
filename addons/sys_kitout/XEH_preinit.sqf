#define COMPONENT uo_kitout
//#define DEBUG_MODE_FULL
#include "\x\cba\addons\main\script_macros_common.hpp"

uo_sys_kitout 		= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_kitout.sqf";
uo_sys_setVest		= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setVest.sqf";
uo_sys_setBackpack 	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setBackpack.sqf";
uo_sys_setUniform 	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setUniform.sqf";
uo_sys_setHeadgear 	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setHeadgear.sqf";
uo_sys_setGlasses 	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setGlasses.sqf";

uo_sys_setWeapons 	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setWeapons.sqf";
uo_sys_setPriKit 	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setPriKit.sqf";
uo_sys_setSecKit 	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setSecKit.sqf";
uo_sys_setRokKit 	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setRokKit.sqf";

uo_sys_setUniformItems 	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setUniformItems.sqf";
uo_sys_setVestItems 	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setVestItems.sqf";
uo_sys_setBackpackItems = compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setBackpackItems.sqf";
uo_sys_setAssignedItems = compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setAssignedItems.sqf";

uo_sys_setVehicleWeapons	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setVehicleWeapons.sqf";
uo_sys_setVehicleMagazines	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setVehicleMagazines.sqf";
uo_sys_setVehicleBackpacks	= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setVehicleBackpacks.sqf";
uo_sys_setVehicleItems		= compile preprocessFileLineNumbers "\sys_kitout\fn\fn_setVehicleItems.sqf";