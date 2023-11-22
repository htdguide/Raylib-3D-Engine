#include <iostream>
#include <stdlib.h>
#include <raylib.h>
#include <string>

class Level
{
	public:
		std::string name;								   //Level name
		Model levelModel;									//Level 3D model
		Texture2D levelTexture;							//Level Texture

		Level(const char* modelpath, const char* texturepath, std::string inName); //Level constructor
};

