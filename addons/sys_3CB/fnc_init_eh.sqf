/*
Author: www.3commandobrigade.com
EH to initialise the BAF units
Arguments:
0: unit
1: respawn (BOOL)
Return Value:
none
*/

//////////////////////////////////////////////////////////////////////////////////////////
// Main INIT EH
// This routine is deliberately not in a separate thread as this causes load order issues
//////////////////////////////////////////////////////////////////////////////////////////

/* Disable

private ["_unit", "_respawn"];
_unit = _this select 0;
_respawn = _this select 1;

_initUnit = {
    //Perform the default init for all units
    //diag_log format["*** _initUnit called on the Server for %1 ***", _this];

    // Always randomise
    [_this, true] call UK3CB_BAF_Units_MTP_fnc_randomize_units;

    // Add specific load outs
    _this call UK3CB_BAF_Units_MTP_fnc_unit_loadout;

};

//diag_log format["*** init for %1 ***", _unit];

if (isServer) then {
    if (local _unit) then {
        _unit call _initUnit;
    };
};

// Call the init post manually to ensure that it follows INIT for JIP players
// Note initPost runs in a separate thread and includes timing delays
[_unit, _respawn] call UK3CB_BAF_Units_MTP_fnc_initpost_EH;
*/
