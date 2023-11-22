#include "level.h"

Level::Level(const char* modelpath, const char* texturepath, std::string inName)						 //Contructor [modelpath, texturepath, name, position]
{
	levelModel = LoadModel(modelpath);																	//Loading the model
	levelTexture = LoadTexture(texturepath);															//Loading the texture
	name = inName;																						//Assigning the name
}
