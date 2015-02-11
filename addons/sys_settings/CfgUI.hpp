#include "script_component.hpp"

class RscStandardDisplay;
class RscPicture;

class RscDisplayMultiplayerSetup: RscStandardDisplay {
	class Controls;
	class controls : controls {
		class UO_LogoBackground: RscPicture
		{
			x = "safezoneXAbs";
			w = "safezoneWAbs";
			idc = 1200;
			text = "\A3\ui_f\data\map\diary\gradient_gs.paa";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,0.15};
		};
	};
};