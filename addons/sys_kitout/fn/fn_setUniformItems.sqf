#define COMPONENT uo_kitout
//#define DEBUG_MODE_FULL
#include "\x\cba\addons\main\script_macros_common.hpp"

PARAMS_2(_unit,_item);
_ret = false;

if !(local _unit) exitWith {_ret};

if (!isNull uniformContainer _unit) then { 
	{
		for "_i" from 1 to (_x select 1) do {_unit addItemToUniform (_x select 0)} 
	} forEach _item;
};

_ret = true;
_ret