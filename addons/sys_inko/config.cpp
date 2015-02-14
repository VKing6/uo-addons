class CfgPatches
{
 class inko_disposable_a3
 {
  units[] = {"INKO_NLAW_USED_TUBE","INKO_RPG26_USED_TUBE","INKO_RPG18_USED_TUBE","INKO_RSHG2_USED_TUBE","INKO_M136_USED_TUBE","INKO_M136_HEDP_USED_TUBE","INKO_M136_HP_USED_TUBE"};
  weapons[] = {"INKO_NLAW_USED","rhs_weap_M136_used","rhs_weap_M136_hedp_used","rhs_weap_M136_hp_used"};
  requiredVersion = 0.1;
  requiredAddons[] = {"inko_disposable_a3","rhs_c_weapons"};
  author[] = {"TinfoilHate"};
  magazines[] = {"INKO_NLAW_USED","rhs_rpg26_dummy","rhs_rshg2_dummy","rhs_rpg18_dummy","rhs_m136_dummy"};
 };
};
class CfgMagazines
{
 class CA_LauncherMagazine;
 class NLAW_F: CA_LauncherMagazine
 {
  inko_disposable = 1;
  model = "";
  mass = 0;
  allowedslots[] = {701,801,901};
 };
 class INKO_NLAW_USED: NLAW_F
 {
  scope = 1;
  count = 0;
  type = 0;
  inko_disposable = 0;
  displayName = "NLAW (Used)";
 };
 class FakeMagazine;
 class rhs_rpg26_mag: FakeMagazine
 {
  mass = 0;
  allowedslots[] = {701,801,901};
 };
 class rhs_rpg26_dummy: rhs_rpg26_mag
 {
  scope = 1;
  count = 0;
  type = 0;
  inko_disposable = 0;
  displayName = "RPG-26 (Used)";
 };
 class rhs_rshg2_mag: rhs_rpg26_mag
 {
  mass = 0;
  allowedslots[] = {701,801,901};
 };
 class rhs_rshg2_dummy: rhs_rshg2_mag
 {
  scope = 1;
  count = 0;
  type = 0;
  inko_disposable = 0;
  displayName = "RShG-2 (Used)";
 };
 class rhs_rpg18_mag: rhs_rpg26_mag
 {
  mass = 0;
  allowedslots[] = {701,801,901};
 };
 class rhs_rpg18_dummy: rhs_rpg18_mag
 {
  scope = 1;
  count = 0;
  type = 0;
  inko_disposable = 0;
  displayName = "RPG-18 (Used)";
 };
 class rhs_m136_mag: CA_LauncherMagazine
 {
  mass = 0;
  allowedslots[] = {701,801,901};
 };
 class rhs_m136_dummy: rhs_m136_mag
 {
  scope = 1;
  count = 0;
  type = 0;
  inko_disposable = 0;
 };
};
class CfgWeapons
{
 class Default
 {
  inko_disposable = 0;
 };
 class Launcher_Base_F;
 class launch_NLAW_F: Launcher_Base_F
 {
  inko_disposable = 1;
  inko_disposable_used = "INKO_NLAW_USED";
  inko_disposable_tube = "INKO_NLAW_USED_TUBE";
 };
 class rhs_weap_rpg26: Launcher_Base_F
 {
  inko_disposable = 1;
  inko_disposable_used = "rhs_weap_rpg26_used";
  inko_disposable_tube = "INKO_RPG26_USED_TUBE";
 };
 class rhs_weap_rpg18: rhs_weap_rpg26
 {
  inko_disposable = 1;
  inko_disposable_used = "rhs_weap_rpg18_used";
  inko_disposable_tube = "INKO_RPG18_USED_TUBE";
 };
 class rhs_weap_rshg2: rhs_weap_rpg26
 {
  inko_disposable = 1;
  inko_disposable_used = "rhs_weap_rshg2_used";
  inko_disposable_tube = "INKO_RSHG2_USED_TUBE";
 };
 class rhs_weap_M136: Launcher_Base_F
 {
  inko_disposable = 1;
  inko_disposable_used = "rhs_weap_M136_used";
  inko_disposable_tube = "INKO_M136_USED_TUBE";
 };
 class rhs_weap_M136_hedp: rhs_weap_M136
 {
  inko_disposable = 1;
  inko_disposable_used = "rhs_weap_M136_hedp_used";
  inko_disposable_tube = "INKO_M136_HEDP_USED_TUBE";
 };
 class rhs_weap_M136_hp: rhs_weap_M136
 {
  inko_disposable = 1;
  inko_disposable_used = "rhs_weap_M136_hp_used";
  inko_disposable_tube = "INKO_M136_HP_USED_TUBE";
 };
 class INKO_NLAW_USED: launch_NLAW_F
 {
  descriptionShort = "N-LAW Rocket Launcher. Cannot be re-used.";
  displayName = "NLAW (Used)";
  inko_disposable = 0;
  magazines[] = {"INKO_NLAW_USED"};
  model = "\A3\weapons_F\launchers\nlaw\nlaw_F.p3d";
 };
 class rhs_weap_rpg26_used: rhs_weap_rpg26
 {
  descriptionshort = "Used launcher tube";
  displayname = "$STR_RHS_RPG26USED_NAME";
  inko_disposable = 0;
  magazines[] = {"rhs_rpg26_dummy"};
  model = "\rhsafrf\addons\rhs_weapons\rpg26\rpg26_unloaded";
 };
 class rhs_weap_rpg18_used: rhs_weap_rpg18
 {
  descriptionshort = "Used launcher tube";
  displayname = "$STR_RHS_RPG18USED_NAME";
  inko_disposable = 0;
  magazines[] = {"rhs_rshg2_dummy"};
  model = "\rhsafrf\addons\rhs_weapons\rpg26\rpg26_unloaded";
 };
 class rhs_weap_rshg2_used: rhs_weap_rshg2
 {
  descriptionshort = "Used launcher tube";
  displayname = "$STR_RHS_RSHG2USED_NAME";
  inko_disposable = 0;
  magazines[] = {"rhs_rpg18_dummy"};
  model = "\rhsafrf\addons\rhs_weapons\rpg26\rshg2_unloaded";
 };
 class rhs_weap_M136_used: rhs_weap_M136
 {
  scope = 1;
  descriptionshort = "Used launcher tube";
  displayname = "M136 HEAT (used)";
  inko_disposable = 0;
  magazines[] = {"rhs_m136_dummy"};
 };
 class rhs_weap_M136_hedp_used: rhs_weap_M136_used
 {
  displayname = "M136 HEDP (used)";
  inko_disposable = 0;
  magazines[] = {"rhs_m136_dummy"};
 };
 class rhs_weap_M136_hp_used: rhs_weap_M136_used
 {
  displayname = "M136 HP (used)";
  inko_disposable = 0;
  magazines[] = {"rhs_m136_dummy"};
 };
};
class CfgVehicles
{
 class Land_Map_F;
 class INKO_NLAW_USED_TUBE: Land_Map_F
 {
  scope = 1;
  side = -1;
  model = "\A3\weapons_F\launchers\nlaw\nlaw_F.p3d";
  icon = "";
  displayName = "";
  nameSound = "";
  destrType = "DestructNo";
  mapSize = 0;
  accuracy = 0;
  armor = 5;
  weight = 20;
 };
 class INKO_RPG26_USED_TUBE: INKO_NLAW_USED_TUBE
 {
  scope = 1;
  descriptionshort = "Used launcher tube";
  displayname = "$STR_RHS_RPG26USED_NAME";
  model = "\rhsafrf\addons\rhs_weapons\rpg26\rpg26_unloaded";
 };
 class INKO_RPG18_USED_TUBE: INKO_NLAW_USED_TUBE
 {
  scope = 1;
  descriptionshort = "Used launcher tube";
  displayname = "$STR_RHS_RPG18USED_NAME";
  model = "\rhsafrf\addons\rhs_weapons\rpg26\rpg26_unloaded";
 };
 class INKO_RSHG2_USED_TUBE: INKO_NLAW_USED_TUBE
 {
  scope = 1;
  descriptionshort = "Used launcher tube";
  displayname = "$STR_RHS_RSHG2USED_NAME";
  model = "\rhsafrf\addons\rhs_weapons\rpg26\rshg2_unloaded";
 };
 class INKO_M136_USED_TUBE: INKO_NLAW_USED_TUBE
 {
  scope = 1;
  descriptionshort = "Used launcher tube";
  displayname = "M136 HEAT (used)";
  model = "rhsusf\addons\rhsusf_weapons\M136\at4";
  class AnimationSources
  {
   class Loaded
   {
    source = "user";
    animPeriod = 0;
    initPhase = 1;
   };
  };
 };
 class INKO_M136_HEDP_USED_TUBE: INKO_NLAW_USED_TUBE
 {
  scope = 1;
  descriptionshort = "Used launcher tube";
  displayname = "M136 HEAT (used)";
  model = "rhsusf\addons\rhsusf_weapons\M136\at4";
  class AnimationSources
  {
   class Loaded
   {
    source = "user";
    animPeriod = 0;
    initPhase = 1;
   };
  };
 };
 class INKO_M136_HP_USED_TUBE: INKO_NLAW_USED_TUBE
 {
  scope = 1;
  descriptionshort = "Used launcher tube";
  displayname = "M136 HP (used)";
  model = "rhsusf\addons\rhsusf_weapons\M136\at4";
  class AnimationSources
  {
   class Loaded
   {
    source = "user";
    animPeriod = 0;
    initPhase = 1;
   };
  };
 };
};
class CfgCloudlets
{
 class RHS_RocketBackfireRPGNT;
 class RHS_Fired_RPG26: RHS_RocketBackfireRPGNT
 {
  beforeDestroyScript = "\sys_inko\empty.sqf";
 };
 class RHS_Fired_RPG18: RHS_Fired_RPG26
 {
  beforeDestroyScript = "\sys_inko\empty.sqf";
 };
 class RHS_Fired_Rshg2: RHS_Fired_RPG26
 {
  beforeDestroyScript = "\sys_inko\empty.sqf";
 };
 class RHS_Fired_M136HEAT: RHS_RocketBackfireRPGNT
 {
  beforeDestroyScript = "\sys_inko\empty.sqf";
 };
 class RHS_Fired_M136HEDP: RHS_Fired_M136HEAT
 {
  beforeDestroyScript = "\sys_inko\empty.sqf";
 };
 class RHS_Fired_M136HP: RHS_Fired_M136HEAT
 {
  beforeDestroyScript = "\sys_inko\empty.sqf";
 };
};
