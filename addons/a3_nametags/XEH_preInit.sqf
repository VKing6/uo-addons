#include "\a3\editor_f\Data\Scripts\dikCodes.h"

if(isDedicated) exitWith {};

["United Operations", "Nametags Menu", ["player", [], -10, "_this call uo_fnc_nameHUD_selfInteractMenu", "main"], [DIK_APPS, [false, false, false]], false, "keydown"] call CBA_fnc_registerKeybindToFleximenu;