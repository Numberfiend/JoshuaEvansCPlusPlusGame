#include "heartcontainer.h"

heartcontainer::heartcontainer(SDL_Renderer* sdlRenderer) 
{
	renderer = sdlRenderer;

	float heartWidth = 0.05f * (float)screenWidth;
	heartportion.w = (int)heartWidth;
	heartportion.h = (int)heartWidth;
	heartportion.x = 100;
	heartportion.y = 100;
	
}
void heartcontainer::init() {
	SDL_Surface* image = IMG_Load("assets/heart.png");
	if (image == nullptr) {
		std::cout << "Could not load image !!" << std::endl;

		std::cout << IMG_GetError << std::endl;
		return;
	}
	hearttexture = SDL_CreateTextureFromSurface(renderer, image);
}
void heartcontainer::render() 
{
	SDL_RenderCopy(renderer, hearttexture, NULL, &heartportion);
}
void heartcontainer::clean()
{
	SDL_DestroyTexture(hearttexture);
}
