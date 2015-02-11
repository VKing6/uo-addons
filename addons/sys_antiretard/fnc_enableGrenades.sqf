#include "script_component.hpp"

_firedEH = player getVariable[QGVAR(firedEH), -1];

if(_firedEH != -1) then {
	player removeEventHandler["fired", _firedEH];
};

player setVariable [QGVAR(firedEH), -1, false];

GVAR(grenadeDisabled) = false;
nou_sys_frag_enabled = true;