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

class CfgSounds
{
	sounds[] = {};
	class krause_retardalert
	{
		name = "krause_retardalert";
		sound[] = {PATHTOF(retardalert.ogg),  db + 0, 1.0};
		titles[] = {0, ""};
	};
};

#include "CfgEventhandlers.hpp"
