#include "\a3\editor_f\Data\Scripts\dikCodes.h"


/* Define Common Macros */
#define DEFAULT_PARAM(idx,dft)	(if ((count _this) > idx) then {_this select idx} else {dft})

/* Begin Init */
UO_debugConsole = false;


/* Execute on server machine only */
if (isServer) then {
	call compile preprocessFileLineNumbers "\x\uo\addons\a3_debugconsole\XEH_postInit_server.sqf";
};

/* Execute on player machine(s) only */
if (hasInterface) then {
	/*waitUntil { !isNil "UO_admins" && !isNil player };
	_admin = (getPlayerUID player) in UO_admins;
	if(_admin) then {
		["United Operations", "Admin Console", ["player", [], -10, "_this call uo_fnc_selfInteractMenu", "main"], [DIK_APPS, [false, false, false]], false, "keydown"] call CBA_fnc_registerKeybindToFleximenu;
	} else {
		
	};*/

	/* Load Debug Console Documentation */
	[] spawn {
		waitUntil {!isNull player && {!isNil "UO_admins"}};
		if (!isMultiplayer || (getPlayerUID player) in UO_admins) then {
			["United Operations", "Admin Console", ["player", [], -10, "_this call uo_fnc_selfInteractMenu", "main"], [DIK_APPS, [false, false, false]], false, "keydown"] call CBA_fnc_registerKeybindToFleximenu;
			
			private ["_docs", "_docStr"];
			_docs = call compile preprocessFile "\x\uo\addons\a3_debugconsole\documentation.sqf";
			_docStr = "<br/>UO Debug Console - Function Documentation<br/><br/>By: Naught, Krause<br/>";
			{ // forEach
				_docStr = _docStr + "<br/>--------------------------------------------------<br/><br/>";
				_docStr = _docStr + format["Function: %1<br/>Description: %2<br/>Parameter(s):<br/>", _x select 0, _x select 1];
				if ((count (_x select 2)) == 0) then {
					_docStr = _docStr + "    None.<br/>";
				} else {
					{ // forEach
						_docStr = _docStr + format["    %1: %2<br/>", _forEachIndex, _x];
					} forEach (_x select 2);
				};
				_docStr = _docStr + format["Syntax: %1<br/>Example(s):<br/>", _x select 3];
				if ((count (_x select 4)) == 0) then {
					_docStr = _docStr + "    None.<br/>";
				} else {
					{ // forEach
						_docStr = _docStr + format["    Example #%1: %2<br/>", _forEachIndex, _x];
					} forEach (_x select 4);
				};
			} forEach _docs;
			player createDiarySubject ["uodc_docs", "UO Debug Console"];
			// TODO: Merge all documentation into one standard file (documentation.sqf)
			player createDiaryRecord ["uodc_docs", ["Documentation", _docStr]];
		};
	};
};

/* End Init */
UO_debugConsole = true;
