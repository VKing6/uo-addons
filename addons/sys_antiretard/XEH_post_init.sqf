//#define DEBUG_MODE_FULL
#include "script_component.hpp"

//if(isDedicated || !isMultiplayer) exitWith {};
//TRACE_1("enter", _this);

[] spawn {
	waitUntil { !isNull player };
	[] call FUNC(disableGrenades);
	// Disable grenades on all clients for first 5 minutes in game, regardless of JIP status
	GVAR(waitTime) = diag_tickTime + 300;
	waitUntil { diag_tickTime > GVAR(waitTime) };
	[] call FUNC(enableGrenades);
};

[] call FUNC(monitorKills);