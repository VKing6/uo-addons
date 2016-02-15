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
// Main POST INIT EH
// Performs post init for all server created units
// Performs both init and post init for all client (ie zeus) created units
//////////////////////////////////////////////////////////////////////////////////////////

_this spawn {
    private ["_unit", "_respawn"];
    _unit = _this select 0;
    _respawn = _this select 1;

    _initUnit = {
        //diag_log format["*** _initUnit called on the Client for %1 ***", _this];

        // Always randomise
        [_this, true] call UK3CB_BAF_Units_MTP_fnc_randomize_units;

        // Add specific load outs
        _this call UK3CB_BAF_Units_MTP_fnc_unit_loadout;

    };

    _initpostUnit = {
        // diag_log format["*** _initpostUnit called on the Client for %1 ***", _this];

        // diag_log format["*** UK3CB_enableRandomizedUnits=%1",missionNamespace getVariable "UK3CB_enableRandomizedUnits"];
        // diag_log format["*** UK3CB_reloadOnRespawn=%1",missionNamespace getVariable "UK3CB_reloadOnRespawn"];
        // diag_log format["*** UK3CB_addNVG=%1",missionNamespace getVariable "UK3CB_addNVG"];
        // diag_log format["*** UK3CB_add3DScopes=%1",missionNamespace getVariable "UK3CB_add3DScopes"];
        // diag_log format["*** UK3CB_addGPS=%1",missionNamespace getVariable "UK3CB_addGPS"];
        // diag_log format["*** UK3CB_removeFrags=%1",missionNamespace getVariable "UK3CB_removeFrags"];
        // diag_log format["*** UK3CB_replaceScopes=%1",missionNamespace getVariable "UK3CB_replaceScopes"];
        // diag_log format["*** UK3CB_enableSafety=%1",missionNamespace getVariable "UK3CB_enableSafety"];

        if (!(missionNamespace getVariable ["UK3CB_enableRandomizedUnits", true])) then {
            // Recall the function, but disable randomisation
            [_this, false] call UK3CB_BAF_Units_MTP_fnc_randomize_units;
        };

        if (missionNamespace getVariable ["UK3CB_addNVG", true]) then {
            _this addItem "UK3CB_BAF_HMNVS";
        };

        if (missionNamespace getVariable ["UK3CB_addGPS", true]) then {
            _this linkItem "ItemGPS";
        };

        if (missionNamespace getVariable ["UK3CB_replaceScopes", false]) then {
            _this call UK3CB_BAF_Units_MTP_fnc_add_reflex_sights;
        };

        if (missionNamespace getVariable ["UK3CB_removeFrags", false]) then {
            _this call UK3CB_BAF_Units_MTP_fnc_remove_frags;
        };

        if (!(isClass (configFile >> "cfgPatches" >> "ace_interaction"))) then {
            // ACE not loaded
            if (missionNamespace getVariable ["UK3CB_add3DScopes", true]) then {
                _this call UK3CB_BAF_Units_MTP_fnc_add_3D_scopes;
            };
        } else {
            // ACE loaded
            if (missionNamespace getVariable ["UK3CB_enableSafety", false]) then {
                if (_this == player) then {
                    [_this, currentWeapon _this, currentMuzzle _this] call ace_safemode_fnc_LockSafety;
                };
            };
        };
    };

    // Delay to allow the unit config module on the map to be initialize
    waitUntil {time > 1};

    // Delay to ensure that control has been passed from server to client
    sleep 6.0;

    //diag_log format["*** postinit for %1 ***", _unit];

    if (isServer) then {
        // SERVER side
        if (local _unit) then {
            _unit call _initpostUnit;
        };
    } else {
        // CLIENT side

        // Headless client
        if (!hasInterface) then {
            if (local _unit) then {
                _unit call _initUnit;
                _unit call _initpostUnit;
            };
        } else {
            // Wait for ownership of the player object to pass from the server to the client - Required for JIP
            if (player != player) then {
                waitUntil {!(isNull player)};
                waitUntil {time > 5}; // Zero delay in practice due to earlier sleep statement
            };

            if (local _unit) then {
                if (_unit != player) then {
                    // Unit created by Zeus
                    //diag_log format["*** Zeused %1 ***", _unit];
                    _unit call _initUnit;
                    _unit call _initpostUnit;
                }; else {
                    // Check for a respawning player
                    if (_respawn == 1) then {
                        //diag_log format["*** Respawning Player %1 ***", _unit];
                        if (missionNamespace getVariable ["UK3CB_reloadOnRespawn", true]) then {
                            _unit call _initUnit;
                            _unit call _initpostUnit;
                        };
                    } else {
                        //diag_log format["*** Player %1 ***", _unit];
                        _unit call _initUnit;
                        _unit call _initpostUnit;
                    };
                };
            };
        };
    };
};
