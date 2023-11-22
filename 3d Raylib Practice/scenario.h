#include <iostream>
#include <stdlib.h>
#include <raylib.h>
#include <string>
#include "level.h"
#include "vehicle.h"
#include "entity.h"

class Scenario
{
	public:
		Level scenarioLevel = Level("", "", "");																					//To avoid constructor problems, filling empty level info
		Vehicle scenarioVehicle = Vehicle("", "", "", Vector3{0,0,0});													//To avoid constructor problems, filling empty vehicle info

		Scenario(Level inLevel, Vehicle inVehicle) {																				//Constructor
			scenarioLevel = inLevel;
			scenarioVehicle = inVehicle;
		}

};

