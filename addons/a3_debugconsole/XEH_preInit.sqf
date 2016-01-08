#include "\a3\editor_f\Data\Scripts\dikCodes.h"

uo_fnc_createZeus = compile preprocessFileLineNumbers "\x\uo\addons\a3_debugconsole\fn\fn_createZeus.sqf";
uo_fnc_removeZeus = compile preprocessFileLineNumbers "\x\uo\addons\a3_debugconsole\fn\fn_removeZeus.sqf";

// Force activating all addons for this run of the missionStart
private["_cfgPatches", "_class", "_addons"];
_cfgPatches = configfile >> "cfgpatches";
for "_i" from 0 to (count _cfgPatches - 1) do {
	_class = _cfgPatches select _i;
	if (isclass _class) then {_addons pushBack (configname _class);};
};
_addons call bis_fnc_activateaddons;

if(!isDedicated) exitWith {};
//UO_localDefinedAdmins = call compile ("[" + (preprocessFile "\x\uo\addons\a3_debugconsole\admins.sqf") + "]");


UO_efnc_killed = {};
UO_efnc_fired = {};
