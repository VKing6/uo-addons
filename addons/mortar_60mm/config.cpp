// #include "\x\cba\addons\main\script_macros_common.hpp"
#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        units[] = {"UO_B_Mortar_60mm","UO_O_Mortar_60mm","UO_I_Mortar_60mm",
          "UO_Box_60mm_Mo_HE","UO_Box_60mm_Mo_Smoke","UO_Box_60mm_Mo_Illum"};
        weapons[] = {"UO_mortar_60mm","UO_mortar_60mm_single"};
        requiredVersion = 1.0;
        requiredAddons[] = {"A3_Static_F_Mortar_01","A3_Weapons_F","ace_mk6mortar"};
        author = "VKing";
    };
};


class CfgCloudlets {
    class MortarExp;
    class UO_60mmExp: MortarExp {
        size[] = {"0.05 * intensity + 2","0.05 * intensity + 1.25"};
    };
};

class MortarExplosion {
    class MortarExp1;
};
class UO_60mmExplosion: MortarExplosion {
    class MortarExp1: MortarExp1 {
        type = "UO_60mmExp";
    };
};

class CfgAmmo {
    class Sh_82mm_AMOS;
    class UO_Sh_60mm: Sh_82mm_AMOS {
        ace_frag_metal = 1500;
        ace_frag_charge = 200;
        hit = 105;
        indirectHit = 20;
        indirectHitRange = 6;
        explosionEffects = "UO_60mmExplosion";
    };
    class Flare_82mm_AMOS_White;
    class UO_Flare_60mm_white: Flare_82mm_AMOS_White {
        timeToLive = 30;
        //intensity = 7500;
    };
};

class CfgMagazines {
    class ACE_1Rnd_82mm_Mo_HE;
    class UO_1Rnd_60mm_Mo_HE: ACE_1Rnd_82mm_Mo_HE {
        displayName = "60mm HE Round";
        ammo = "UO_Sh_60mm";
        author = "VKing";
        mass = 40;
    };
    class ACE_1Rnd_82mm_Mo_Smoke;
    class UO_1Rnd_60mm_Mo_Smoke: ACE_1Rnd_82mm_Mo_Smoke {
        displayName = "60mm Smoke Round";
        author = "VKing";
        mass = 40;
    };
    class ACE_1Rnd_82mm_Mo_Illum;
    class UO_1Rnd_60mm_Mo_Illum: ACE_1Rnd_82mm_Mo_Illum {
        displayName = "60mm Illum Round";
        ammo = "UO_Flare_60mm_white";
        author = "VKing";
        mass = 40;
    };

    class 8Rnd_82mm_Mo_shells;
    class UO_8Rnd_60mm_Mo_shells: 8Rnd_82mm_Mo_shells {
        displayName = "60mm HE Magazine";
        ammo = "UO_Sh_60mm";
        author = "VKing";
    };
    class 8Rnd_82mm_Mo_Smoke_white;
    class UO_8Rnd_60mm_Mo_smoke_white: 8Rnd_82mm_Mo_Smoke_white {
        displayName = "60mm Smoke Magazine";
        author = "VKing";
    };
    class 8Rnd_82mm_Mo_Flare_white;
    class UO_8Rnd_60mm_Mo_flare_white: 8Rnd_82mm_Mo_Flare_white {
        displayName = "60mm Illum Magazine";
        ammo = "UO_Flare_60mm_white";
        author = "VKing";
    };
};

class CfgWeapons {
    class ACE_mortar_82mm;
    class UO_mortar_60mm_single: ACE_mortar_82mm {
        displayName = "Mortar 60mm";
        author = "VKing";
        magazines[] = {"UO_1Rnd_60mm_Mo_HE","UO_1Rnd_60mm_Mo_Smoke","UO_1Rnd_60mm_Mo_Illum"};
    };

    class mortar_82mm;
    class UO_mortar_60mm: mortar_82mm {
        ace_mk6mortar_replaceWith = "UO_mortar_60mm_single";
        displayName = "Mortar 60mm";
        author = "VKing";
        magazines[] = {"UO_8Rnd_60mm_Mo_shells","UO_8Rnd_60mm_Mo_smoke_white","UO_8Rnd_60mm_Mo_flare_white"};
    };
};

