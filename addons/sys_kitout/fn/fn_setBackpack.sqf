#define COMPONENT uo_kitout
//#define DEBUG_MODE_FULL
#include "\x\cba\addons\main\script_macros_common.hpp"

PARAMS_2(_unit,_item);
_ret = false;

if !(local _unit) exitWith {_ret};

	removeBackpack _unit;

	_unit addBackpack _item;
	
	{_unit removeItemFromBackpack _x} forEach (backpackItems _unit);

_ret = true;
_ret