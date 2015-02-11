if(!isServer) exitWith { false };

_admin = _this select 0;
_name = _this select 1;
_uid = _this select 2;

_group = createGroup sideLogic;
// We need to make ourselves a Zeus!!! We need to spawn the module, give ourselves ownership, and add all the objects to it

diag_log text format["UO_ADMIN: Player '%1'{%2} has initiated GM Zeus!", _name, _uid];

_uoDebugCurator = _group createUnit ["ModuleCurator_F",[0,0,0],[],0,"NONE"];

if(isNil "UO_GMCurators") then { UO_GMCurators = []; };

_uoDebugCurator setVariable ["Addons", 3, true];
_uoDebugCurator addCuratorAddons activatedAddons; 
_uoDebugCurator addCuratorEditableObjects [allUnits, true];
_admin assignCurator _uoDebugCurator;  

UO_GMCurators set[(count UO_GMCurators), [[_admin,_name,_uid], _uoDebugCurator, _group]];
publicVariable "UO_GMCurators";