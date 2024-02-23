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
	consoleWindow.size = Vector2{ 1280, 720 };

	while (!WindowShouldClose() && !termination) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		consoleWindow.borderColor = GRAY;
		consoleWindow.drawConsole();

		if (GuiButton(Rectangle{200, 200, 200, 200 }, "Hello")) {
			commands("scene3d");
			termination = true;
		}
		EndDrawing();
	}
}