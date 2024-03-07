#include "enemies.h"
enemies::enemies(SDL_Renderer* sdlRenderer) {
	renderer = sdlRenderer;
}
void enemies::init() {
	SDL_Surface* image = IMG_Load("assets/robot-preview.png");
	if (image == nullptr) {
		std::cout << "Could not load image !!" << std::endl;

		std::cout << IMG_GetError << std::endl;
		return;
	}
	enemytexture = SDL_CreateTextureFromSurface(renderer, image);
	
	float enemyWidth = 0.05f * (float)screenWidth;
	enemyportion.w = (int)enemyWidth;
	enemyportion.h = (int)enemyWidth;	
}

void enemies::render() {
	std::random_device rd;
	std::uniform_int_distribution<int>dist(50, 900);
	if (finishedrender != true) {
		for (int i = 0; i < 5; i++) {
          
			randomxresult = dist(rd);
			randomyresult = dist(rd);
			enemyportion.x = randomxresult;
			enemyportion.y = randomyresult;
			SDL_RenderCopy(renderer, enemytexture, NULL, &enemyportion);
		}
		finishedrender = true;
	}
}
/*random number generator idea sourced from https ://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus*/

void enemies::update() {

}
