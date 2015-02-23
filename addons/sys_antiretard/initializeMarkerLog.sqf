#include "script_component.hpp"

_init='
if (HasInterface) then {
    ZEU_MkLog_fcollectMrkInfo = {
        [
            _this,
            getText  (configFile >> "CfgMarkers" >> (markertype _this) >> "name"),
            markerColor _this,
            markerText _this,
            mapGridPosition markerPos _this
        ];
    };


        "ZEU_MkLog_MrkOpPV" addPublicVariableEventHandler
        {
        	if !(HASINTERFACE)exitwith{};
        	_p = ((_this select 1)select 0);
        	if(Player == _p)exitwith{};
        	_n = name _p;
        	_pUID 	= ((_this select 1)select 1);
        	_pSide 	= ((_this select 1)select 2);
        	_did 	= ((_this select 1)select 3);
        	_type 	= ((_this select 1)select 4)select 1;
        	_colour = ((_this select 1)select 4)select 2;
        	if(_colour == "Default")then{_colour = "Black"};
        	_txt 	= "";
        	if((((_this select 1)select 4)select 3)== "")then{_txt = ""}else{_txt = format [" with text: << %1 >>",((_this select 1)select 4)select 3]};
        	_grid 	= (((_this select 1)select 4)select 4);

        	if(playerside== _pSide)then
  			{
				systemchat format ["<< MARKER >> %1 %2 a %3 %4 at Grid %5 %6",_n, _did, _colour, _type, _grid, _txt ];
  			};;
        };


    ZEU_MkLog_fsetMrkEHs = {
        scopeName "func";
        waitUntil {
            if (
                _this == 53 && getClientState == "BRIEFING READ"
            ) then {
                breakOut "func";
            };
            !isNull findDisplay _this
        };
        findDisplay _this displayAddEventHandler [
            "KeyDown",
            {
                if (_this select 1 == 211) then {
                    _mrknames = allMapMarkers;
                    _mrkdetails = [];
                    {
                        _mrkdetails pushBack (
                            _x call ZEU_MkLog_fcollectMrkInfo
                        );
                    } forEach _mrknames;
                    0 = [_mrknames, _mrkdetails] spawn {
                        _mrknames = _this select 0;
                        _mrkdetails = _this select 1;
                        ZEU_MkLog_MrkOpPV =
                        [
                            player,
                            getplayerUID player,
                            playerside,
                            "DELETED"
                        ];
                        {
                            _i = _mrknames find _x;
                            if (_i > -1) then {
                                ZEU_MkLog_MrkOpPV pushBack (_mrkdetails select _i);
                            };
                        } forEach (_mrknames - allMapMarkers);
                        if (count ZEU_MkLog_MrkOpPV > 4) then {
                            publicVariableServer "ZEU_MkLog_MrkOpPV";
                        };
                    };
                    false
                };
            }
        ];
        findDisplay _this displayAddEventHandler [
            "ChildDestroyed",
            {
                if (
                    ctrlIdd (_this select 1) == 54 && _this select 2 == 1
                ) then {
                    0 = all_mrkrs spawn {
                        ZEU_MkLog_MrkOpPV =
                        [
                            player,
                            getplayerUID player,
                            playerside,
                            "PLACED"
                        ];
                        {
                            ZEU_MkLog_MrkOpPV pushBack (
                                _x call ZEU_MkLog_fcollectMrkInfo
                            );
                        } forEach (allMapMarkers - _this);
                        if (count ZEU_MkLog_MrkOpPV > 4) then {
                            publicVariableServer "ZEU_MkLog_MrkOpPV";
                        };
                    };
                };
            }
        ];
        findDisplay _this displayCtrl 51 ctrlAddEventHandler [
            "MouseButtonDblClick",
            {
                0 = 0 spawn {
                    if (!isNull findDisplay 54) then {
                        findDisplay 54 displayCtrl 1
                            buttonSetAction "all_mrkrs = allMapMarkers";
                    };
                };
            }
        ];
    };
    0 = 12 spawn ZEU_MkLog_fsetMrkEHs;
    0 = 53 spawn ZEU_MkLog_fsetMrkEHs;
};
';
    0 = 0 spawn {
        "ZEU_MkLog_MrkOpPV" addPublicVariableEventHandler
        {
        	_p = ((_this select 1)select 0);
        	_n = name _p;
        	_did 	= ((_this select 1)select 3);
        	_type 	= ((_this select 1)select 4)select 1;
        	_colour = ((_this select 1)select 4)select 2;
        	if(_colour == "Default")then{_colour = "Black"};
        	_txt 	= "";
        	if((((_this select 1)select 4)select 3)== "")then{_txt = ""}else{_txt = format [" with text: << %1 >>",((_this select 1)select 4)select 3]};
        	_grid 	= (((_this select 1)select 4)select 4);

        	_h = floor(Time / 3600);
			_m = floor((Time - (_h*3600)) / 60);
			_s = floor(Time mod 60);
			_mTime = format ["@ Time %1h:%2m:%3s",_h,_m,_s ];
			diag_log format ["<< MARKER >> %1 %2 a %3 %4 at Grid %5 %6 at %7",_n, _did, _colour, _type, _grid, _txt, _mTime ];
			// If players are still in briefing, report the marker operation to the players
          	if(Time < 1)then
          	{
          		ZEU_MkLog_MrkOpPV = (_this select 1);
          		publicVariable "ZEU_MkLog_MrkOpPV";
          		if(hasInterface) then { 
				systemchat format ["<< MARKER >> %1 %2 a %3 %4 at Grid %5 %6 at %7",_n, _did, _colour, _type, _grid, _txt, _mTime ];
				};
          	};
        };
    };
"Logic" createUnit [[1,1,1], (createGroup sideLogic), _init, 0.5, "corporal"];