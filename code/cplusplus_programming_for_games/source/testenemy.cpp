#include "testenemy.h"
testenemy::testenemy(SDL_Renderer* sdlRenderer) {
	renderer = sdlRenderer;
	float enemyWidth = 0.05f * (float)screenWidth;
	enemyportion.w = (int)enemyWidth;
	enemyportion.h = (int)enemyWidth;
	std::random_device rd;
	std::uniform_int_distribution<int>dist(290, 1080);
	enemyportion.x = dist(rd);
	enemyportion.y = dist(rd);
}
void testenemy::init()
{
	SDL_Surface* image = IMG_Load("assets/robot-preview.png");
	if (image == nullptr) {
		std::cout << "Could not load image !!" << std::endl;
		std::cout << IMG_GetError << std::endl;
		return;
	}
	texture = SDL_CreateTextureFromSurface(renderer, image);
}
void testenemy::render() 
{
	SDL_RenderCopy(renderer, texture, NULL, &enemyportion); 
	
}

void testenemy::clean() 
{
	
	SDL_DestroyTexture(texture);
}


	
