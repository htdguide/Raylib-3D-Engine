#include <iostream>
#include <stdlib.h>
#include <raylib.h>
#include <string>


#ifndef gamelib
#define gamelib


typedef struct Entity {																								//Entity struct - name, model, texture2D, camera3D, vector3 position
	std::string name;																								//Entity name
	Model model;																									//Entity 3D model
	Texture2D texture;																								//Entity Texture
	Camera3D camera;																								//Entity Camera
	Vector3 position;																								//Entity Position
}Entity;

typedef struct Level {																								//Level struct - name, model, texture2D
	std::string name;																								//Level name
	Model model;																									//Level 3D model
	Texture2D texture;																								//Level Texture
}Level;

typedef struct Vehicle {																							//Vehicle struct - name, model, texture2D, camera3D, vector3 position, wheelFL, wheelFR, wheelRL, wheelRR
	std::string name;																								//Vehicle name
	Model model;																									//Vehicle 3D model
	Texture2D texture;																								//Vehicle Texture
	Camera3D camera;																								//Vehicle Camera
	Vector3 position;																								//Vehicle Position			
	Entity wheelFL;																									//Vehicle wheel
	Entity wheelFR;																									//Vehicle wheel
	Entity wheelRL;																									//Vehicle wheel
	Entity wheelRR;																									//Vehicle wheel

}Vehicle;

class actions																										//Actions class
{
	public:

		Vehicle movement(Vehicle vehicle, float speed) {															//Vehicle movement method, with the wheels
			if (IsKeyDown(KEY_A)) {
				vehicle.position.x += speed;
				vehicle.wheelFL.position.x += speed;
				vehicle.wheelFR.position.x += speed;
				vehicle.wheelRL.position.x += speed;
				vehicle.wheelRR.position.x += speed;

			}
			if (IsKeyDown(KEY_D)) {
				vehicle.position.x -= speed;
				vehicle.wheelFL.position.x -= speed;
				vehicle.wheelFR.position.x -= speed;
				vehicle.wheelRL.position.x -= speed;
				vehicle.wheelRR.position.x -= speed;
			}
			if (IsKeyDown(KEY_W)) {
				vehicle.position.z += speed;
				vehicle.wheelFL.position.z += speed;
				vehicle.wheelFR.position.z += speed;
				vehicle.wheelRL.position.z += speed;
				vehicle.wheelRR.position.z += speed;
			}
			if (IsKeyDown(KEY_S)) {
				vehicle.position.z -= speed;
				vehicle.wheelFL.position.z -= speed;
				vehicle.wheelFR.position.z -= speed;
				vehicle.wheelRL.position.z -= speed;
				vehicle.wheelRR.position.z -= speed;
			}
			return vehicle;
		}

		Entity movement(Entity entity, float speed) {																	//Entity movement method
			if (IsKeyDown(KEY_A)) {
				entity.position.x += speed;
			}
			if (IsKeyDown(KEY_D)) {
				entity.position.x -= speed;
			}
			if (IsKeyDown(KEY_W)) {
				entity.position.z += speed;
			}
			if (IsKeyDown(KEY_S)) {
				entity.position.z -= speed;
			}
			return entity;
		}
	
		Entity cameraMovementThirdPerson(Entity entity, Vector2 mousePos, float distance, float speed) {				//Method for entity camera control (Adjustable distance and speed)

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

		Vehicle cameraMovementThirdPerson(Vehicle vehicle, Vector2 mousePos, float distance, float speed) {				//Method for vehicle camera control (Adjustable distance and speed)

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
	
		Vehicle initialize(Vehicle vehicle) {																					//Initializing a vehicle, assigning textures to the models, filling camera info
			vehicle.camera = { 0 };
			vehicle.camera.position = { vehicle.position.x + 10.0f, vehicle.position.y + 10.0f, vehicle.position.z + 10.0f };	//Calculating camera position with the gap, anyway this parameter will be instantly rewritten by cameraMovementThridPerson
			vehicle.camera.target = vehicle.position;																			//Assigning at where camera looking at
			vehicle.camera.up = Vector3{ 0.0f, 1.0f, 0.0f };																	//Camera rotation axis
			vehicle.camera.fovy = 90.0f;																						//Camera FOV in degrees
			vehicle.camera.projection = CAMERA_PERSPECTIVE;																		//Camera projection
			vehicle.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = vehicle.texture;									//Assigning a texture to the model
			return vehicle;
		}
		Level initialize(Level level) {																							//Initializing a level, assigning textures to the models
			level.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = level.texture;
			return level;
		}
		Entity initialize(Entity entity) {																						//Initializing an entity, assigning textures to the models, filling camera info
			entity.camera = { 0 };																								//Creating a camera
			entity.camera.position = { entity.position.x + 10.0f, entity.position.y + 10.0f, entity.position.z + 10.0f };		//Calculating camera position with the gap, anyway this parameter will be instantly rewritten by cameraMovementThridPerson
			entity.camera.target = entity.position;																				//Assigning at where camera looking at
			entity.camera.up = Vector3{ 0.0f, 1.0f, 0.0f };																		//Camera rotation axis
			entity.camera.fovy = 90.0f;																							//Camera FOV in degrees
			entity.camera.projection = CAMERA_PERSPECTIVE;																		//Camera projection		
			entity.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = entity.texture;										//Assigning a texture to the model
			return entity;
		}

		void vehicleDraw(Vehicle vehicle, Vector3 position, float vehicleScale, float wheelScale, Color tint) {					//Draw a whole vehicle with a scale and tint
			DrawModel(vehicle.model, position, vehicleScale, tint);
			DrawModel(vehicle.wheelFL.model, vehicle.wheelFL.position, wheelScale, tint);
			DrawModel(vehicle.wheelFR.model, vehicle.wheelFR.position, wheelScale, tint);
			DrawModel(vehicle.wheelRL.model, vehicle.wheelRL.position, wheelScale, tint);
			DrawModel(vehicle.wheelRR.model, vehicle.wheelRR.position, wheelScale, tint);
		}
		void vehicleUnload(Vehicle vehicle) {																					//Unload a whole vehicle
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

#endif