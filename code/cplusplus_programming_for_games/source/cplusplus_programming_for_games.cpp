// cplusplus_programming_for_games.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "GameLoop.h"

int main()
{

	GameLoop gameLoop = GameLoop();
	if (gameLoop.init() < 0) return 1;

	while (gameLoop.keepAlive())
	{
		gameLoop.update();
		gameLoop.render();
		SDL_Delay(16);
	} 

	gameLoop.clean();
	return 0;
}