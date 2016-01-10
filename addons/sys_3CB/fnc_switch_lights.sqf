/*
Author: www.3commandobrigade.com
Switch a vehicle's lights between low and high beam
Arguments:
0: vehicle
Return Value:
None
*/

/////////////////////////////////////////////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////////////////////////////////////////

private ["_vehicle", "_switch"];
_vehicle = _this;

_switch = false;

if ((alive player) && (alive _vehicle) && (player == driver _vehicle)) then {

	if ((_vehicle animationPhase 'FrontLight') == 0) then {
		_vehicle animate ['FrontLight', 1];
		_vehicle animate ['FrontLightCone', 1];
	} else {
		_vehicle animate ['FrontLight', 0];
		_vehicle animate ['FrontLightCone', 0];
	};
	//playSound3D ["a3\sounds_f\weapons\closure\sfx1.wss", player, false, getPosASL player, 1, 1, 0];
	_switch = true;
};

_switch
