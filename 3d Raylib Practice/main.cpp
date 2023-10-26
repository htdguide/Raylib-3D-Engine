#include "raylib.h"
Camera cameramovement(Camera cam) {
	cam.target.x = GetMousePosition().x;
	cam.target.y = GetMousePosition().y;
	return cam;
}
int main() {
	InitWindow(1280, 720, "Model Loading");
	Model duck = LoadModel("./assets/duck/OBJ/RubberDuck_LOD0.obj");
	Texture2D tex = LoadTexture("./assets/duck/Unity/RubberDuck_AlbedoTransparency.png");
	duck.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = tex;

	Camera cam = { 0 };
	cam.position = Vector3 { 50.0f,50.0f,50.0f };
	cam.target = Vector3{ 0.0f, 0.0f, 0.0f };
	cam.up = Vector3{ 0.0f, 1.0f, 0.0f };
	cam.fovy = 90.0f;
	cam.projection = CAMERA_PERSPECTIVE;

	Vector3 pos = { 0.0f, 0.0f, 0.0f };
	BoundingBox bounds = GetMeshBoundingBox(duck.meshes[0]);

	SetTargetFPS(60);
	

	while (!WindowShouldClose()) {
		UpdateCamera(&cam, CAMERA_THIRD_PERSON);
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(cam);
		DrawModel(duck, pos, 1.0f, WHITE);
		DrawGrid(20, 10.0f);
		DrawBoundingBox(bounds, GREEN);
		EndMode3D();
		DrawText("Loading obj file", 10, GetScreenHeight() - 25, 25, DARKGRAY);
		EndDrawing();
		if (IsKeyDown(KEY_D))
			cam.position.x++;
		if (IsKeyDown(KEY_A))
			cam.position.x--;
		if (IsKeyDown(KEY_S))
			cam.position.z++;
		if (IsKeyDown(KEY_W))
			cam.position.z--;
		//cam = cameramovement(cam);
	}
		UnloadTexture(tex);
		UnloadModel(duck);
		CloseWindow();
		return 0;	
}
