
/*
    Library: Administrative
    Author(s): Naught
*/

[(_this select 0), {
    _this spawn {
        TP_U2M_UNIT = (_this select 0);
        openMap [true, false];
        hint format[
            "Click on the map to teleport '%1' to the position.\nClose the map to stop the teleport function.",
            name(_this select 0)
        ];
        onMapSingleClick "
            if (!isNil 'TP_U2M_UNIT' && {!isNull TP_U2M_UNIT}) then {
                TP_U2M_UNIT setPos _pos;
                hint format['%1 teleported to:\n%2', (name TP_U2M_UNIT), _pos];
            } else {
                hint 'Unit is now invalid!\nNobody was teleported.';
            };
        ";
        waitUntil {!visibleMap};
        onMapSingleClick "";
        hint "Teleport function ended.";
    };
}] call UO_fnc_execOnPlayerLocal;
