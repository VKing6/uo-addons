
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_unit,_type,_gear);

if !(local _unit) exitWith {};

_gearPath = missionConfigFile >> "uo_kitout_gear";
_weapons		= getArray (_gearPath >> _type >> _gear >> "weapons");
_priKit			= getArray (_gearPath >> _type >> _gear >> "weapons_priKit");
_secKit			= getArray (_gearPath >> _type >> _gear >> "weapons_secKit");
_rokKit			= getArray (_gearPath >> _type >> _gear >> "weapons_rokKit");

_headgear		= getArray (_gearPath >> _type >> _gear >> "headgear");
_glasses		= getArray (_gearPath >> _type >> _gear >> "glasses");

_uniform		= getArray (_gearPath >> _type >> _gear >> "uniform");
_uniformItems	= getArray (_gearPath >> _type >> _gear >> "uniformItems");

_vest			= getArray (_gearPath >> _type >> _gear >> "vest");
_vestItems		= getArray (_gearPath >> _type >> _gear >> "vestItems");

_backpack		= getArray (_gearPath >> _type >> _gear >> "backpack");
_backpackItems	= getArray (_gearPath >> _type >> _gear >> "backpackItems");

_assignedItems 	= getArray (_gearPath >> _type >> _gear >> "assignedItems");

_vehWeapons 	= getArray (_gearPath >> _type >> _gear >> "vehicleWeapons");
_vehMagazines	= getArray (_gearPath >> _type >> _gear >> "vehicleMagazines");
_vehBackpacks	= getArray (_gearPath >> _type >> _gear >> "vehicleBackpacks");
_vehItems		= getArray (_gearPath >> _type >> _gear >> "vehicleItems");

#define selectRandom(ARRAY) ARRAY select (floor random (count ARRAY));

if (_unit isKindOf "Man") then {
	//Clear Items and Assigned Items
	removeAllItemsWithMagazines _unit;
	removeAllAssignedItems _unit;

	//Remove weapons
	{_unit removeWeapon _x} forEach weapons _unit;

	//Remove Hats, Goggles
	removeHeadgear _unit;
	removeGoggles _unit;

	//Select and process uniforms
	if (count _uniform > 0) then {
		_uniform = selectRandom(_uniform);
		if (_uniform != uniform _unit) then {
			[_unit,_uniform] call FUNC(setUniform);
		};
	} else {
		removeUniform _unit;
	};

	//Select and process vests
	if (count _vest > 0) then {
		_vest = selectRandom(_vest);
		if (_vest != vest _unit) then {
			[_unit,_vest] call FUNC(setVest);
		};
	} else {
		removeVest _unit;
	};

	//Select and process backpacks
	if (count _backpack > 0) then {
		_backpack = selectRandom(_backpack);
		if (_backpack != backpack _unit) then {
			[_unit,_backpack] call FUNC(setBackpack);
		};
	} else {
		removeBackpack _unit;
	};

	//Select and process hats and goggles
	if (count _headgear > 0) then {
		_headgear = selectRandom(_headgear);
		[_unit,_headgear] call FUNC(setHeadgear);
	};
	if (count _glasses > 0) then {
		_glasses = selectRandom(_glasses);
		[_unit,_glasses] call FUNC(setGlasses);
	};
	
	//Select and process weapons
	if (count _weapons > 0) then {[_unit,_weapons] call FUNC(setWeapons); };

	//Add all the gear
	if (count _uniformItems > 0) then {[_unit,_uniformItems] call FUNC(setUniformItems); };
	if (count _vestItems > 0) then {[_unit,_vestItems] call FUNC(setVestItems); };
	if (count _backpackItems > 0) then {[_unit,_backpackItems] call FUNC(setBackpackItems); };
	if (count _assignedItems > 0) then {[_unit,_assignedItems] call FUNC(setAssignedItems); };

	//Add weapon attachments/ammo slots
	if (count _priKit > 0) then {[_unit,_priKit] call FUNC(setPriKit); };
	if (count _secKit > 0) then {[_unit,_secKit] call FUNC(setSecKit); };
	if (count _rokKit > 0) then {[_unit,_rokKit] call FUNC(setRokKit); };
} else {
	//Or if you're a vehicle, do this
	if ((count _vehWeapons) > 0) then {[_unit,_vehWeapons] call FUNC(setVehicleWeapons); };
	if ((count _vehMagazines) > 0) then {[_unit,_vehMagazines] call FUNC(setVehicleMagazines); };
	if ((count _vehBackpacks) > 0) then {[_unit,_vehBackpacks] call FUNC(setVehicleBackpacks); };
	if ((count _vehItems) > 0) then {[_unit,_vehItems] call FUNC(setVehicleItems); };
};