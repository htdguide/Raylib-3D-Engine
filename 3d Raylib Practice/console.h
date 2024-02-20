#include "string.h"
#include <iostream>
#include "scene3D.h"				//scene3D Header 
#include "raylib.h"					//raylib for existance of this project
#include "gamelib.h"				//gamelib library with all of the actions
#include <cmath>					//c math
#define RAYGUI_IMPLEMENTATION

using namespace std;

class console {
public:
	console();

	void commands(string input) {

		if (input == "scene3d") {
			scene3D();
		}



	}
};
