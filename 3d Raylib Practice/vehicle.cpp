#include "Vehicle.h"

Vehicle::Vehicle(const char* modelpath, const char* texturepath, std::string inName, Vector3 inPos)
{
	vehicleModel = LoadModel(modelpath);
	vehicleTexture = LoadTexture(texturepath);
	name = inName;
	vehiclePosition = inPos;
	vehicleCamera = { 0 };																										//Assigning the Camera3D
	vehicleCamera.position = { vehiclePosition.x + 10.0f, vehiclePosition.y + 10.0f, vehiclePosition.z + 10.0f };					//Calculating camera position with the gap, anyway this parameter will be instantly rewritten by cameraMovementThridPerson
	vehicleCamera.target = vehiclePosition;																						//Assigning at where camera looking at
	vehicleCamera.up = Vector3{ 0.0f, 1.0f, 0.0f };																				//Camera rotation axis
	vehicleCamera.fovy = 90.0f;																									//Camera FOV
	vehicleCamera.projection = CAMERA_PERSPECTIVE;																				//Camera projection from raylib
}
