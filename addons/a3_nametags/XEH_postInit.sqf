#include "\a3\editor_f\Data\Scripts\dikCodes.h"

	if (isDedicated) exitWith {};
	
	/* Disable if not flagged active */
	if (count allMissionObjects "cse_sys_tags" > 0) exitWith {};
	if (isNil "a3_nameHUD_active") then {a3_nameHUD_active = true};
	if (!a3_nameHUD_active) exitWith {};

	disableSerialization;

	if (isNil "a3_nameHUD_enabled") then {a3_nameHUD_enabled = true};
	if (isNil "a3_nameHUD_drawDistance") then {a3_nameHUD_drawDistance = 20};
	if (isNil "a3_nameHUD_enabled_group") then {a3_nameHUD_enabled_group = false};

	if (a3_nameHUD_enabled) then {
		[{
			if (a3_nameHUD_enabled && alive player) then {
				_nearUnits = [a3_nameHUD_drawDistance] call uo_fnc_nameHUD_get_near_units;
				_leader = leader (group player);
				_playerIsLeader = false;
				
				if(alive _leader) then {
					if(_leader == player) then {
						_playerIsLeader = true;
					};
				};
				
				if (_playerIsLeader) then {
					{
						if(alive _x) then {
							_unitTeam = _x getVariable ["a3_nameHUD_groupAssignment","MAIN"];
							if (_unitTeam != assignedTeam _x) then {
								_x setVariable ["a3_nameHUD_groupAssignment",assignedTeam _x,true];
							};
						};
					} forEach units (group player);
				} else {
					{
						if(alive _x) then {
							_unitTeam = _x getVariable ["a3_nameHUD_groupAssignment","MAIN"];
							if (_unitTeam != assignedTeam _x) then {
								_x assignTeam _unitTeam;
							};
						};
					} forEach units (group player);
				};
			};
		}, 5] call CBA_fnc_addPerFrameHandler;

		[{
			if (a3_nameHUD_enabled && alive player) then {
				_nearUnits = [a3_nameHUD_drawDistance] call uo_fnc_nameHUD_get_near_units;

				if (count _nearUnits > 0) then {
					1 cutRsc ["a3_nameHUD","PLAIN"];
					_index = 0;
					_teamColor = [1,1,1,1];
					{
						if (_x in units group player) then {
							if (_x == leader (group player)) then {
								_teamColor = [0.85, 0.4, 0, 1]
							} else {
								_liveTeam = _x getVariable ["a3_nameHUD_groupAssignment","MAIN"];
								switch (_liveTeam) do {
									case "RED": 	{_teamColor = [1, 0, 0, 1]};
									case "GREEN": 	{_teamColor = [0, 1, 0, 1]};
									case "BLUE": 	{_teamColor = [0, 0, 1, 1]};
									case "YELLOW": 	{_teamColor = [0.85, 0.85, 0, 1]};
									default 		{_teamColor = [1,1,1,1]};
								};
							};
						} else {_teamColor = [0.8,0.8,0.8,1]};
						[_x, _index, _teamColor, a3_nameHUD_drawDistance] call uo_fnc_nameHUD_set_name_tag;
					} forEach _nearUnits;
				};
			};
		}, 0] call CBA_fnc_addPerFrameHandler;
	};