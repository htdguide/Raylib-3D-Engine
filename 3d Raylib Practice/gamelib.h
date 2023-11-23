#include <iostream>
#include <stdlib.h>
#include <raylib.h>
#include <string>


typedef struct Level {
	std::string name;																								//Level name
	Model model;																									//Level 3D model
	Texture2D texture;																								//Level Texture
}Level;

typedef struct Vehicle {
	std::string name;																								//Vehicle name
	Model model;																									//Vehicle 3D model
	Texture2D texture;																								//Vehicle Texture
	Camera3D camera;																								//Vehicle Camera
	Vector3 position;																								//Vehicle Position																				//Level Texture
}Vehicle;

typedef struct Entity {
	std::string name;																								//Entity name
	Model model;																									//Entity 3D model
	Texture2D texture;																								//Entity Texture
	Camera3D camera;																								//Entity Camera
	Vector3 position;
}Entity;

class actions																										//Actions class
{
	public:

		Vehicle movement(Vehicle vehicle) {																				//Vehicle movement method
			if (IsKeyDown(KEY_A)) {
				vehicle.position.x += 0.5f;
			}
			if (IsKeyDown(KEY_D)) {
				vehicle.position.x -= 0.5f;
			}
			if (IsKeyDown(KEY_W)) {
				vehicle.position.z += 0.5f;
			}
			if (IsKeyDown(KEY_S)) {
				vehicle.position.z -= 0.5f;
			}
			return vehicle;
		}

		Entity movement(Entity entity) {																				//Entity movement method
			if (IsKeyDown(KEY_A)) {
				entity.position.x += 0.5f;
			}
			if (IsKeyDown(KEY_D)) {
				entity.position.x -= 0.5f;
			}
			if (IsKeyDown(KEY_W)) {
				entity.position.z += 0.5f;
			}
			if (IsKeyDown(KEY_S)) {
				entity.position.z -= 0.5f;
			}
			return entity;
		}
	
		Entity cameraMovementThirdPerson(Entity entity, Vector2 mousePos, float distance, float speed) {				//Method for entity camera control (Adjustable distance and speed)

			float xAngle = mousePos.x / (GetScreenWidth() / 360.0f);													//Getting angle values from the screen width
			if (mousePos.y == 0) mousePos.y++;																			//Removing 0 from the upcoming formula
			float zAngle = mousePos.y / (GetScreenHeight() / 180.0f);													//Getting angle values from the screen height and applying aspect ratio


			zAngle -= 90.0f;

			float xAxisRad = -(xAngle * PI) / 180.0f;
			float zAxisRad = -(zAngle * PI) / 180.0f;

			// Calculate the new position relative to the duck's position
			float offsetX = distance * cos(zAxisRad) * sin(xAxisRad);
			float offsetY = distance * sin(zAxisRad);
			float offsetZ = distance * cos(zAxisRad) * cos(xAxisRad);

			// Update the camera position relative to the duck
			entity.camera.position.x = entity.position.x + offsetX;
			entity.camera.position.y = entity.position.y + offsetY;
			entity.camera.position.z = entity.position.z + offsetZ;

			// Look at the duck's position
			entity.camera.target.x = entity.position.x;
			entity.camera.target.y = entity.position.y;
			entity.camera.target.z = entity.position.z;

			if (GetMouseX() >= GetScreenWidth() - 1) SetMousePosition(1, GetMouseY());									// Cycling mouse movement if it reach the bounds
			if (GetMouseX() == 0)	SetMousePosition(GetScreenWidth(), GetMouseY());									// Cycling mouse movement if it reach the bounds
			if (!IsCursorHidden()) HideCursor();																		// Hiding the cursor
			return entity;
		}

		Vehicle cameraMovementThirdPerson(Vehicle vehicle, Vector2 mousePos, float distance, float speed) {				//Method for vehicle camera control (Adjustable distance and speed)

			float xAngle = mousePos.x / (GetScreenWidth() / 360.0f);													//Getting angle values from the screen width
			if (mousePos.y == 0) mousePos.y++;																			//Removing 0 from the upcoming formula
			float zAngle = mousePos.y / (GetScreenHeight() / 180.0f);													//Getting angle values from the screen height and applying aspect ratio


			zAngle -= 90.0f;

			float xAxisRad = -(xAngle * PI) / 180.0f;
			float zAxisRad = -(zAngle * PI) / 180.0f;

			// Calculate the new position relative to the duck's position
			float offsetX = distance * cos(zAxisRad) * sin(xAxisRad);
			float offsetY = distance * sin(zAxisRad);
			float offsetZ = distance * cos(zAxisRad) * cos(xAxisRad);

			// Update the camera position relative to the duck
			vehicle.camera.position.x = vehicle.position.x + offsetX;
			vehicle.camera.position.y = vehicle.position.y + offsetY;
			vehicle.camera.position.z = vehicle.position.z + offsetZ;

			// Look at the duck's position
			vehicle.camera.target.x = vehicle.position.x;
			vehicle.camera.target.y = vehicle.position.y;
			vehicle.camera.target.z = vehicle.position.z;

			if (GetMouseX() >= GetScreenWidth() - 1) SetMousePosition(1, GetMouseY());									// Cycling mouse movement if it reach the bounds
			if (GetMouseX() == 0)	SetMousePosition(GetScreenWidth(), GetMouseY());									// Cycling mouse movement if it reach the bounds
			if (!IsCursorHidden()) HideCursor();																		// Hiding the cursor
			return vehicle;
		}
	
		Vehicle initialize(Vehicle vehicle) {
			vehicle.camera = { 0 };
			vehicle.camera.position = { vehicle.position.x + 10.0f, vehicle.position.y + 10.0f, vehicle.position.z + 10.0f }; //Calculating camera position with the gap, anyway this parameter will be instantly rewritten by cameraMovementThridPerson
			vehicle.camera.target = vehicle.position;																	//Assigning at where camera looking at
			vehicle.camera.up = Vector3{ 0.0f, 1.0f, 0.0f };															//Camera rotation axis
			vehicle.camera.fovy = 90.0f;					
			vehicle.camera.projection = CAMERA_PERSPECTIVE;	//Camera FOV
			vehicle.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = vehicle.texture;
			return vehicle;
		}
		Level initialize(Level level) {
			level.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = level.texture;
			return level;
		}
		Entity initialize(Entity entity) {
			entity.camera = { 0 };
			entity.camera.position = { entity.position.x + 10.0f, entity.position.y + 10.0f, entity.position.z + 10.0f }; //Calculating camera position with the gap, anyway this parameter will be instantly rewritten by cameraMovementThridPerson
			entity.camera.target = entity.position;																	//Assigning at where camera looking at
			entity.camera.up = Vector3{ 0.0f, 1.0f, 0.0f };															//Camera rotation axis
			entity.camera.fovy = 90.0f;
			entity.camera.projection = CAMERA_PERSPECTIVE;	//Camera FOV
			entity.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = entity.texture;
			return entity;
		}
	
};