/* Author: Naught */
diag_log text format["ARGS: _this=%1", _this];
	private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

	// _this==[_target, _menuNameOrParams]
	_target = _this select 0;
	if((count _this) > 1) then {
		_params = _this select 1;
	} else {
		_params = "nameHUD";
	};
	
	_menuName = "nameHUD";
	_menuRsc = "popup";

	if (typeName _params == typeName []) then {
		if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__];};
		_menuName = _params select 0;
		_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
	} else {
		_menuName = _params;
	};
	//-----------------------------------------------------------------------------

	_menus = [
		[
			["nameHUD", "Main Menu", _menuRsc],
			[
				["UO Nametags >", "", "", "",
					["_this call uo_fnc_nameHUD_selfInteractMenu", "UO_nametagMenu", 1],
					-1, 1, (a3_nameHUD_active),true
				]
			]
		]
	];

	if(_menuName == "UO_nametagMenu") then {

		_menus set [count _menus,
			[
				["UO_nametagMenu", "Nametag Options", "popup", ""],
				[
					[
					"Toggle Nametags",
						{ [] call uo_fnc_nameHUD_toggle_name_tag },
						"", "", "", -1, 1,
						(true), (true)
					],
					[
					"Toggle Group Tags",
						{ [] call uo_fnc_nameHUD_toggle_group_tag },
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