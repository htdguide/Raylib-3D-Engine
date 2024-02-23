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
class consoleWindowClass {																																//Console Class
public:
	string input;																								    									//Input from the keyboard
	string previousInput;																																//Previous input from the keyboard
	Vector2 position{ 10, 10 };																															//Position of the console
	Vector2 size = { 800 , 600 };																														//Size of the console
	int borders = 10;																																	//Borders padding [Choose between 0 and 100]
	Color borderColor = DARKGRAY;																														//Border Color
	Color backgroundColor = BLACK;																														//Background Color
	Color textColor = WHITE;																															//Text Color
	Color textBoxColor = BLACK;																															//Textbox Color
	int textBoxSize = 40;																																//Textbox height size
	
	
	void drawConsole() {																																//Drawing a console
		DrawRectangleRounded(Rectangle{ position.x, position.y, size.x, size.y }, 0.02, 25, borderColor);												//Drawing a rectangle behind background to make borders
		
		Vector2 backgroundPosition = { position.x + borders, position.y + borders };																	//Calculation of the textbox coordinates inside the console
		Vector2 backgroundSize = { size.x - 2 * borders, size.y - 2 * borders};																			//Calculation of the textbox size inside the console by using padding
		DrawRectangle(backgroundPosition.x, backgroundPosition.y, backgroundSize.x, backgroundSize.y, backgroundColor);									//Drawing background rectangle
		Rectangle textBox{ backgroundPosition.x - 4, backgroundPosition.y + backgroundSize.y - textBoxSize, backgroundSize.x + 7, textBoxSize };		//Textbox rectangle
		DrawRectangleLinesEx(textBox, 3.0, borderColor);																								//Drawing a textbox borders
	
	}
};
