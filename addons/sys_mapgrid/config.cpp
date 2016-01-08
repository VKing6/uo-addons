class CfgPatches {
    class vk_uoMapGrid {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"uo_main",
        "A3_Map_Altis","A3_Map_Stratis","Map_VR","Chernarus","fata",
        "mbg_celle2","MBG_Cindercity","MCN_Aliabad","Porto","ProvingGrounds_PMC",
        "Shapur_BAF","Takistan","Thirsk","ThirskW","Utes","vt5","zargabad",
        "CUP_Worlds_Grid", // Ensure compatibility
        "FDF_Isle1_a", // Podagorsk
        "PRA3_Kz", // Kunduz
        "WL_Route191","WL_WRoute191" // Schwemlitz
        };
    };
};

class CfgLocationTypes { // Fixes missing font error on celle2
    class MBG_celle2_icon_A7 {
        font = "PuristaMedium";
    };
};

class CfgWorlds {
    class DefaultWorld {
        class Grid;
    };
    class CAWorld: DefaultWorld {};
    class Altis: CAWorld {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2  {
                zoomMax = 0.5;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class Stratis: CAWorld {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.95;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class VR: CAWorld {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class Chernarus: CAWorld {
        //15360
        class Grid: Grid {
            offsetX = 0;
            offsetY = 15360;
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class Porto: CAWorld {
        //5120
        class Grid: Grid {
            offsetX = 0;
            offsetY = 5120;
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class Utes: CAWorld {
        //5120
        class Grid: Grid {
            offsetX = 0;
            offsetY = 5120;
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class FDF_Isle1_a: CAWorld { //Podagorsk
        //20480
        class Grid: Grid {
            offsetX = 0;
            offsetY = 20480;
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class Thirsk: CAWorld {
        //5120
        class Grid: Grid {
            offsetX = 0;
            offsetY = 5120;
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class ThirskW: CAWorld {
        //5120
        class Grid: Grid {
            offsetX = 0;
            offsetY = 5120;
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class mbg_celle2: CAWorld {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "0000";
                formatY = "0000";
                stepX = 10;
                stepY = -10;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class WL_Route191: Utes { // Schwemlitz
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class WL_WRoute191: ThirskW { // Schwemlitz Winter
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class cindercity: CAWorld {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class Takistan: CAWorld {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class MCN_Aliabad: Takistan {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class Shapur_BAF: CAWorld {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class Zargabad: CAWorld {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class ProvingGrounds_PMC: CAWorld {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class fata: CAWorld {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class Kunduz: CAWorld {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
    class vt5: CAWorld {
        class Grid: Grid {
            class Zoom1 {
                zoomMax = 0.000001;
                format = "XY";
                formatX = "00000";
                formatY = "00000";
                stepX = 1;
                stepY = -1;
            };
            class Zoom2 {
                zoomMax = 0.85;
                format = "XY";
                formatX = "00";
                formatY = "00";
                stepX = 1000;
                stepY = -1000;
            };
            class Zoom3 {
                zoomMax = 1e+030;
                format = "XY";
                formatX = "0";
                formatY = "0";
                stepX = 10000;
                stepY = -10000;
            };
        };
    };
};
