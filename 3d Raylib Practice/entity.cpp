#include <iostream>
#include <stdlib.h>
#include <raylib.h>
#include "entity.h"


Entity::Entity(const char* modelpath, const char* texturepath, std::string inName, Vector3 inPos) //Contructor [modelpath, texturepath, name, position]
{
	entityModel = LoadModel(modelpath);																	//Loading the model
	entityTexture = LoadTexture(texturepath);															//Loading the texture
	name = inName;																						//Assigning the name
	entityPosition = inPos;																					//Assigning the position
	entityCamera = { 0 };																				//Assigning the Camera3D
	entityCamera.position = { entityPosition.x + camgap.x, entityPosition.y + camgap.y, entityPosition.z + camgap.z };	//Calculating camera position with the gap
	entityCamera.target = entityPosition;																		//Assigning at where camera looking at
	entityCamera.up = Vector3{ 0.0f, 1.0f, 0.0f };														//Camera rotation axis
	entityCamera.fovy = 90.0f;																			//Camera FOV
	entityCamera.projection = CAMERA_PERSPECTIVE;														//Camera projection from raylib
	
}