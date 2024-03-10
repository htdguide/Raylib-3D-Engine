#include "raylib.h"
#include "console.h"
#include "mainmenu.h"

int main() {

	InitWindow(GetScreenWidth(), GetScreenHeight(), "3D Raylib Practice");																																	//Initializing window
	SetTargetFPS(60);
	ToggleFullscreen();
	mainmenu();
	CloseWindow();
	return 0;
}
