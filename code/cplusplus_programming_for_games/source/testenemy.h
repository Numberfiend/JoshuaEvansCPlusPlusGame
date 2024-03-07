#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <random>
#include "Player.h"
class testenemy
{
public:
	testenemy(SDL_Renderer* sdlRenderer);
	void init();
	void render();
	void update();
	void clean();
	SDL_Rect gethitbox();
	SDL_Rect getenemybox() {
		return enemyportion;
	}

private:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect enemyportion = SDL_Rect();
	SDL_Texture* texture = nullptr;
	int screenWidth = 1920;
	int i = 0;
};

