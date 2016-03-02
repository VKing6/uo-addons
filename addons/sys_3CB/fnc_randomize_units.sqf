/*
Author: www.3commandobrigade.com
Generates randomised load outs for units
Arguments:
0: unit
Return Value:
none
*/

//////////////////////////////////////////////////////////////////////////////////////////
// Main INIT EH
//////////////////////////////////////////////////////////////////////////////////////////

private ["_unit", "_count", "_headgear", "_facewear", "_uniform", "_vest", "_backpack", "_headSelected", "_faceSelected",
	"_uniformSelected", "_vestSelected", "_backpackSelected", "_unitMagazine", "_randomize", "_unitItem", "_succeeded"];

_unit = _this select	0;
_randomize = _this select 1;

// Save all items and magazines
if (!_randomize) then {
	_unitItem = items _unit;
	_unitMagazine = magazines _unit;
};

// Headgear
_headgear = getarray (configFile >> "cfgvehicles" >> typeof _unit >> "UK3CB_allowedheadgear");
_count = count _headgear;
if (_count > 0) then {
	_succeeded = (floor random 100) < getnumber (configFile >> "cfgvehicles" >> typeof _unit >> "UK3CB_headgearProbability");
	if (_randomize && _succeeded) then {
		_headSelected = _headgear select floor (random _count);
	} else {
		_headSelected = _headgear select 0;
	};
	if (_headSelected != "") then {
		_unit addHeadgear (_headSelected);
	};
};

// Facewear
_facewear = getarray (configFile >> "cfgvehicles" >> typeof _unit >> "UK3CB_allowedfacewear");
_count = count _facewear;
if (_count > 0) then {
	_succeeded = (floor random 100) < getnumber (configFile >> "cfgvehicles" >> typeof _unit >> "UK3CB_facewearProbability");
	if (_randomize && _succeeded) then {
		_faceSelected = _facewear select floor (random _count);
	} else {
		_faceSelected = _facewear select 0;
	};
	if (_faceSelected != "") then {
		_unit addGoggles (_faceSelected);
	} else {
		removeGoggles _unit;
	};
} else {
	removeGoggles _unit;
};

// Uniform
_uniform = getarray (configFile >> "cfgvehicles" >> typeof _unit >> "UK3CB_alloweduniform");
_count = count _uniform;
if (_count > 0) then {
	_succeeded = (floor random 100) < getnumber (configFile >> "cfgvehicles" >> typeof _unit >> "UK3CB_uniformProbability");
	if (_randomize && _succeeded) then {
		_uniformSelected = _uniform select floor (random _count);
	} else {
		_uniformSelected = _uniform select 0;
	};
	if (_uniformSelected != "") then {
		_unit addUniform (_uniformSelected);
	};
};

// Vest
_vest = getarray (configFile >> "cfgvehicles" >> typeof _unit >> "UK3CB_allowedvest");
_count = count _vest;
if (_count > 0) then {
	_succeeded = (floor random 100) < getnumber (configFile >> "cfgvehicles" >> typeof _unit >> "UK3CB_vestProbability");
	if (_randomize && _succeeded) then {
		_vestSelected = _vest select floor (random _count);
	} else {
		_vestSelected = _vest select 0;
	};
	if (_vestSelected != "") then {
		_unit addVest (_vestSelected);
	};
};

// Backpack
_backpack = getarray (configFile >> "cfgvehicles" >> typeof _unit >> "UK3CB_allowedbackpack");
_count = count _backpack;
if (_count > 0) then {
	_succeeded = (floor random 100) < getnumber (configFile >> "cfgvehicles" >> typeof _unit >> "UK3CB_backpackProbability");
	if (_randomize && _succeeded) then {
		_backpackSelected = _backpack select floor (random _count);
	} else {
		_backpackSelected = _backpack select 0;
	};
	if (_backpackSelected != "") then {

		removeBackpack _unit;
		_unit addBackpack (_backpackSelected);
	};
};

if (!_randomize) then {
	// Restore all items and magazines
	{_unit addMagazine _x} forEach _unitMagazine;
	{_unit addItem _x} forEach _unitItem;
};
