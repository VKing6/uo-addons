#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = { "uo_main", "cse_sys_medical" };
		version = VERSION;
	};
};

#include "CfgEventhandlers.hpp"
//#include "CfgUI.hpp"