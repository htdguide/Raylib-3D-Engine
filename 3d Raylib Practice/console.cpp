#include "string.h"
#include <iostream>
#include "console.h"				//console header 
#include "raygui.h"					//rayGUI for the interface
#include "raylib.h"					//raylib for existance of this project
#include "gamelib.h"				//gamelib library with all of the actions
#include <cmath>					//c math
#include "trueno.h"					//trueno vehicle initialization header


console::console() {
	bool termination = false;
	consoleWindowClass consoleWindow;
	consoleWindow.size = Vector2{ (float)GetScreenWidth()/2, (float)GetScreenHeight()/2};

	while (!WindowShouldClose() && !termination) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		if (consoleWindow.console()) termination = true;
		EndDrawing();
	}
}