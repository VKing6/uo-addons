#define COMPONENT uo_kitout
//#define DEBUG_MODE_FULL
#include "\x\cba\addons\main\script_macros_common.hpp"

PARAMS_2(_unit,_item);
_ret = false;

if !(local _unit) exitWith {_ret};

if (!isNull backpackContainer _unit) then { 
	{_unit linkItem _x} forEach _item;
};

_ret = true;
_ret