#pragma once
#include <iostream>
#include <stdlib.h>
#include <raylib.h>
#include <cmath>
#include <string>
#include "entity.h"

class Cameramode
{
	
public:
	Cameramode(); //Contructor header 
	void cameraMovement(Entity entity, Vector2 mouseMov, float distance, float speed) {

		entity.entityCamera.position.x = entity.position.x + distance * sin(mouseMov.x * speed) * cos(mouseMov.y * speed);
		entity.entityCamera.position.y = entity.position.y + distance * sin(mouseMov.x * speed) * sin(mouseMov.y * speed);
		entity.entityCamera.position.z = entity.position.z + distance * cos(mouseMov.y * speed);
	}
};