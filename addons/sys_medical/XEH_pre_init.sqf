#include "script_component.hpp"

FUNC(isMedic) = {};
FUNC(hasDeployedMedicalFacility) = {

};
FUNC(canDeployedMedicalFacility) = {

};

FUNC(addDeployMedicalFacilityMenu) = {
	//Equipment Menu
	_entries = [
		[
			"Deploy",
			{},
			(CSE_ICON_PATH + "icon_backpack_radio.paa"),
			{[] call lynx_fnc_radialSub_paraflare},
			"Deploy Medical Facility"
		],
		[
			"Pick Up",
			{},
			(CSE_ICON_PATH + "icon_backpack_radio.paa"),
			{[] call lynx_fnc_radialSub_paraflare},
			"Pack Medical Facility"
		]
	];
	["ActionMenu","equipment", _entries ] call cse_fnc_addMultipleEntriesToRadialCategory_F;
};