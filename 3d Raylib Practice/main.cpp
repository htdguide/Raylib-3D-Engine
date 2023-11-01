#include "raylib.h"
#include "entity.h"



Camera cameramovement(Camera cam) {
	cam.target.x = GetMousePosition().x;
	cam.target.y = GetMousePosition().y;
	
	return cam;
}
int main() {
	InitWindow(1280, 720, "Model Loading");
	Entity duck = Entity("./assets/duck/OBJ/RubberDuck_LOD0.obj", "./assets/duck/Unity/RubberDuck_AlbedoTransparency.png", "duck");
	duck.entityModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = duck.entityTexture;

	Camera cam = { 0 };
	cam.position = Vector3 { 50.0f,50.0f,50.0f };
	cam.target = Vector3{ 0.0f, 0.0f, 0.0f };
	cam.up = Vector3{ 0.0f, 1.0f, 0.0f };
	cam.fovy = 90.0f;
	cam.projection = CAMERA_PERSPECTIVE;

	Vector3 pos = { 0.0f, 0.0f, 0.0f };

	SetTargetFPS(60);
	

	while (!WindowShouldClose()) {
		BoundingBox bounds = GetMeshBoundingBox(duck.entityModel.meshes[0]);
		UpdateCamera(&cam, CAMERA_THIRD_PERSON);
	
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(cam);
		DrawModel(duck.entityModel, pos, 1.0f, WHITE);
		DrawGrid(20, 10.0f);
		DrawBoundingBox(bounds, GREEN);
		EndMode3D();
		DrawText("Loading obj file", 10, GetScreenHeight() - 25, 25, DARKGRAY);
		EndDrawing();
		if (IsKeyDown(KEY_D))
			pos.x++;
		if (IsKeyDown(KEY_A))
			pos.x--;
		if (IsKeyDown(KEY_S))
			pos.z++;
		if (IsKeyDown(KEY_W))
			pos.z--;
	}
		UnloadTexture(duck.entityTexture);
		UnloadModel(duck.entityModel);
		CloseWindow();
		return 0;	
}
