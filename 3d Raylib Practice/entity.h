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
		
		Entity(const char* modelpath, const char* texturepath, std::string inName) {		//Contructor
			entityModel = LoadModel(modelpath);
			entityTexture = LoadTexture(texturepath);
			name = inName;
		} 
};

