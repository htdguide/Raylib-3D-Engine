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
		Vector3 position;									//Entity Position
		Vector3 camgap = { 50.0f,50.0f,50.0f };				//Entity Camera Gap from the position
		
		Entity(const char* modelpath, const char* texturepath, std::string inName, Vector3 inPos); //Contructor header [modelpath, texturepath, name, position]

		void cameraSync() {									//Camera syncronising with the model method
			entityCamera.position = { position.x + camgap.x, position.y + camgap.y, position.z + camgap.z };
			entityCamera.target = position;
		}

		void movement() {									//Entity movement method
			if (IsKeyDown(KEY_W)) {
				position.x++;
				cameraSync();
			}
		}
};