class CfgVehicles {
    class StaticWeapon;
    class StaticMortar: StaticWeapon {
        class Turrets;
    };
    class Mortar_01_base_F: StaticMortar {
        class Turrets: Turrets {
            class MainTurret;
        };
        class ACE_Actions;
    };
    class UO_Mortar_60mm_base: Mortar_01_base_F {
        displayName = "Mk60 Mortar";
        author = "VKing";
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = {"UO_mortar_60mm"};
                magazines[] = {"UO_8Rnd_60mm_Mo_shells","UO_8Rnd_60mm_Mo_shells","UO_8Rnd_60mm_Mo_shells","UO_8Rnd_60mm_Mo_shells","UO_8Rnd_60mm_Mo_smoke_white","UO_8Rnd_60mm_Mo_flare_white"};
            };
        };
        class assembleInfo {
            primary = 0;
            base = "";
            assembleTo = "";
            dissasembleTo[] = {"UO_B_Mortar_60mm_weapon","B_Mortar_01_support_F"};
            displayName = "";
        };
        class ACE_Actions: ACE_Actions {
            class ACE_Mk6Mortar_loadActions {
                condition = QUOTE(false);
            };
            class UO_60mm_loadActions {
                displayName = "Load Mortar";
                distance = 2;
                condition = QUOTE([ARR_2(_target,_player)] call ace_mk6mortar_fnc_canLoadMagazine);
                statement = "";
                icon = "";
                selection = "usti hlavne";
                class uo_60mm_loadMagazine_Illum {
                    displayName = "Load Illum";
                    condition = QUOTE([ARR_3(_target,_player,'UO_1Rnd_60mm_Mo_Illum')] call ace_mk6mortar_fnc_canLoadMagazine);
                    statement = QUOTE([ARR_4(_target,_player,5,'UO_1Rnd_60mm_Mo_Illum')] call ace_mk6mortar_fnc_loadMagazineTimer);
                    icon = "";
                };
                class uo_60mm_loadMagazine_Smoke {
                    displayName = "Load Smoke";
                    condition = QUOTE([ARR_3(_target,_player,'UO_1Rnd_60mm_Mo_Smoke')] call ace_mk6mortar_fnc_canLoadMagazine);
                    statement = QUOTE([ARR_4(_target,_player,2.5,'UO_1Rnd_60mm_Mo_Smoke')] call ace_mk6mortar_fnc_loadMagazineTimer);
                    icon = "";
                };
                class uo_60mm_loadMagazine_HE {
                    displayName = "Load HE";
                    condition = QUOTE([ARR_3(_target,_player,'UO_1Rnd_60mm_Mo_HE')] call ace_mk6mortar_fnc_canLoadMagazine);
                    statement = QUOTE([ARR_4(_target,_player,2.5,'UO_1Rnd_60mm_Mo_HE')] call ace_mk6mortar_fnc_loadMagazineTimer);
                    icon = "";
                };
            };
        };
    };
    class UO_B_Mortar_60mm: UO_Mortar_60mm_base {
        author = "VKing";
        scope = 2;
        side = 1;
        faction = "BLU_F";
        crew = "B_Soldier_F";
        availableForSupportTypes[] = {"Artillery"};
    };
    class UO_O_Mortar_60mm: UO_Mortar_60mm_base {
        author = "VKing";
        scope = 2;
        side = 0;
        faction = "OPF_F";
        crew = "O_Soldier_F";
        availableForSupportTypes[] = {"Artillery"};
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\A3\Static_f\Mortar_01\data\Mortar_01_OPFOR_CO.paa"};
        class assembleInfo: assembleInfo {
            dissasembleTo[] = {"UO_O_Mortar_60mm_weapon","O_Mortar_01_support_F"};
        };
    };
    class UO_I_Mortar_60mm: UO_Mortar_60mm_base {
        author = "VKing";
        scope = 2;
        side = 2;
        faction = "IND_F";
        crew = "I_soldier_F";
        availableForSupportTypes[] = {"Artillery"};
        class assembleInfo: assembleInfo {
            dissasembleTo[] = {"UO_I_Mortar_60mm_weapon","I_Mortar_01_support_F"};
        };
    };

    class Weapon_Bag_Base;
    class B_Mortar_01_weapon_F: Weapon_Bag_Base {
        class assembleInfo;
    };
    class UO_B_Mortar_60mm_weapon: B_Mortar_01_weapon_F {
        author = "VKing";
        displayName = "Folded Mk60 Tube and Bipod";
        mass = 280;
        class assembleInfo: assembleInfo {
            assembleTo = "UO_B_Mortar_60mm";
        };
    };
    class O_Mortar_01_weapon_F: Weapon_Bag_Base {
        class assembleInfo;
    };
    class UO_O_Mortar_60mm_weapon: O_Mortar_01_weapon_F {
        author = "VKing";
        displayName = "Folded Mk60 Tube and Bipod";
        mass = 280;
        class assembleInfo: assembleInfo {
            assembleTo = "UO_O_Mortar_60mm";
        };
    };
    class I_Mortar_01_weapon_F: Weapon_Bag_Base {
        class assembleInfo;
    };
    class UO_I_Mortar_60mm_weapon: I_Mortar_01_weapon_F {
        author = "VKing";
        displayName = "Folded Mk60 Tube and Bipod";
        mass = 280;
        class assembleInfo: assembleInfo {
            assembleTo = "UO_I_Mortar_60mm";
        };
    };
    class ACE_Box_82mm_Mo_HE;
    class UO_Box_60mm_Mo_HE: ACE_Box_82mm_Mo_HE {
        displayName = "60mm HE Box";
        author = "VKing";
        maximumLoad = 480;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UO_1Rnd_60mm_Mo_HE,12);
        };
    };
    class UO_Box_60mm_Mo_Smoke: UO_Box_60mm_Mo_HE {
        displayName = "60mm Smoke Box";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UO_1Rnd_60mm_Mo_Smoke,12);
        };
    };
    class UO_Box_60mm_Mo_Illum: UO_Box_60mm_Mo_HE {
        displayName = "60mm Illumination Box";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UO_1Rnd_60mm_Mo_Illum,12);
        };
    };
};
