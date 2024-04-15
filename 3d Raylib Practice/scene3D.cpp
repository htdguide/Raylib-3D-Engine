#include "scene3D.h"				//scene3D Header 
#include "raygui.h"					//rayGUI for the interface
#include "raylib.h"					//raylib for existance of this project
#include "gamelib.h"				//gamelib library with all of the actions
#include <cmath>					//c math
#include "trueno.h"					//trueno vehicle initialization header
#define RAYGUI_STATIC

scene3D::scene3D() {
	truenoCreator truenoCreator;
	keyboardHandler keyboard;
	interfaceHandler interfaceHandler;
	actions3D action;																														//Call an action class for library manipulations
	Camera sceneCamera = action.sceneCamera();
	Level3D map = { "racetrack", LoadModel("./assets/map/map.obj"), LoadTexture("./assets/map/material.001.png") };						//Initializing entity
	Vehicle3D trueno = truenoCreator.vehicle;
	map = action.initialize(map);

	while (!WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(sceneCamera);																										//Starting 3d with camera of the entity
		
		action.vehicleDraw(true, trueno, trueno.position, 1.0f, 0.13f, WHITE);															//Drawing the vehicle
		DrawModel(map.model, Vector3{ 0 , 0 , 0 }, 250.0f, WHITE);																		//Drawing the model

		DrawGrid(500, 10.0f);
		EndMode3D();

		trueno = keyboard.vehicleMovement(trueno);
		sceneCamera = trueno.camera;
			
		trueno = action.cameraMovementThirdPerson(trueno, GetMousePosition(), 20.0f, 1.0f);												//Updating camera position																							//Moving a camera by a mouse

		action.debugMouseXYZ(25, 25, 25);
		action.debugVehicleXYZ(trueno, 25, 100, 25);
		EndDrawing();
	}
	action.vehicleUnload(trueno);
	UnloadTexture(map.texture);
	UnloadModel(map.model);
	ShowCursor();
}