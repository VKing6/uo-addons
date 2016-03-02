/*
Author: www.3commandobrigade.com
Add ACE items to a unit's loadout
Arguments:
0: unit
Return Value:
none
*/

/////////////////////////////////////////////////////////////////////////////////////////////
// MAIN
/////////////////////////////////////////////////////////////////////////////////////////////
private ["_unitName"];
_unitName = typeOf _this;

// Add magazines
{
	_this addMagazine _x;
} forEach getArray (configFile >> "CfgVehicles" >> _unitName >> "magazines");

// Add generic items
{
	_this addItem _x;
} forEach getArray (configFile >> "CfgVehicles" >> _unitName >> "items");

if (isClass (configFile >> "cfgPatches" >> "ace_medical")) then {
	// ACE3 equipment
	{
		_this addItem _x;
	} forEach getArray (ConfigFile >> "CfgVehicles" >> _unitName >> "UK3CB_loadout_ace_gear");

	{
		_this addItemToBackpack _x;
	} forEach getArray (ConfigFile >> "CfgVehicles" >> _unitName >> "UK3CB_loadout_ace_backpack");

} else {
	// Vanilla equipment
	{
		_this addItem _x;
	} forEach getArray (ConfigFile >> "CfgVehicles" >> _unitName >> "UK3CB_loadout_vanilla_gear");

	{
		_this addItemToBackpack _x;
	} forEach getArray (ConfigFile >> "CfgVehicles" >> _unitName >> "UK3CB_loadout_vanilla_backpack");
};
