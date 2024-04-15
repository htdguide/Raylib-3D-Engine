#include <iostream>
#include <stdlib.h>
#include <raylib.h>
#include <string>
//#include "raygui.h"

#ifndef gamelib
#define gamelib


typedef struct Entity3D {																							//Entity struct - name, model, texture2D, camera3D, vector3 position
	std::string name;																								//Entity name
	Model model;																									//Entity 3D model
	Texture2D texture;																								//Entity Texture
	Camera3D camera;																								//Entity Camera
	Vector3 position;																								//Entity Position
	BoundingBox boundingBox;																						//Bounding Box
}Entity;

typedef struct Level3D {																							//Level struct - name, model, texture2D
	std::string name;																								//Level name
	Model model;																									//Level 3D model
	Texture2D texture;																								//Level Texture
	BoundingBox boundingBox;																						//Bounding Box
}Level;

typedef struct Vehicle3D {																							//Vehicle struct - name, model, texture2D, camera3D, vector3 position, wheelFL, wheelFR, wheelRL, wheelRR
	std::string name;																								//Vehicle name
	Model model;																									//Vehicle 3D model
	Texture2D texture;																								//Vehicle Texture
	Camera3D camera;																								//Vehicle Camera
	Vector3 position;																								//Vehicle Position			
	Entity3D wheelFL;																								//Vehicle wheel
	Entity3D wheelFR;																								//Vehicle wheel
	Entity3D wheelRL;																								//Vehicle wheel
	Entity3D wheelRR;																								//Vehicle wheel
	BoundingBox boundingBox;																						//Bounding Box
}Vehicle;

class actions3D																										//Actions class
{
	public:

		void debugMouseXYZ(int x, int y, int size) {																//Debug coordinates of the mouse on the screen					
			int mousePosX = GetMousePosition().x;																	//Debugging 
			int mousePosY = GetMousePosition().y;																	//Debugging
			auto mouseX = std::to_string(mousePosX);																//Debugging
			auto mouseY = std::to_string(mousePosY);
			DrawText((const char*)mouseX.c_str(), x, y, size, DARKGRAY);											//Debugging text
			DrawText((const char*)mouseY.c_str(), 300 + x, y, size, DARKGRAY);
		}
		void debugVehicleXYZ(Vehicle3D vehicle, int x, int y, int size) {											//Debug coordinates of the vehicle
			auto posX = std::to_string(vehicle.position.x);															//Debugging
			auto posY = std::to_string(vehicle.position.z);
			DrawText((const char*)posX.c_str(), x, y, 25, DARKGRAY);												//Debugging text
			DrawText((const char*)posY.c_str(), 300 + x, y, size, DARKGRAY);
		}

		Camera sceneCamera() {
			Camera camera = { 0 };
			camera.position = { 10.0f, 10.0f, 10.0f };																// Camera position
			camera.target = { 0.0f, 0.0f, 0.0f };																	// Camera looking at point
			camera.up = { 0.0f, 1.0f, 0.0f };																		// Camera up vector (rotation towards target)
			camera.fovy = 90.0f;																					// Camera field-of-view Y
			camera.projection = CAMERA_PERSPECTIVE;																	// Camera projection type
			return camera;
		}


		Vehicle3D movementXZ(Vehicle3D vehicle, float speed, char direction) {										//Vehicle movement method, directions are 'l' 'r' 'u' 'd' (Left, Right, Up and Down)
			if (direction == 'l') {
				vehicle.position.x += speed;
				vehicle.wheelFL.position.x += speed;
				vehicle.wheelFR.position.x += speed;
				vehicle.wheelRL.position.x += speed;
				vehicle.wheelRR.position.x += speed;
				vehicle.boundingBox.min.x += speed;
				vehicle.boundingBox.max.x += speed;
			}
			if (direction == 'r') {
				vehicle.position.x -= speed;
				vehicle.wheelFL.position.x -= speed;
				vehicle.wheelFR.position.x -= speed;
				vehicle.wheelRL.position.x -= speed;
				vehicle.wheelRR.position.x -= speed;
				vehicle.boundingBox.min.x -= speed;
				vehicle.boundingBox.max.x -= speed;
			}
			if (direction == 'u') {
				vehicle.position.z += speed;
				vehicle.wheelFL.position.z += speed;
				vehicle.wheelFR.position.z += speed;
				vehicle.wheelRL.position.z += speed;
				vehicle.wheelRR.position.z += speed;
				vehicle.boundingBox.min.z += speed;
				vehicle.boundingBox.max.z += speed;
			}
			if (direction == 'd') {
				vehicle.position.z -= speed;
				vehicle.wheelFL.position.z -= speed;
				vehicle.wheelFR.position.z -= speed;
				vehicle.wheelRL.position.z -= speed;
				vehicle.wheelRR.position.z -= speed;
				vehicle.boundingBox.min.z -= speed;
				vehicle.boundingBox.max.z -= speed;
			}
			
			return vehicle;
		}

