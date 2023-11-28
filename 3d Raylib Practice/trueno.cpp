#include "trueno.h"

truenoVehicleCreator::truenoVehicleCreator() {
	actions action;

	Entity wheelFL{ "wheelFL", LoadModel("./assets/wheel/wheel.obj"), LoadTexture("./assets/wheel/texturealbedo.png"), Camera3D{}, Vector3{} };
	Entity wheelFR{ "wheelFR", LoadModel("./assets/wheel/wheel.obj"), LoadTexture("./assets/wheel/texturealbedo.png"), Camera3D{}, Vector3{} };
	Entity wheelRL{ "wheelRL", LoadModel("./assets/wheel/wheel.obj"), LoadTexture("./assets/wheel/texturealbedo.png"), Camera3D{}, Vector3{} };
	Entity wheelRR{ "wheelRR", LoadModel("./assets/wheel/wheel.obj"), LoadTexture("./assets/wheel/texturealbedo.png"), Camera3D{}, Vector3{} };

	vehicle = Vehicle { "Trueno", LoadModel("./assets/ae86/ToyotaAE86.obj"), LoadTexture("./assets/ae86/textures/Palette.png"), Camera3D{0}, Vector3{ 0.0f, 1.0f, 0.0f }, wheelFL, wheelFR, wheelRL, wheelRR };

	vehicle.wheelFL.position = Vector3{ vehicle.position.x + 3.5f, vehicle.position.y, vehicle.position.z + 5.0f };
	vehicle.wheelFR.position = Vector3{ vehicle.position.x - 3.0f, vehicle.position.y, vehicle.position.z + 5.0f };
	vehicle.wheelRL.position = Vector3{ vehicle.position.x - 3.0f, vehicle.position.y, vehicle.position.z - 5.4f };
	vehicle.wheelRR.position = Vector3{ vehicle.position.x + 3.5f, vehicle.position.y, vehicle.position.z - 5.4f };

	
	vehicle = action.initialize(vehicle);
	vehicle.wheelFL = action.initialize(vehicle.wheelFL);
	vehicle.wheelFR = action.initialize(vehicle.wheelFR);
	vehicle.wheelRL = action.initialize(vehicle.wheelRL);
	vehicle.wheelRR = action.initialize(vehicle.wheelRR);
}