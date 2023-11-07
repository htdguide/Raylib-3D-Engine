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
		Vector3 position;
		
		Entity(const char* modelpath, const char* texturepath, std::string inName, Vector3 pos) //Contructor [modelpath, texturepath, name, position]
		{ 
			entityModel = LoadModel(modelpath);
			entityTexture = LoadTexture(texturepath);
			name = inName;
			position = pos;
		} 
};