		Entity3D movementXZ(Entity3D entity, float speed, char direction) {													//Entity movement method, directions are 'l' 'r' 'u' 'd' (Left, Right, Up and Down)
			if (direction == 'l') {
				entity.position.x += speed;
				entity.boundingBox.min.x += speed;
				entity.boundingBox.max.x += speed;
			}
			if (direction == 'r') {
				entity.position.x -= speed;
				entity.boundingBox.min.x -= speed;
				entity.boundingBox.max.x -= speed;
			}
			if (direction == 'u') {
				entity.position.z += speed;
				entity.boundingBox.min.z += speed;
				entity.boundingBox.max.z += speed;
			}
			if (direction == 'd') {
				entity.position.z -= speed;
				entity.boundingBox.min.z -= speed;
				entity.boundingBox.max.z -= speed;
			}
			return entity;
		}
	
		Entity3D cameraMovementThirdPerson(Entity3D entity, Vector2 mousePos, float distance, float speed) {			//Method for entity camera control (Adjustable distance and speed)

			float xAngle = mousePos.x / (GetScreenWidth() / 360.0f);													//Getting angle values from the screen width
			if (mousePos.y == 0) mousePos.y++;																			//Removing 0 from the upcoming formula
			float zAngle = mousePos.y / (GetScreenHeight() / 180.0f);													//Getting angle values from the screen height and applying aspect ratio

			zAngle -= 90.0f;																							//Removing half of the degrees to spawn a camera looking forward

			float xAxisRad = -(xAngle * PI) / 180.0f;																	//Calculating radians
			float zAxisRad = -(zAngle * PI) / 180.0f;																	//Calculating radians

			float offsetX = distance * cos(zAxisRad) * sin(xAxisRad);													//Calculate the offset coordinates, point on the surface of the sphere
			float offsetY = distance * sin(zAxisRad);																	//Calculate the offset coordinates, point on the surface of the sphere
			float offsetZ = distance * cos(zAxisRad) * cos(xAxisRad);													//Calculate the offset coordinates, point on the surface of the sphere

			entity.camera.position.x = entity.position.x + offsetX;														//Update the camera position relative to the entity by adding the offset
			entity.camera.position.y = entity.position.y + offsetY;														//Update the camera position relative to the entity by adding the offset
			entity.camera.position.z = entity.position.z + offsetZ;														//Update the camera position relative to the entity by adding the offset

			entity.camera.target.x = entity.position.x;																	//Look at the entity's position
			entity.camera.target.y = entity.position.y;																	//Look at the entity's position
			entity.camera.target.z = entity.position.z;																	//Look at the entity's position

			if (GetMouseX() >= GetScreenWidth() - 1) SetMousePosition(1, GetMouseY());									// Cycling mouse movement if it reach the bounds
			if (GetMouseX() == 0)	SetMousePosition(GetScreenWidth(), GetMouseY());									// Cycling mouse movement if it reach the bounds
			if (!IsCursorHidden()) HideCursor();																		// Hiding the cursor
			return entity;
		}

		Vehicle3D cameraMovementThirdPerson(Vehicle3D vehicle, Vector2 mousePos, float distance, float speed) {			//Method for vehicle camera control (Adjustable distance and speed)

			float xAngle = mousePos.x / (GetScreenWidth() / 360.0f);													//Getting angle values from the screen width
			if (mousePos.y == 0) mousePos.y++;																			//Removing 0 from the upcoming formula
			float zAngle = mousePos.y / (GetScreenHeight() / 180.0f);													//Getting angle values from the screen height and applying aspect ratio

			zAngle -= 90.0f;																							//Removing half of the degrees to spawn a camera looking forward

			float xAxisRad = -(xAngle * PI) / 180.0f;																	//Calculating radians
			float zAxisRad = -(zAngle * PI) / 180.0f;																	//Calculating radians

			float offsetX = distance * cos(zAxisRad) * sin(xAxisRad);													//Calculate the offset coordinates, point on the surface of the sphere
			float offsetY = distance * sin(zAxisRad);																	//Calculate the offset coordinates, point on the surface of the sphere
			float offsetZ = distance * cos(zAxisRad) * cos(xAxisRad);													//Calculate the offset coordinates, point on the surface of the sphere
	
			vehicle.camera.position.x = vehicle.position.x + offsetX;													//Update the camera position relative to the vehicle by adding the offset
			vehicle.camera.position.y = vehicle.position.y + offsetY;													//Update the camera position relative to the vehicle by adding the offset
			vehicle.camera.position.z = vehicle.position.z + offsetZ;													//Update the camera position relative to the vehicle by adding the offset

			vehicle.camera.target.x = vehicle.position.x;																//Look at the entity's position
			vehicle.camera.target.y = vehicle.position.y;																//Look at the entity's position
			vehicle.camera.target.z = vehicle.position.z;																//Look at the entity's position

			if (GetMouseX() >= GetScreenWidth() - 1) SetMousePosition(1, GetMouseY());									// Cycling mouse movement if it reach the bounds
			if (GetMouseX() == 0)	SetMousePosition(GetScreenWidth(), GetMouseY());									// Cycling mouse movement if it reach the bounds
			if (!IsCursorHidden()) HideCursor();																		// Hiding the cursor
			return vehicle;
		}
	
