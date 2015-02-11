#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = { "Extended_EventHandlers", "CBA_MAIN"};
		VERSION_CONFIG;
	};
};

class CfgMods {
	class UOMODS_A3
	{
		dir = "@UOMODS_A3";
		picture = "";
		action = "http://www.unitedoperations.net";
		hideName = 0;
		hidePicture = 0;
		name = "UnitedOperations";
	};
};

