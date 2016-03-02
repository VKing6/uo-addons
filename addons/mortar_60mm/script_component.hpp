#define COMPONENT mortar_60mm
#include "\x\uo\Addons\main\script_mod.hpp"

#ifdef DEBUG_ENABLED_MORTAR_60MM
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_MORTAR_60MM
    #define DEBUG_SETTINGS DEBUG_SETTINGS_MORTAR_60MM
#endif

#define MACRO_ADDMAGAZINE(MAGAZINE,COUNT) class _xx_##MAGAZINE { \
    magazine = #MAGAZINE; \
    count = COUNT; \
}

#include "\x\uo\addons\main\script_macros.hpp"
