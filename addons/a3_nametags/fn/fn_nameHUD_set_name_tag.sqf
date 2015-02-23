
	private ["_unit","_dist","_color","_hud","_displayDistance"];

	// Set variable
	_unit = _this select 0;
	_index = _this select 1;
	_color = _this select 2;
	_displayDistance = _this select 3;
	_ui = uiNamespace getVariable "a3_nameHUD";
	_txt = "";

	// Set distance
	_dist = _unit distance (vehicle player);

	// If unit distance is close than 10m
	if (_dist < _displayDistance) then {
		// If unit is not get in vehicle
		if (vehicle _unit == _unit) then {
			// Determine tag type and set text
			if (a3_nameHUD_enabled_group) then {
				_nam = name _unit;
				_grp = groupID group _unit;
				
				_txt = "" + _nam + "\n" + _grp + "";
			} else {
				_txt = name _unit;
			};

			// Set position name tag
			_pos = [((getPosATL _unit) select 0),((getPosATL _unit) select 1),( ( (getPosATL _unit) select 2)+((_unit selectionPosition "launcher") select 2) ) + 0.65];
			if(surfaceIsWater _pos) then {
				_pos = [((getPosASLW _unit) select 0),((getPosASLW _unit) select 1),( ((getPosASLW _unit) select 2)+((_unit selectionPosition "launcher") select 2) ) + 0.65];
			};
			_renderPos = worldToScreen _pos;
			//diag_log text format["Pos=%1", _pos];
			if (count _renderPos>0) then {
				_hud = _ui displayCtrl (23501 + _index);

				_hud ctrlSetPosition [(_renderPos select 0)-0.2,_renderPos select 1];
				_hud ctrlSetText (if (!visibleMap) then {_txt} else {""});
				_hud ctrlSetTextColor [(_color select 0),(_color select 1),(_color select 2),0.8 min (1.2 - _dist * (1 / _displayDistance))];
				_hud ctrlCommit 0;
				_index = _index + 1;
			};
		};
	};