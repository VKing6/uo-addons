UO_fnc_getCurators = {
    private["_curatorPlayers", "_curatorObject", "_curatorPlayer"];
    _curatorPlayers = [];
    {
        _curatorObject = _x;
        _curatorPlayer = getAssignedCuratorUnit _curatorObject;
        _curatorPlayers set[(count _curatorPlayers), [_curatorPlayer, _curatorObject] ];
    } forEach allCurators;

    _curatorPlayers
};

UO_fnc_isCurator = {
    private["_curators", "_result"];

    _result = false;
    _curators = [] call UO_fnc_getCurators;
    {
        if((_x select 0) == player) exitWith {
            _result = true;
            _result
        };
    } forEach _curators;

    _result
};

_isCurator = [player] call UO_fnc_isCurator;
if(!_isCurator) then {
    diag_log text format["* Calling server side Zeus initialization"];
    player sideChat "!! You are now Zeus !!";
    hint "!! You are now Zeus !!";

    // [[[player, (name player), (getPlayerUID player)],"\x\uo\addons\a3_debugconsole\fn\fn_createZeus.sqf"],"BIS_fnc_execVM",false,true] call BIS_fnc_MP;
    [player, name player, getPlayerUID player] remoteExecCall ["uo_fnc_createZeus",0,false];
} else {
    diag_log text format["! You are already a Zeus!"];
    player sideChat "!! You are already a Zeus !!";
    hint "!! You are already a Zeus !!";
};
