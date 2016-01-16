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

if (isServer) then {
    /* Load Administrators */
    UO_admins = ["_SP_PLAYER_"];
    if (isDedicated) then {
        UO_admins_userconfig = getArray (ConfigFile >> "ACE_ServerSettings" >> "UO_Admins" >> "admins");
    };
    if (!isNil "UO_admins_userconfig") then {
        UO_admins = UO_admins + UO_admins_userconfig;
    };
    publicVariable "UO_admins";
};

if(!isDedicated) exitWith {};


UO_efnc_killed = {};
UO_efnc_fired = {};
