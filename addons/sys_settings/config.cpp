#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = { "uo_main" };
		version = VERSION;
	};
};

#include "CfgEventhandlers.hpp"
//#include "CfgUI.hpp"