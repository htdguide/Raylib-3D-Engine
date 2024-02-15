#include "scene3D.h"
#include "raylib.h"
#include "gamelib.h"
#include <cmath>
#include "trueno.h"
#define RAYGUI_IMPLEMENTATION
#include "C:\Users\mogil\source\repos\htdguide\3d-Raylib-Practice\raylib-4.5.0_win64_msvc16\raygui-master\src\raygui.h"

scene3D::scene3D() {

	actions action;																																																															//Call an action class for library manipulations
	Camera sceneCamera = action.sceneCamera();
	Level map = { "racetrack", LoadModel("./assets/map/map.obj"), LoadTexture("./assets/map/material.001.png") };																//Initializing entity
	truenoVehicleCreator truenoCreator = truenoVehicleCreator();
	Vehicle trueno = truenoCreator.vehicle;
	map = action.initialize(map);


	while (!WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(sceneCamera);																																				//Starting 3d with camera of the entity
		
		action.vehicleDraw(true, trueno, trueno.position, 1.0f, 0.13f, WHITE);
		DrawModel(map.model, Vector3{ 0 , 0 , 0 }, 250.0f, WHITE);																												//Drawing a model

		DrawGrid(500, 10.0f);
		EndMode3D();

		sceneCamera = trueno.camera;
			
		trueno = action.cameraMovementThirdPerson(trueno, GetMousePosition(), 20.0f, 1.0f);																					//Updating camera position																							//Moving a camera by a mouse

		action.debugMouseXYZ(25, 25, 25);
		action.debugVehicleXYZ(trueno, 25, 100, 25);

		//trueno = action.movementXZ(trueno, 0.1f, 'l');																																	//Entity movement method
		EndDrawing();
		//UpdateCamera(&sceneCamera, CAMERA_FIRST_PERSON);
	}
	action.vehicleUnload(trueno);
	UnloadTexture(map.texture);
	UnloadModel(map.model);

	CloseWindow();
}