
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_unit,_item);
_ret = false;

if !(local _unit) exitWith {_ret};

	{_unit addSecondaryWeaponItem _x} forEach _item;

_ret = true;
_ret