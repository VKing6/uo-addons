#include "script_component.hpp"

private["_unit", "_killer", "_unitId", "_killerId", "_logText", "_unitSide", "_killerSide", "_unitPos", "_unitGrid", "_killerPos", "_wait", "_killerGrid", "_near", "_nearPlayers", "_logFormat"];
_unit = _this select 0;
_killer = _this select 1;

if(player != _unit) exitWith {};

// Log the death
_unitPos = getPosATL player;
_unitGrid = mapGridPosition player;
_unitSide = side player;
_unitId = getPlayerUID player;

_killerPos = getPosATL _killer;
_killerGrid = mapGridPosition _killer;
_killerSide = side _killer;
_killerId = getPlayerUID _killer;

_near = _unitPos nearObjects ["Man", 100];
_nearPlayers = [];
{
	if(isPlayer _x) then {
		_nearPlayers pushBack [(name _x),_x];
	};
} forEach _near;
_logFormat = "<< KILL >> [%15] %1, {%2,%3,%4,sid:%5}(LOC %6, GRID %7) killed by {%8,%9,%10,sid:%11}(LOC %12, GRID %13) Near:%14";

_logText = format [_logFormat, 
						(name _unit),_unit,
						_unitPos,_unitGrid,_unitSide,_unitId,
						(name _killer),_killer,
						_killerPos,_killerGrid,_killerSide,_killerId,					
						_nearPlayers,
						diag_tickTime
					];	
					
GVAR(kills) pushBack _logText;
