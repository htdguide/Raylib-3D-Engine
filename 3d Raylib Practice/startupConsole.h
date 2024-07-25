#include <string>
#include <iostream>
#include "mainmenu.h"
#include "raylib.h"
#include <string> 

using namespace std;


void printChatBubble(string message, int color) {																	//Method to create chat bubbles

	string RESETCOLOR = "\033[0m";																					// ANSI escape code to reset to default color
	string BUBBLECOLOR = "\033[0m";																					// ANSI escape code with a default color

	switch (color) {
	case 1:
		BUBBLECOLOR = "\033[90m";																					// If true then there will be a gray color		
		break;
	}

	int width = message.length() + 2;																				// 1 space padding on each side


	cout << BUBBLECOLOR << "  " << char(218); 																		// Print top rounded border	
	for (int i = 0; i < width; ++i) cout << char(196);
	cout << char(191) << RESETCOLOR << std::endl;


	cout << BUBBLECOLOR << " " << " " << char(179) << " " << message << " " << char(179) << RESETCOLOR << endl;		// Print message with side borders


	cout << BUBBLECOLOR << "  " << char(192);																		// Print bottom rounded border
	for (int i = 0; i < width; ++i) cout << char(196);
	cout << char(217) << RESETCOLOR << endl;
}




string inputTidy()																									//Handler of the input to clear the input every time 
{
	string input;
	cin >> input;
	std::cout
		<< "\x1b[1A" // Move cursor up one
		<< "\x1b[2K"; // Delete the entire line
	return input;
}


void welcomeMessage() {
	string welcomeMessage;
	welcomeMessage = "Welcome to raylib engine's console menu! Type 'help' to see the commands";
	printChatBubble(welcomeMessage, 0);
}

void helpMessage() {
	string helpMessage;
	helpMessage = "type 'rungui' to run graphical interface";
	printChatBubble(helpMessage, 0);
}


void mainConsole() {

	welcomeMessage();

	string input;

	while (input != "quit") {

		input = inputTidy();
		printChatBubble(input, 1);

		if (input == "rungui")
		{
			InitWindow(GetScreenWidth(), GetScreenHeight(), "3D Raylib Practice");																																	//Initializing window
			SetTargetFPS(60);
			ToggleFullscreen();
			mainmenu();
			CloseWindow();
			welcomeMessage();
		}

		if (input == "help")
		{
			helpMessage();
		}
	}
}

