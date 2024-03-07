#pragma once
#include<iostream>
#include <SDL.h>

#include <SDL_image.h>

class Player;
class heartcontainer
{
	
public:
	heartcontainer(SDL_Renderer* sdlRenderer);
	
	void init();
	void render();
	void update();
	void clean();
private:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* hearttexture = nullptr;
	SDL_Rect heartportion = SDL_Rect();
	int screenWidth = 1920;
};

