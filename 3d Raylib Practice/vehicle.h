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
	Vector3 camgap = { 50.0f, 50.0f ,50.0f };					//Vehicle Camera Gap from the position

	//Vehicle(const char* modelpath, const char* texturepath, std::string inName, Vector3 inPos);
};

