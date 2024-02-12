#include "raylib.h"
#include "scene3D.h"

int main() {

	InitWindow(GetScreenWidth(), GetScreenHeight(), "3D Raylib Practice");																																	//Initializing window
	SetTargetFPS(60);
	ToggleFullscreen();
	scene3D();
	return 0;
}
