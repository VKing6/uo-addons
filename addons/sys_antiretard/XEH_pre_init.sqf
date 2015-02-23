#include "script_component.hpp"

ADDON = false;

// Kill log
PREP(onKilled);
PREP(monitorKills);

// game start protection
PREP(disableFire);
PREP(disableGrenades);

PREP(enableFire);
PREP(enableGrenades);

// GVARs

GVAR(grenadeDisabled) = false;
GVAR(gotWarning) = true;
GVAR(kills) = [];

if(isDedicated) then {
	[] call compile preprocessFileLineNumbers QUOTE(PATHTOF(initializeMarkerLog.sqf));
};

ADDON = true;