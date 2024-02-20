#include "gamelib.h"
#include <raylib.h>
#include <cmath>

class truenoCreator{																									//Initializing exact trueno car, all of the models abd textures are here
public:
	Vehicle vehicle;
	truenoCreator() {
		actions action;

		//Creating 4 Entities which are the wheels
		Entity wheelFL{ "wheelFL", LoadModel("./assets/wheel/wheel.obj"), LoadTexture("./assets/wheel/texturealbedo.png"), Camera3D{}, Vector3{} };			//Entity constructor
		Entity wheelFR{ "wheelFR", LoadModel("./assets/wheel/wheelR.obj"), LoadTexture("./assets/wheel/texturealbedo.png"), Camera3D{}, Vector3{} };		//Entity constructor
		Entity wheelRR{ "wheelRR", LoadModel("./assets/wheel/wheelR.obj"), LoadTexture("./assets/wheel/texturealbedo.png"), Camera3D{}, Vector3{} };		//Entity constructor
		Entity wheelRL{ "wheelRL", LoadModel("./assets/wheel/wheel.obj"), LoadTexture("./assets/wheel/texturealbedo.png"), Camera3D{}, Vector3{} };			//Entity constructor


		//Creating a Vehicle with the wheels
		vehicle = { "Trueno", LoadModel("./assets/ae86/ToyotaAE86.obj"), LoadTexture("./assets/ae86/textures/Palette.png"), Camera3D{0}, Vector3{ 0.0f, 1.0f, 0.0f }, wheelFL, wheelFR, wheelRL, wheelRR }; //Vehicle constructor

		//Coordinates for the wheels
		vehicle.wheelFL.position = Vector3{ vehicle.position.x + 3.5f, vehicle.position.y, vehicle.position.z + 5.0f };										//Relative positioning of the wheel
		vehicle.wheelFR.position = Vector3{ vehicle.position.x - 3.0f, vehicle.position.y, vehicle.position.z + 5.0f };										//Relative positioning of the wheel
		vehicle.wheelRR.position = Vector3{ vehicle.position.x - 3.0f, vehicle.position.y, vehicle.position.z - 5.4f };										//Relative positioning of the wheel
		vehicle.wheelRL.position = Vector3{ vehicle.position.x + 3.5f, vehicle.position.y, vehicle.position.z - 5.4f };										//Relative positioning of the wheel

		//Initializing via action class
		vehicle = action.initialize(vehicle);																												//Initializing a vehicle, assigning textures to the models, filling camera info
		vehicle.wheelFL = action.initialize(vehicle.wheelFL);																								//Initializing an entity, assigning textures to the models, filling camera info
		vehicle.wheelFR = action.initialize(vehicle.wheelFR);																								//Initializing an entity, assigning textures to the models, filling camera info
		vehicle.wheelRL = action.initialize(vehicle.wheelRL);																								//Initializing an entity, assigning textures to the models, filling camera info
		vehicle.wheelRR = action.initialize(vehicle.wheelRR);																								//Initializing an entity, assigning textures to the models, filling camera info

	}
};

