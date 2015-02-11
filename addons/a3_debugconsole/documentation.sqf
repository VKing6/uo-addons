/*
	Title: UO Debug Console Documentation
	Author(s): Naught, Krause
	
	Syntax:
	(start code)	
		[
			[
				"UO_fnc_functionName",
				"Description of function",
				[ // Function Parameters
					"Parameter 1 (string)",
					...
				],
				"Function syntax",
				[ // Function Examples
					"[params] call UO_fnc_functionName;",
					...
				]
			],
			...
		]
	(end)
*/

[
	[
		"UO_fnc_enableZeus",
		"Make yourself a Zeus player within the currently running mission.",
		[ // Function Parameters
		],
		"[] call UO_fnc_enableZeus;",
		[ // Function Examples
			"[] call UO_fnc_enableZeus;"
		]
	],
	[
		"UO_fnc_disableZeus",
		"Disable your Zeus privledges and stop being Zeus.",
		[ // Function Parameters
		],
		"[] call UO_fnc_disableZeus;",
		[ // Function Examples
			"[] call UO_fnc_disableZeus;"
		]
	],
	[
		"UO_fnc_mapMonitor",
		"Tracks units, vehicles, bodies, and bullets in real-time on the in-game map screen.",
		[ // Function Parameters
			"Marker Detail Level [number] (optional) : 0 = low, 1 = normal, 2 = high, 3 = very high",
			"Marker Update Interval in Seconds [number] (optional)"
		],
		"[(detailNum, intervalNum)] call UO_fnc_mapMonitor;",
		[ // Function Examples
			"[] call UO_fnc_mapMonitor;",
			"[0] call UO_fnc_mapMonitor;",
			"[3, 1] call UO_fnc_mapMonitor;"
		]
	],
	[
		"UO_fnc_teleportU2U",
		"Teleports a unit to another unit.",
		[ // Function Parameters
			"Origin Unit Name [string]",
			"Destination Unit Name [string]"
		],
		"['origUnitString', 'destUnitString'] call UO_fnc_teleportU2U;",
		[ // Function Examples
			"['Teddy', 'Naught'] call UO_fnc_teleportU2U;"
		]
	],
	[
		"UO_fnc_teleportU2M",
		"Opens the map and teleports a unit to position(s) based on map-clicks. The function ends when the map is closed.",
		[ // Function Parameters
			"Unit Name [string]"
		],
		"['unitNameString'] call UO_fnc_teleportU2M;",
		[ // Function Examples
			"['Naught'] call UO_fnc_teleportU2M;"
		]
	]
]