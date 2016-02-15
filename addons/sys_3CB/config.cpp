#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"UK3CB_BAF_Vehicles_Coyote_Jackal","UK3CB_BAF_Units_MTP"};
        author = "VKing";
    };
};

class cfgFunctions {
    class UK3CB_BAF_Vehicles_Coyote_Jackal {
        class UK3CB_BAF_Vehicles_Coyote_Jackal {
            class switch_lights {
                file = QUOTE(PATHTOF(fnc_switch_lights.sqf));
            };
        };
    };
    class UK3CB_BAF_Units_MTP {
        class UK3CB_BAF_Units_MTP {
            class init_eh {
                file = QUOTE(PATHTOF(fnc_init_eh.sqf));
            };
        };
    };
};
