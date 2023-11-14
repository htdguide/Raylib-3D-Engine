#pragma once
#include <iostream>
#include <stdlib.h>
#include <raylib.h>
#include <string>

class Entity
{
	public:
		std::string name;								   //Entity name
		Model entityModel;									//Entity 3D model
		Texture2D entityTexture;							//Entity Texture
		Camera3D entityCamera;								//Entity Camera
		Vector3 entityPosition;									//Entity Position
		Vector3 camgap = { 50.0f,50.0f,50.0f };				//Entity Camera Gap from the position
		
		Entity(const char* modelpath, const char* texturepath, std::string inName, Vector3 inPos); //Contructor header [modelpath, texturepath, name, position]

		void cameraSync() {									//Camera syncronising with the model method
			entityCamera.position = { entityPosition.x + camgap.x, entityPosition.y + camgap.y, entityPosition.z + camgap.z };
			entityCamera.target = entityPosition;
		}

		void movement() {									//Entity movement method
			if (IsKeyDown(KEY_W)) {
				entityPosition.x++;
			}
			if (IsKeyDown(KEY_S)) {
				entityPosition.x--;
			}
			if (IsKeyDown(KEY_D)) {
				entityPosition.z++;
			}
			if (IsKeyDown(KEY_A)) {
				entityPosition.z--;
			}
		}

		void cameraMovementThirdPerson(Vector2 mousePos, float distance, float speed) { //Method for camera control (Adjustable distance and speed)

			float xAngle = mousePos.x / (GetScreenWidth()/360.0f);									//Getting angle values from the screen width
			if (mousePos.y == 0) mousePos.y++;														//Removing 0 from the upcoming formula
			float zAngle = mousePos.y / (GetScreenHeight()/180.0f);									//Getting angle values from the screen height and applying aspect ratio

			
			zAngle -= 90.0f;

			float xAxisRad = -(xAngle * PI) / 180.0f;
			float zAxisRad = -(zAngle * PI) / 180.0f;

																									// Calculate the new position relative to the duck's position
			float offsetX = distance * cos(zAxisRad) * sin(xAxisRad);
			float offsetY = distance * sin(zAxisRad);
			float offsetZ = distance * cos(zAxisRad) * cos(xAxisRad);

																									// Update the camera position relative to the duck
			entityCamera.position.x = entityPosition.x + offsetX;
			entityCamera.position.y = entityPosition.y + offsetY;
			entityCamera.position.z = entityPosition.z + offsetZ;

																									// Look at the duck's position
			entityCamera.target.x = entityPosition.x;
			entityCamera.target.y = entityPosition.y;
			entityCamera.target.z = entityPosition.z;
		}
};


