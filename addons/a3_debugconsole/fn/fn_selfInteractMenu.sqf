/* Author: Naught */

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

// _this==[_target, _menuNameOrParams]
_target = _this select 0;
if((count _this) > 1) then {
    _params = _this select 1;
} else {
    _params = "mainDebug";
};
_menuName = "mainDebug";
_menuRsc = "popup";

if (typeName _params == typeName []) then {
    if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__];};
    _menuName = _params select 0;
    _menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
    _menuName = _params;
};
//-----------------------------------------------------------------------------

private ["_admin"];
_admin = (getPlayerUID player) in UO_admins;

_menus = [
    [
        ["mainDebug", "Main Menu", _menuRsc],
        [
            ["UO Debug >", "", "", "",
                ["_this call UO_fnc_selfInteractMenu", "UO_debugMenu", 1],
                -1, 1, (_admin),true]
        ]
    ]
];

if(_menuName == "UO_debugMenu") then {

    _menus set [count _menus,
        [
            ["UO_debugMenu", "Debug Menu", "popup", ""],
            [
                [
                "UO Debug Console",
                    { ['keyDown', [findDisplay 49,59], ''] execVM 'a3\ui_f\scripts\GUI\RscDisplayInterrupt.sqf'; },
                    "", "", "", -1, 1,
                    (true), (true)
                ],
                [
                "Toggle Map Monitor",
                    { [2] call UO_fnc_mapMonitor; },
                    "", "", "", -1, 1,
                    (true), (true)
                ],
                [
                "Enable Zeus on Self",
                    { [] call UO_fnc_enableZeus; },
                    "", "", "", -1, 1,
                    (true), (true)
                ],
                [
                "Disable Zeus on Self",
                    { [2] call UO_fnc_disableZeus; },
                    "", "", "", -1, 1,
                    (true), (true)
                ]
            ]
        ]
    ];
};

//-----------------------------------------------------------------------------
_menuDef = [];
{
    if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
    hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this}else{""}, __FILE__];
    diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _this, __FILE__];
};

_menuDef // return value
