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
	while (!WindowShouldClose() && !termination) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		const char *text = "ss";
		if (GuiButton(Rectangle{ 200, 200, 200, 200 }, "Press me!")) {
			commands("scene3d");
			termination = true;
		}
		EndDrawing();
	}
}