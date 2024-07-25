#include "scene2D.h"				//scene3D Header 
#include "raygui.h"					//rayGUI for the interface
#include "raylib.h"					//raylib for existance of this project
#include "gamelib.h"				//gamelib library with all of the actions
#include <cmath>					//c math
#include "trueno.h"					//trueno vehicle initialization header
#define RAYGUI_STATIC

scene2D::scene2D() {


	while (!WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) {
		BeginDrawing();

		EndDrawing();
	}

}