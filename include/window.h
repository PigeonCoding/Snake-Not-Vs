#pragma once

#include "../include/raylib.h"
#include <iostream>

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY } GameScreen;

class Window
{
private:
	const int SCREENWIDTH = 600;
	const int SCREENHEIGHT = 600;
	Sound fxWav;
	GameScreen currentScreen;
	const int cellSize = 20;
	int framesCounter = 0;
	
public:
	
	void init();
	void CloseGame();
	void resetGame();
	void RunGame();
	void start();
	

};
