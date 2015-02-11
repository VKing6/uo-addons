#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define GRENADE_MESSAGE "WARNING: YOU ALMOST KILLED EVERYONE!\nPress I instead of G to" +\
" open your inventory.\nRebind the throw key to avoid future accidents. If you still wish to throw, throw again."

FUNC(grenade_fired_eh) = {
	if (GVAR(grenadeDisabled)) then {
		if(!GVAR(gotWarning)) then {
			if ((_this select 2) == "HandGrenadeMuzzle" || (_this select 1) == "Throw") then {
				//TRACE_1("ITS A GRENADE", _this);
				deleteVehicle (_this select 6);
				
				//playSound "krause_retardalert";
				titleText [GRENADE_MESSAGE, "PLAIN", 3];
				player addMagazine (_this select 5); 
				
				GVAR(gotWarning) = true;
				
			};
		} else {
			[QGVAR(logGrenadeThrow), [(name player), (getPlayerUID player), (position player), (mapGridPosition player) ]] call CBA_fnc_globalEvent;
			GVAR(gotWarning) = false;
		};
	};
};

FUNC(handleGrenadeLog) = {
	private["_playerName", "_playerPos", "_playerGrid"];
	_playerName = _this select 0;
	_playerPos = _this select 1;
	_playerGrid = _this select 2;
	_playerId = _this select 3;
	diag_log text format[" << ND >> {%1, sid:%2}(%3, %4)", _playerName, _playerId, _playerId, _playerPos, _playerGrid];
};
[QGVAR(logGrenadeThrow), FUNC(handleGrenadeLog)] call CBA_fnc_addEventHandler;


_firedEH = player addEventHandler ["Fired", FUNC(grenade_fired_eh)];
player setVariable[QGVAR(firedEH), _firedEH, false];

nou_sys_frag_enabled = false;
GVAR(grenadeDisabled) = true;