#include "raylib.h"
#include "console.h"

int main() {

	InitWindow(GetScreenWidth(), GetScreenHeight(), "3D Raylib Practice");																																	//Initializing window
	SetTargetFPS(60);
	ToggleFullscreen();
	console();
	CloseWindow();
	return 0;
}
