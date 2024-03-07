#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "player.h"
#include <random>

class enemies
{
	
public:
	enemies(SDL_Renderer* sdlRenderer);
	void init();
	void update();
	void render();
private:
	int randomxresult = 0;
	int randomyresult = 0;
	int screenWidth = 1920;
	int screenHeight = 1080;
	SDL_Rect enemyportion = SDL_Rect();
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* enemytexture = nullptr;
	bool finishedrender = false;

};

