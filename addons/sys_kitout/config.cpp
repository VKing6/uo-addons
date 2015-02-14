
class CfgPatches
{
 class uo_a3_framework
 {
  units[] = {};
  weapons[] = {};
  requiredVersion = 0.1;
  requiredAddons[] = {};
 };
};
class Extended_PreInit_EventHandlers
{
 class uo_sys_kitout
 {
  init = "call compile preprocessFileLineNumbers '\sys_kitout\XEH_preinit.sqf'";
 };
};