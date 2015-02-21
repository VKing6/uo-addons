
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_unit,_item);
_ret = false;

if !(local _unit) exitWith {_ret};

	removeBackpack _unit;

	_unit addBackpack _item;
	
	{_unit removeItemFromBackpack _x} forEach (backpackItems _unit);

_ret = true;
_ret