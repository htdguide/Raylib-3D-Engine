#include <iostream>
#include <stdlib.h>
#include <raylib.h>
#include <string>


class Vehicle
{
	public:
		std::string name;											//Vehicle name
		Model vehicleModel;											//Vehicle 3D model
		Texture2D vehicleTexture;									//Vehicle Texture
		Camera3D vehicleCamera;										//Vehicle Camera
		Vector3 vehiclePosition;									//Vehicle Position

		Vehicle(const char* modelpath, const char* texturepath, std::string inName, Vector3 inPos);				//Vehicle constructor

		void movement() {																										//Entity movement method
			if (IsKeyDown(KEY_A)) {
				vehiclePosition.x += 0.5f;
			}
			if (IsKeyDown(KEY_D)) {
				vehiclePosition.x -= 0.5f;
			}
			if (IsKeyDown(KEY_W)) {
				vehiclePosition.z += 0.5f;
			}
			if (IsKeyDown(KEY_S)) {
				vehiclePosition.z -= 0.5f;
			}
		}

		void cameraMovementThirdPerson(Vector2 mousePos, float distance, float speed) {											//Method for camera control (Adjustable distance and speed)

			float xAngle = mousePos.x / (GetScreenWidth() / 360.0f);																//Getting angle values from the screen width
			if (mousePos.y == 0) mousePos.y++;																					//Removing 0 from the upcoming formula
			float zAngle = mousePos.y / (GetScreenHeight() / 180.0f);																//Getting angle values from the screen height and applying aspect ratio


			zAngle -= 90.0f;

			float xAxisRad = -(xAngle * PI) / 180.0f;
			float zAxisRad = -(zAngle * PI) / 180.0f;

			// Calculate the new position relative to the duck's position
			float offsetX = distance * cos(zAxisRad) * sin(xAxisRad);
			float offsetY = distance * sin(zAxisRad);
			float offsetZ = distance * cos(zAxisRad) * cos(xAxisRad);

			// Update the camera position relative to the duck
			vehicleCamera.position.x = vehiclePosition.x + offsetX;
			vehicleCamera.position.y = vehiclePosition.y + offsetY;
			vehicleCamera.position.z = vehiclePosition.z + offsetZ;

			// Look at the duck's position
			vehicleCamera.target.x = vehiclePosition.x;
			vehicleCamera.target.y = vehiclePosition.y;
			vehicleCamera.target.z = vehiclePosition.z;

			if (GetMouseX() >= GetScreenWidth() - 1) SetMousePosition(1, GetMouseY());											// Cycling mouse movement if it reach the bounds
			if (GetMouseX() == 0)	SetMousePosition(GetScreenWidth(), GetMouseY());											// Cycling mouse movement if it reach the bounds
			if (!IsCursorHidden()) HideCursor();																				// Hiding the cursor
		}
};

