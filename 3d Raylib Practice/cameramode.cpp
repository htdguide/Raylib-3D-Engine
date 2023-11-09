#include <iostream>
#include <stdlib.h>
#include <raylib.h>
#include "cameramode.h"


Cameramode::Cameramode(int inspeed, bool inhorizontalLock, bool inverticalLock, bool inrotationLock) //Contructor [speed of the mouse movement, horizontal lock, verticla lock and the rotation lock]
{
	speed = inspeed;
	horizontalLock = inhorizontalLock;
	verticalLock = inverticalLock;
	rotationLock = inrotationLock;
}