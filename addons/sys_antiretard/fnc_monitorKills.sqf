#include "script_component.hpp"

FUNC(logKill) = {
	private["_wait"];
	
	_wait = random 5;
	sleep _wait;
	
	["uo_logKill", _this] call CBA_fnc_globalEvent;
};

FUNC(writeLogKill) = {
	diag_log text _this;
};
["uo_logKill", FUNC(writeLogKill)] call CBA_fnc_addEventHandler;

FUNC(monitorKillsPFH) = {
	if(isNil QGVAR(kills)) exitWith {
		[GVAR(monitorKillsPFH_Handle)] call CBA_fnc_removePerFrameHandler;
	};
	if((count GVAR(kills)) > 0) then {
		{
			_x spawn FUNC(logKill);
		} forEach GVAR(kills);
		GVAR(kills) = [];
	};
};
// Only monitor in MP
if(isMultiplayer) then {
	GVAR(monitorKillsPFH_Handle) = [FUNC(monitorKillsPFH), 5, []] call CBA_fnc_addPerFrameHandler;
};