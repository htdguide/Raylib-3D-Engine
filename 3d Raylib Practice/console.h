#include "string.h"
#include <iostream>
#include "scene3D.h"				//scene3D Header 
#include "raylib.h"					//raylib for existance of this project
#include "gamelib.h"				//gamelib library with all of the actions
#include <cmath>					//c math
#include "raygui.h"					//rayGUI for the interface
#define RAYGUI_IMPLEMENTATION

using namespace std;

class console {
public:
	console();
};

class consoleWindowClass {																																//Console Class
public:
	int textBoxSize = 40;																																//Textbox height size
	int topBar = 20;																																	//Window top bar size (height)
	int buttonsWidth = 30;																																//Buttons width

	struct textBufferStruct {
		char text[128] = { 0 };																															//One line of the text
	};
	textBufferStruct textBuffer[20];

	const int textSize = sizeof(textBuffer[0].text);																											//Taking the text size from the struct

	bool exitStatus = false;
	bool textBoxStatus = false;
	float scaleNum = 166348;																															//This number came from the formula [ScreenWidth * ScreesHeight / desired font size]
	int fontSize = GetScreenHeight() * GetScreenWidth() / scaleNum;																						//Getting font size 30 with resolution 2736 x 1824
	string input;																								    									//Input from the keyboard
	string previousInput;	
	

	Vector2 backgroundSize;																																//Size of the background box
	Vector2 backgroundPosition;																															//Position of the background
	Vector2 position{ 10, 10 };																															//Position of the console
	Vector2 size = { 800 , 600 };																														//Size of the console
	Vector2 exitButtonSize = { (float)buttonsWidth, (float)topBar };
	
	int borders = 10;																																	//Borders padding [Choose between 0 and 100]
	
	Color borderColor = DARKGRAY;																														//Border Color
	Color backgroundColor = BLACK;																														//Background Color
	Color textColor = WHITE;																															//Text Color
	Color textBoxColor = BLACK;																															//Textbox Color
	Rectangle textBox;


	bool console() {																																	//Drawing a console
		stylesSettingsDefault();																														//Applying styles default settings
		DrawRectangleRounded(Rectangle{ position.x, position.y, size.x, size.y }, 0.01, 25, borderColor);												//Drawing a rectangle behind background to make borders
		
		backgroundPosition = { position.x + borders, position.y + borders + 20};																		//Calculation of the textbox coordinates inside the console + 10 pixels of the gap for close/move buttons
		backgroundSize = { size.x - 2 * borders, size.y - 2 * borders - topBar};																		//Calculation of the textbox size inside the console by using padding
		DrawRectangle(backgroundPosition.x, backgroundPosition.y, backgroundSize.x, backgroundSize.y, backgroundColor);									//Drawing background rectangle
		
		textBox = { backgroundPosition.x, backgroundPosition.y + backgroundSize.y - textBoxSize, backgroundSize.x, (float)textBoxSize };				//Textbox rectangle
		DrawRectangleLinesEx(textBox, 3.0, borderColor);																								//Drawing a textbox borders
		
		Rectangle exitButton{ backgroundPosition.x + backgroundSize.x - exitButtonSize.x, backgroundPosition.y  - exitButtonSize.y, exitButtonSize.x, exitButtonSize.y};
		if (GuiButton(exitButton, " ")) {
			exitStatus = true;
		}
		if(GuiTextBox(textBox, textBuffer[0].text, 128, textBoxStatus)) textBoxInputHandler();
		mouseClickHandler();
		return exitStatus;
	}

	void mouseClickHandler() {
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {

			if (CheckCollisionPointRec(GetMousePosition(), textBox)) {
				textBoxStatus = true;
			}
			else textBoxStatus = false;
		}
		else;
	}

	void stylesSettingsDefault() {

		//Textbox
		GuiSetStyle(DEFAULT, TEXT_SIZE, fontSize);																										//Font size set		
		GuiSetStyle(TEXTBOX, BASE_COLOR_PRESSED, 0xFFFFFFFF);																							//White color when active
		GuiSetStyle(TEXTBOX, BORDER_COLOR_PRESSED, 0x000000FF);																							//Black borders when active
		GuiSetStyle(TEXTBOX, TEXT_COLOR_PRESSED, 0x000000FF);																							//Black text when active
		GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, 0x808080FF);																							//Gray borders when disabled

		//Button
		GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, 0xAA2200FF);																								//Button color set
		GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, 0xAA2200FF);																							//Red borders when button is normal
		GuiSetStyle(BUTTON, BORDER_COLOR_FOCUSED, 0xAA2200FF);																							//Red borders when focused
		GuiSetStyle(BUTTON, BASE_COLOR_FOCUSED, 0xAA4400FF);																							//Red + Green base color when focused
		GuiSetStyle(BUTTON, BASE_COLOR_PRESSED, 0x8B4400FF);																							//Dark red color when pressed
		GuiSetStyle(BUTTON, BORDER_COLOR_PRESSED, 0xAA2200FF);																							//Red borders when button is pressed
		
	
	
	
	
	}

	void textBoxInputHandler() {																										
		commands(textBuffer[0].text);
		for (int i = 0; i++; i < sizeof(textBuffer) - 1) {																							//Moving all of the data to the upper line
			strcpy(textBuffer[i+1].text, textBuffer[i].text);
		}
		strcpy(textBuffer[0].text, "");																												//Erasing main input line																						
	}

	void commands(string input) {

		if (input == "scene3d") {
			scene3D();
		}



	}
};