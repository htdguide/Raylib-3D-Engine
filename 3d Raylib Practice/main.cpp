#include "raylib.h"
#include "entity.h"
#include <cmath>

using namespace std;

void mouseHandler(int x, int y) {												//If mouse hits the corner, cursor goes to the opposite side coodrdinate
	if (x >= GetScreenWidth() - 1)	SetMousePosition(1, y);
//	if (y >= GetScreenHeight() - 1)	SetMousePosition(x, 1);
	if (x == 0)	SetMousePosition(GetScreenWidth(), y);
//	if (y == 0)	SetMousePosition(x, GetScreenHeight());
}

int mouseHider() {																			//If left mouse clicked, hiding the cursor
	if (IsMouseButtonReleased(IsKeyDown(MOUSE_BUTTON_LEFT)) && !IsCursorHidden())
		HideCursor();
	return 0;
}

int main() {
	InitWindow(1920, 1080, "Model Loading");																																		//Initializing window
	Entity duck = Entity("./assets/ae86/ToyotaAE86.obj", "./assets/ae86/textures/Palette.png", "duck", Vector3{ 1.0f, 1.0f, 1.0f });
	Entity map = Entity("./assets/map/map.obj", "./assets/map/material.001.png", "map", Vector3{ 0.0f, 0.0f, 0.0f });	//Initializing entity
	Entity wheel = Entity("./assets/wheel/wheel.obj", "./assets/wheel/texturealbedo.png", "wheel", Vector3{ 0.0f, 1.0f, 0.0f });	//Initializing entity
	duck.entityModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = duck.entityTexture;	
	map.entityModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = map.entityTexture;
	wheel.entityModel.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = wheel.entityTexture;
	Texture2D texture2 = LoadTexture("./assets/wheel/texturnormal.png");
	wheel.entityModel.materials[0].maps[MATERIAL_MAP_NORMAL].texture = texture2;
	Texture2D texture3 = LoadTexture("./assets/wheel/texturespecular.png");
	wheel.entityModel.materials[0].maps[MATERIAL_MAP_SPECULAR].texture = texture3;
	SetTargetFPS(60);
	ToggleFullscreen();

	while (!WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) {

		mouseHandler(GetMouseX(), GetMouseY());																			//Moving mouse if it touches the screen border
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(duck.entityCamera);																					//Starting 3d with camera of the entity
		DrawModel(duck.entityModel, duck.entityPosition, 1.0f, WHITE);	
		DrawModel(map.entityModel, map.entityPosition, 250.0f, WHITE);													//Drawing a model
		DrawModel(wheel.entityModel, wheel.entityPosition, 0.13f, WHITE);
		
		DrawGrid(500, 10.0f);
		EndMode3D();

		
		mouseHider();																									//If left click is pressed, cursor hides
		duck.cameraMovementThirdPerson(GetMousePosition(), 20.0f, 1.0f);												//Moving a camera by a mouse


		int mousePosX = GetMousePosition().x;																			//Debugging 
		int mousePosY = GetMousePosition().y;																			//Debugging
		auto mouseX = std::to_string(mousePosX);																		//Debugging
		auto mouseY = std::to_string(mousePosY);
		auto posX = std::to_string(duck.entityPosition.x);																//Debugging
		auto posY = std::to_string(duck.entityPosition.z);


		duck.movement();																								//Entity movement method
	

	 	DrawText((const char *)mouseX.c_str(), 10, GetScreenHeight() - 25, 25, DARKGRAY);								//Debugging text
		DrawText((const char*)mouseY.c_str(), 300, GetScreenHeight() - 25, 25, DARKGRAY);
		DrawText((const char*)posX.c_str(), 10, 25, 25, DARKGRAY);														//Debugging text
		DrawText((const char*)posY.c_str(), 300, 25, 25, DARKGRAY);
		EndDrawing();
	}
	UnloadTexture(duck.entityTexture);
	UnloadModel(duck.entityModel);
	UnloadTexture(map.entityTexture);
	UnloadModel(map.entityModel);
	UnloadTexture(wheel.entityTexture);
	UnloadModel(wheel.entityModel);
	CloseWindow();
	return 0;
	
}
