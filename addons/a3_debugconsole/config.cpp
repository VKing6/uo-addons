class CfgPatches {
    class a3_debugconsole {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"A3_UI_F"};
    };
};

//class Extended_Killed_EventHandlers
//{
//    uo_debugconsole_killed = "_this call UO_efnc_killed";
//};
//class Extended_Fired_EventHandlers
//{
//    uo_debugconsole_fired = "_this call UO_efnc_fired";
//};
class Extended_PreInit_EventHandlers {
    class ADDON {
        init = "call compile preprocessFileLineNumbers '\x\uo\addons\a3_debugconsole\XEH_preInit.sqf'";
    };
};
class Extended_PostInit_EventHandlers {
    class ADDON {
        init = "call compile preprocessFileLineNumbers '\x\uo\addons\a3_debugconsole\xeh_postInit.sqf'";
    };
};

class CfgFunctions {
    class uo {
        class InteractMenu {
            class selfInteractMenu {
                file = "\x\uo\addons\a3_debugconsole\fn\fn_selfInteractMenu.sqf";
            };
        };
        class Monitor {
            class mapMonitor {
                file = "\x\uo\addons\a3_debugconsole\fn\fn_mapMonitor.sqf";
            };
            class overlay {
                file = "\x\uo\addons\a3_debugconsole\fn\fn_overlay.sqf";
            };
        };
        class Admin {
            class enableZeus {
                file = "\x\uo\addons\a3_debugconsole\fn\fn_enableZeus.sqf";
            };
            class disableZeus {
                file = "\x\uo\addons\a3_debugconsole\fn\fn_disableZeus.sqf";
            };
            class teleportU2M {
                file = "\x\uo\addons\a3_debugconsole\fn\fn_teleportU2M.sqf";
            };
            class teleportU2P {
                file = "\x\uo\addons\a3_debugconsole\fn\fn_teleportU2P.sqf";
            };
            class teleportU2U {
                file = "\x\uo\addons\a3_debugconsole\fn\fn_teleportU2U.sqf";
            };
        };
    };
};
//};
