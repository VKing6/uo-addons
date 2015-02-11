// COMPONENT should be defined in the script_component.hpp and included BEFORE this hpp
#define MAINPREFIX x

#define PREFIX uo

//--BUILDPREFIX
#include "\x\uo\Addons\main\script_version.hpp"
//--ENDBUILDPREFIX

#define VERSION MAJOR.MINOR.PATCHLVL.BUILD
#define VERSION_AR MAJOR,MINOR,PATCHLVL,BUILD
#define VERSION_PLUGIN MAJOR.MINOR.PATCHLVL.BUILD

// MINIMAL required version for the Mod. Components can specify others..
#define REQUIRED_VERSION 1.01

#ifndef VERSION_CONFIG
	#define VERSION_CONFIG version = VERSION; versionStr = QUOTE(VERSION); versionAr[] = {VERSION_AR}
#endif