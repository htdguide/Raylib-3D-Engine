#include "raylib.h"
#include "console.h"
#include "mainmenu.h"

string input;

void printChatBubble(string message, bool color) {
	
	string RESETCOLOR = "\033[0m";																					// ANSI escape code to reset to default color
	string BUBBLECOLOR = "\033[0m";																					// ANSI escape code with a default color

	if (color) BUBBLECOLOR = "\033[90m";																			// If true then there will be a gray color																				

	int width = message.length() + 2;																				// 1 space padding on each side


	cout << BUBBLECOLOR << "  " << char(218); 																		// Print top rounded border	
	for (int i = 0; i < width; ++i) cout << char(196);
	cout << char(191) << RESETCOLOR << std::endl;
	

	cout << BUBBLECOLOR << " " << " " << char(179) << " " << message << " " << char(179) << RESETCOLOR << endl;		// Print message with side borders


	cout << BUBBLECOLOR << "  " << char(192);																		// Print bottom rounded border
	for (int i = 0; i < width; ++i) cout << char(196);
	cout << char(217) << RESETCOLOR << endl;
}

void inputHandler()																									//Handler of the input to clear the input every time 
{
	cin >> input;
	std::cout
		<< "\x1b[1A" // Move cursor up one
		<< "\x1b[2K"; // Delete the entire line
}

int main() {
	string welcomeMessage, help;

	welcomeMessage = "Welcome to my background! Type 'help' to see the commands";

	printChatBubble(welcomeMessage, false);
	inputHandler();

	if (input == "mainmenu")
	{
		InitWindow(GetScreenWidth(), GetScreenHeight(), "3D Raylib Practice");																																	//Initializing window
		SetTargetFPS(60);
		ToggleFullscreen();
		mainmenu();
		CloseWindow();
		return 0;
	}

	else
	{
		printChatBubble(input, true);
		inputHandler();
	}
}


