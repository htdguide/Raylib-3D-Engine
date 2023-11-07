#include "raylib.h"
#include "entity.h"

using namespace std;

int mouseHandler(int x, int y) {
	if (x >= GetScreenWidth() - 1)
		SetMousePosition(GetScreenWidth() / 2, y);
	if (y >= GetScreenHeight() - 1)
		SetMousePosition(x, GetScreenHeight() / 2);
	if (x == 0)
		SetMousePosition(GetScreenWidth() / 2, y);
	if (y == 0)
		SetMousePosition(x, GetScreenHeight() / 2);
	return 0;
}

int main() {
	InitWindow(1920, 1080, "Model Loading");
	Entity duck = Entity("./assets/duck/OBJ/RubberDuck_LOD0.obj", "./assets/duck/Unity/RubberDuck_AlbedoTransparency.png", "duck", Vector3{ 0.0f, 0.0f, 0.0f });
	duck.entityModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = duck.entityTexture;

	Camera cam = { 0 };
	Vector3 campos = { 50.0f,50.0f,50.0f };
	cam.position = campos;
	cam.target = Vector3{ 0.0f, 0.0f, 0.0f };
	cam.up = Vector3{ 0.0f, 1.0f, 0.0f };
	cam.fovy = 90.0f;
	cam.projection = CAMERA_PERSPECTIVE;
	SetTargetFPS(240);
	ToggleFullscreen();
	DisableCursor();

	while (!WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) {
		BoundingBox bounds = GetMeshBoundingBox(duck.entityModel.meshes[0]);
		mouseHandler(GetMouseX(), GetMouseY());
		UpdateCamera(&cam, 4);
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(cam);
		DrawModel(duck.entityModel, duck.position, 1.0f, WHITE);
		DrawGrid(20, 10.0f);
		DrawBoundingBox(bounds, GREEN);
		EndMode3D();

		int mousePosX = GetMouseX();
		int mousePosY = GetMouseY();
		auto mouseX = std::to_string(mousePosX);
		auto mouseY = std::to_string(mousePosY);

	 	DrawText((const char *)mouseX.c_str(), 10, GetScreenHeight() - 25, 25, DARKGRAY);
		DrawText((const char*)mouseY.c_str(), 300, GetScreenHeight() - 25, 25, DARKGRAY);
		EndDrawing();
	}
		UnloadTexture(duck.entityTexture);
		UnloadModel(duck.entityModel);
		CloseWindow();
		return 0;
	
}
