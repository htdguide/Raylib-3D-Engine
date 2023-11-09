#pragma once
#include <iostream>
#include <stdlib.h>
#include <raylib.h>
#include <string>

class Cameramode
{
private:
	int speed;
	bool horizontalLock, verticalLock, rotationLock;
	Cameramode(int speed, bool horizontalLock, bool verticalLock, bool rotationLock); //Contructor header 
	
public:
	void cameraMovement() {
		if (!horizontalLock && !verticalLock && !rotationLock) {             //No locks at all

		}
	}
};