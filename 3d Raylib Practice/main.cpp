#include "raylib.h"
#include "gamelib.h"
#include <cmath>



int main() {

	InitWindow(1920, 1080, "Model Loading");																																		//Initializing window
	SetTargetFPS(60);
	ToggleFullscreen();

	actions action;
	Vehicle Trueno = { "Trueno", LoadModel("./assets/ae86/ToyotaAE86.obj"), LoadTexture("./assets/ae86/textures/Palette.png"), Camera3D{0}, Vector3{ 0.0f, 1.0f, 0.0f } };
	Level map = { "racetrack", LoadModel("./assets/map/map.obj"), LoadTexture("./assets/map/material.001.png")};																//Initializing entity
	Entity wheel = { "wheel", LoadModel("./assets/wheel/wheel.obj"), LoadTexture("./assets/wheel/texturealbedo.png"), Camera3D{}, Vector3{ 3.5f, 1.0f, 5.0f } };				//Initializing entity	

	Trueno = action.initialize(Trueno);																																			//Like a constructor
	map = action.initialize(map);																																				//Like a constructor
	wheel = action.initialize(wheel);																																			//Like a constructor

	while (!WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(Trueno.camera);																																				//Starting 3d with camera of the entity
		DrawModel(Trueno.model, Trueno.position, 1.0f, WHITE);	
		DrawModel(map.model, Vector3 {0 , 0 , 0}, 250.0f, WHITE);																												//Drawing a model
		DrawModel(wheel.model, wheel.position, 0.13f, WHITE);

		DrawGrid(500, 10.0f);
		EndMode3D();

		
		Trueno = action.cameraMovementThirdPerson(Trueno, GetMousePosition(), 20.0f, 1.0f);																						//Updating camera position																							//Moving a camera by a mouse


		int mousePosX = GetMousePosition().x;																																	//Debugging 
		int mousePosY = GetMousePosition().y;																																	//Debugging
		auto mouseX = std::to_string(mousePosX);																																//Debugging
		auto mouseY = std::to_string(mousePosY);
		auto posX = std::to_string(Trueno.position.x);																															//Debugging
		auto posY = std::to_string(Trueno.position.z);


		Trueno = action.movement(Trueno);																																							//Entity movement method
	

	 	DrawText((const char *)mouseX.c_str(), 10, GetScreenHeight() - 25, 25, DARKGRAY);																						//Debugging text
		DrawText((const char*)mouseY.c_str(), 300, GetScreenHeight() - 25, 25, DARKGRAY);
		DrawText((const char*)posX.c_str(), 10, 25, 25, DARKGRAY);																												//Debugging text
		DrawText((const char*)posY.c_str(), 300, 25, 25, DARKGRAY);
		EndDrawing();
	}
	UnloadTexture(Trueno.texture);
	UnloadModel(Trueno.model);
	UnloadTexture(map.texture);
	UnloadModel(map.model);
	UnloadTexture(wheel.texture);
	UnloadModel(wheel.model);
	CloseWindow();
	return 0;
}
