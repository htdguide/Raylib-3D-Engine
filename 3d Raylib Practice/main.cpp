#include "raylib.h"
#include "entity.h"
#include <cmath>

using namespace std;

void mouseHandler(int x, int y) {												//If mouse hits the corner, cursor goes to the opposite side coodrdinate
	if (x >= GetScreenWidth() - 1)	SetMousePosition(0, y);
	if (y >= GetScreenHeight() - 1)	SetMousePosition(x, 0);
	if (x == 0)	SetMousePosition(GetScreenWidth(), y);
	if (y == 0)	SetMousePosition(x, GetScreenHeight());
}

int mouseHider() {																			//If left mouse clicked, hiding the cursor
	if (IsMouseButtonReleased(IsKeyDown(MOUSE_BUTTON_LEFT)) && !IsCursorHidden())
		HideCursor();
	return 0;
}

int main() {
	InitWindow(1920, 1080, "Model Loading");																																		//Initializing window
	Entity duck = Entity("./assets/duck/OBJ/RubberDuck_LOD0.obj", "./assets/duck/Unity/RubberDuck_AlbedoTransparency.png", "duck", Vector3{ 0.0f, 0.0f, 0.0f });					//Initializing entity
	duck.entityModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = duck.entityTexture;																							//I dont know what is it

	float xAxis = 0.0f;
	float zAxis = 0.0f;


	SetTargetFPS(60);
	ToggleFullscreen();

	while (!WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) {
	
		BoundingBox bounds = GetMeshBoundingBox(duck.entityModel.meshes[0]);											//Bounding box from the model
		mouseHandler(GetMouseX(), GetMouseY());																			//Moving mouse if it touches the screen border
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(duck.entityCamera);																					//Starting 3d with camera of the entity
		DrawModel(duck.entityModel, duck.entityPosition, 1.0f, WHITE);														//Drawing a model
		DrawGrid(20, 10.0f);
		DrawBoundingBox(bounds, GREEN);
		EndMode3D();


		mouseHider();																									//If left click is pressed, cursor hides
		duck.cameraMovement(GetMousePosition(), 100.0f, 1.0f);

		xAxis = GetMousePosition().x / (GetScreenWidth()/360.0f);
		zAxis = GetMousePosition().y / (GetScreenHeight()/360.0f);

		//float xAxisRad = -(xAxis * PI) / 180;
		//float zAxisRad = -(zAxis * PI) / 180;

		//// Calculate the new position relative to the duck's position
		//float offsetX = 100 * cos(zAxisRad) * sin(xAxisRad);
		//float offsetY = 100 * sin(zAxisRad);
		//float offsetZ = 100 * cos(zAxisRad) * cos(xAxisRad);

		//// Update the camera position relative to the duck
		//duck.entityCamera.position.x = duck.position.x + offsetX;
		//duck.entityCamera.position.y = duck.position.y + offsetY;
		//duck.entityCamera.position.z = duck.position.z + offsetZ;

		//// Look at the duck's position
		//duck.entityCamera.target.x = duck.position.x;
		//duck.entityCamera.target.y = duck.position.y;
		//duck.entityCamera.target.z = duck.position.z;


		int mousePosX = GetMouseDelta().x;																					//Debugging 
		int mousePosY = GetMouseDelta().y;																					//Debugging
		auto mouseX = std::to_string(xAxis);																		//Debugging
		auto mouseY = std::to_string(zAxis);


		duck.movement();																								//Entity movement method
			
	 	DrawText((const char *)mouseX.c_str(), 10, GetScreenHeight() - 25, 25, DARKGRAY);								//Debugging text
		DrawText((const char*)mouseY.c_str(), 300, GetScreenHeight() - 25, 25, DARKGRAY);
		EndDrawing();
	}
	UnloadTexture(duck.entityTexture);
	UnloadModel(duck.entityModel);
	CloseWindow();
	return 0;
	
}
