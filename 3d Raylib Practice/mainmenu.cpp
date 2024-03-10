#include "mainmenu.h"
#include "string.h"
#include <iostream>
#include "console.h"				//console header 
#include "raygui.h"					//rayGUI for the interface
#include "raylib.h"					//raylib for existance of this project
#include "gamelib.h"				//gamelib library with all of the actions
#include <cmath>					//c math
#include "trueno.h"					//trueno vehicle initialization header
#define RAYGUI_IMPLEMENTATION

mainmenu::mainmenu() {
	bool termination = false;																	//Window termination boolean
	consoleWindowClass consoleWindow;															//Creating cosnole window
	consoleWindow.size = Vector2{ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };		//Setting the size of the screen

	while (!WindowShouldClose() && !termination) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		if (consoleWindow.console()) termination = true;										//Run console untill termination is false
		EndDrawing();
	}
}