#include "raylib.h"
#include "gamelib.h"
#include <cmath>
#include "trueno.h"
#define RAYGUI_IMPLEMENTATION
#include "C:\Users\mogil\source\repos\htdguide\3d-Raylib-Practice\raylib-4.5.0_win64_msvc16\raygui-master\src\raygui.h"

int main() {

	InitWindow(GetScreenWidth(), GetScreenHeight(), "Model Loading");																																	//Initializing window
	SetTargetFPS(60);
	ToggleFullscreen();
	
	

	actions action;																																																															//Call an action class for library manipulations
	Level map = { "racetrack", LoadModel("./assets/map/map.obj"), LoadTexture("./assets/map/material.001.png")};																//Initializing entity
	truenoVehicleCreator truenoCreator = truenoVehicleCreator();
	Vehicle trueno = truenoCreator.vehicle;
	map = action.initialize(map);																																							
	
	while (!WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(trueno.camera);																																				//Starting 3d with camera of the entity
		action.vehicleDraw(trueno, trueno.position, 1.0f, 0.13f, WHITE);
		DrawModel(map.model, Vector3 {0 , 0 , 0}, 250.0f, WHITE);																												//Drawing a model


		DrawGrid(500, 10.0f);
		EndMode3D();

		trueno = action.cameraMovementThirdPerson(trueno, GetMousePosition(), 20.0f, 1.0f);																						//Updating camera position																							//Moving a camera by a mouse

		int mousePosX = GetMousePosition().x;																																	//Debugging 
		int mousePosY = GetMousePosition().y;																																	//Debugging
		auto mouseX = std::to_string(mousePosX);																																//Debugging
		auto mouseY = std::to_string(mousePosY);
		auto posX = std::to_string(trueno.position.x);																															//Debugging
		auto posY = std::to_string(trueno.position.z);

		trueno = action.movement(trueno, 0.5f);																																	//Entity movement method

		if (GuiButton(Rectangle { 200, 200, 200, 200 }, "Press me!")) {
			std::cout << "Pressed";
		}

	 	DrawText((const char *)mouseX.c_str(), 10, GetScreenHeight() - 25, 25, DARKGRAY);																						//Debugging text
		DrawText((const char*)mouseY.c_str(), 300, GetScreenHeight() - 25, 25, DARKGRAY);
		DrawText((const char*)posX.c_str(), 10, 25, 25, DARKGRAY);																												//Debugging text
		DrawText((const char*)posY.c_str(), 300, 25, 25, DARKGRAY);
		EndDrawing();
	}
	action.vehicleUnload(trueno);
	UnloadTexture(map.texture);
	UnloadModel(map.model);

	CloseWindow();
	return 0;
}
