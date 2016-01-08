if(!isServer) exitWith { false };

_admin = _this select 0;
_name = _this select 1;
_uid = _this select 2;

if(isNil "UO_GMCurators") exitWith {};

diag_log text format["UO_ADMIN: Player '%1'{%2} is removing themselves as Zeus", _name, _uid];

_newCurators = [];
{

    _player = ((_x select 0) select 0);
    if(_player == _admin) then {
        _curator = _x select 1;
        _curatorGroup = _x select 2;

        unassignCurator _curator;
        deleteVehicle _curator;
        deleteGroup _curatorGroup;
    };
    _newCurators = UO_GMCurators - [_x];
} forEach UO_GMCurators;

UO_GMCurators = _newCurators;
publicVariable "UO_GMCurators";