		Vehicle3D initialize(Vehicle3D vehicle) {																				//Initializing a vehicle, assigning textures to the models, filling camera info
			vehicle.camera = { 0 };
			vehicle.camera.position = { vehicle.position.x + 10.0f, vehicle.position.y + 10.0f, vehicle.position.z + 10.0f };	//Calculating camera position with the gap, anyway this parameter will be instantly rewritten by cameraMovementThridPerson
			vehicle.camera.target = vehicle.position;																			//Assigning at where camera looking at
			vehicle.camera.up = Vector3{ 0.0f, 1.0f, 0.0f };																	//Camera rotation axis
			vehicle.camera.fovy = 90.0f;																						//Camera FOV in degrees
			vehicle.camera.projection = CAMERA_PERSPECTIVE;																		//Camera projection
			vehicle.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = vehicle.texture;									//Assigning a texture to the model
			vehicle.boundingBox = GetMeshBoundingBox(vehicle.model.meshes[0]);													//Assigning bounding box from the mesh
			return vehicle;
		}
		Level3D initialize(Level3D level) {																						//Initializing a level
			level.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = level.texture;										//Assigning textures to the models
			level.boundingBox = GetMeshBoundingBox(level.model.meshes[0]);														//Assigning bounding box from the mesh
			return level;
		}
		Entity3D initialize(Entity3D entity) {																					//Initializing an entity, assigning textures to the models, filling camera info
			entity.camera = { 0 };																								//Creating a camera
			entity.camera.position = { entity.position.x + 10.0f, entity.position.y + 10.0f, entity.position.z + 10.0f };		//Calculating camera position with the gap, anyway this parameter will be instantly rewritten by cameraMovementThridPerson
			entity.camera.target = entity.position;																				//Assigning at where camera looking at
			entity.camera.up = Vector3{ 0.0f, 1.0f, 0.0f };																		//Camera rotation axis
			entity.camera.fovy = 90.0f;																							//Camera FOV in degrees
			entity.camera.projection = CAMERA_PERSPECTIVE;																		//Camera projection		
			entity.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = entity.texture;										//Assigning a texture to the model
			entity.boundingBox = GetMeshBoundingBox(entity.model.meshes[0]);													//Assigning bounding box from the mesh
			return entity;
		}

		void vehicleDraw(bool bBox, Vehicle3D vehicle, Vector3 position, float vehicleScale, float wheelScale, Color tint) {	//Draw the whole vehicle with a scale and tint. Boolean for the boundingbox
			DrawModel(vehicle.model, position, vehicleScale, tint);
			DrawModel(vehicle.wheelFL.model, vehicle.wheelFL.position, wheelScale, tint);
			DrawModel(vehicle.wheelFR.model, vehicle.wheelFR.position, wheelScale, tint);
			DrawModel(vehicle.wheelRL.model, vehicle.wheelRL.position, wheelScale, tint);
			DrawModel(vehicle.wheelRR.model, vehicle.wheelRR.position, wheelScale, tint);
			if (bBox) DrawBoundingBox(vehicle.boundingBox, GREEN);
		}
		void vehicleUnload(Vehicle3D vehicle) {																					//Unload the whole vehicle
			UnloadTexture(vehicle.texture);
			UnloadModel(vehicle.model);
			UnloadTexture(vehicle.wheelFL.texture);
			UnloadTexture(vehicle.wheelFR.texture);
			UnloadTexture(vehicle.wheelRL.texture);
			UnloadTexture(vehicle.wheelRR.texture);
			UnloadModel(vehicle.wheelFL.model);
			UnloadModel(vehicle.wheelFR.model);
			UnloadModel(vehicle.wheelRL.model);
			UnloadModel(vehicle.wheelRR.model);
		}
	
};

class keyboardHandler																											//Keyboard handler class to handle input from the keyboard
{
	public:
		actions3D action;																										//Initializing main class with actions
		Vehicle3D vehicleMovement(Vehicle3D vehicle) {
			if (IsKeyDown(KEY_A)) vehicle = action.movementXZ(vehicle, 0.1f, 'l');
			if (IsKeyDown(KEY_D)) vehicle = action.movementXZ(vehicle, 0.1f, 'r');
			if (IsKeyDown(KEY_W)) vehicle = action.movementXZ(vehicle, 0.1f, 'u');
			if (IsKeyDown(KEY_S)) vehicle = action.movementXZ(vehicle, 0.1f, 'd');
			return vehicle;
		}
};

class interfaceHandler
{
	public:
		actions3D action;

		void console() {
			//GuiLabel(Rectangle{ 20, 20, 20, 20 }, "hello");
		}
};

#endif