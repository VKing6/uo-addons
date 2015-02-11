#define DEBUG_MODE_FULL

#include "script_component.hpp"

/* class RscDisplayMultiplayerSetup */
//CA_ValueRoles, 109
//CA_ValuePool, 114
//UO_ValueRoles,666

FUNC(openSlotSelectionDialog) = {
	TRACE_1("Enter", _this);
	
	createDialog "UO_ZeusSlottingSelectionDisplay";
	
	
};

#define ROW_HEIGHT 0.04
#define TEXT_DIMENSIONS 0.4,0.05

#define ROW_IDC_START 666

GVAR(rowIndex) = 0;
GVAR(slotListBoxes) = [];

#define ROW_POS(x) (x*ROW_HEIGHT)
#define CUR_ROW_POS ROW_POS(GVAR(rowIndex))

#define ROW_IDC(number) (ROW_IDC_START+number)
#define CUR_ROW_IDC ROW_IDC(GVAR(rowIndex))

#define INCREMENT_ROW GVAR(rowIndex) = GVAR(rowIndex) + 1;
#define INCREMENT_ROW_COUNT(x) GVAR(rowIndex) = GVAR(rowIndex) + x;

FUNC(onSlottingMouseButtonClick) = {
	TRACE_1("onSlottingMouseButtonClick", _this);
};

FUNC(onSlottingLBSelectionChanged) = {
	TRACE_1("onSlottingLBSelectionChanged", _this);
	_listbox = _this select 0;
	
	
};

FUNC(createSlotSelectionDialogFromMission) = {
	private["_display", "_controlGroup", "_i", "_indexTrack"];
	TRACE_1("createSlotSelectionDialogFromMission", _this);
	
	disableSerialization;
	
	_display = _this select 0;
	_controlGroup = _this select 1;
	
	// DO CONTROL GROUP HERE
	_indexTrack = 0;
	
	_allPlayers = [];
	_allGroups = [];
	{
		_allPlayableUnits pushBack _x;
		if(!(group _x) in _allGroups) then {
			_allGroups pushBack (group _x);
		};
	} forEach playableUnits;
	
	TRACE_1("Players", _allPlayers);
	TRACE_1("Groups", _allGroups);
	
};

FUNC(createGroupControl) = {
	private["_display", "_controlGroup", "_groupName"];
	TRACE_1("createGroupControl", _this);
	
	_groupConfig = _this select 0;
	_display = _this select 1;
	_controlGroup = _this select 2;
	
	// Create the group label text and listbox for the group, return the listbox IDC
	_groupName = getText (_groupConfig >> "name");
	TRACE_1("Group", _groupName);
	_idc = CUR_ROW_IDC;
	_groupRow = _display ctrlCreate ["RscText", _idc, _controlGroup];
	_groupRow ctrlSetText _groupName;
	_groupRow ctrlSetPosition [0, CUR_ROW_POS, TEXT_DIMENSIONS];
	_groupRow ctrlCommit 0;
	INCREMENT_ROW;
	
	_slotsConfig = "true" configClasses (_groupConfig >> "Slots");
	_slotCount = (count _slotsConfig);
	
	_idc = CUR_ROW_IDC;
	_slotsListBox = _display ctrlCreate ["UO_RscListBox", _idc, _controlGroup];
	_slotsListBox ctrlSetPosition [0, CUR_ROW_POS, 0.4, 0.05*(_slotCount)];
	INCREMENT_ROW_COUNT(_slotCount);

	{
		_slotConfig = _x;
		_slotName = getText (_slotConfig >> "name");
		_slotNameText = format["-  %1", _slotName];
		
		_slotsListBox lbAdd _slotNameText;
	} forEach _slotsConfig;
	_slotsListBox ctrlCommit 0;
	
	GVAR(slotListBoxes) pushBack [_groupName, _slotsListBox];
	_idc;
};

FUNC(createSlotSelectionDialogFromTemplate) = {
	private["_display", "_controlGroup", "_templateName"];
	TRACE_1("createSlotSelectionDialogFromTemplate", _this);
	
	_templateName = _this select 0;
	_display = (_this select 1) select 0;
	_controlGroup = (_this select 1) select 1;
	_isValidTemplate = false;
	_templateConfig = nil;
	
	// Try the missionConfig first to allow mission overrides, then try addon defaults
	if(!isClass (missionConfigFile >> "UO_Templates" >> "SlotTemplates" >> _templateName)) then { 
		if( isClass (configFile >> "UO_Templates" >> "SlotTemplates" >> _templateName)) then {
			_templateConfig = (configFile >> "UO_Templates" >> "SlotTemplates" >> _templateName);
			_isValidTemplate = true;
		};		
	} else {
		_templateConfig = (missionConfigFile >> "UO_Templates" >> "SlotTemplates" >> _templateName);
		_isValidTemplate = true;
	};
	if(!_isValidTemplate) exitWith { LOG("Invalid Template!"); false };
	
	_groupsConfig = "true" configClasses (_templateConfig >> "Groups");
	
	{
		_groupConfig = _x;
		_groupName = getText (_groupConfig >> "name");
		TRACE_1("Group", _groupName);
		
		// Create a group label
		_slotListIdc = [_groupConfig, _display, _controlGroup] call FUNC(createGroupControl);
	} forEach _groupsConfig;
};

FUNC(createSlotSelectionDialog) = {
	private["_display", "_controlGroup"];
	
	TRACE_1("createSlotSelectionDialog", _this);
	disableSerialization;
	_display = _this select 0;
	_controlGroup = _this select 1;
	
	// Test, use a template
	["US_InfantryPlatoon_01", [_display, _controlGroup]] call FUNC(createSlotSelectionDialogFromTemplate);
	
	//[_display, _controlGroup] call FUNC(populateSlotSelectionDialogFromMission);
};



FUNC(onLoadSlotSelectionDialog) = {
	private["_display", "_controlGroup"];
	
	TRACE_1("onLoadSlotSelectionDialog", _this);
	disableSerialization;

	GVAR(rowIndex) = 0;
	GVAR(slotListBoxes) = [];
	
	_display = _this select 0;
	_controlGroup = _display displayCtrl 666;
	
	[_display, _controlGroup] call FUNC(createSlotSelectionDialog);
	
		// Fill the player list
	_valuePoolControl = _display displayCtrl 114;
	// Add test playersNumber
	GVAR(playerCount) = 0;
	{
		if(isPlayer _x) then {
			_name = format["* %1", (name _x)];
			_index = _valuePoolControl lbAdd _name;
			GVAR(playerCount) = GVAR(playerCount) + 1;
		};
	} forEach allUnits;
};

FUNC(onUnloadSlotSelectionDialog) = {
	TRACE_1("onUnloadSlotSelectionDialog", _this);
	
};