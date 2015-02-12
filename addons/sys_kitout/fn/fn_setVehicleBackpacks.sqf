#define COMPONENT uo_kitout
//#define DEBUG_MODE_FULL
#include "\x\cba\addons\main\script_macros_common.hpp"

PARAMS_2(_unit,_item);
_ret = false;

if !(local _unit) exitWith {_ret};

	clearBackpackCargoGlobal _unit; 
	{_unit addBackpackCargoGlobal [_x select 0,_x select 1]} forEach _item;

_ret = true;
_ret