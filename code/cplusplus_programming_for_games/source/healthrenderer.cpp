#include "healthrenderer.h"

healthrenderer::healthrenderer(SDL_Renderer* sdlRenderer)
{

	renderer = sdlRenderer;

}

void healthrenderer::init()
{
	int init = TTF_Init();
	if (init != 0) {
		std::cout << SDL_GetError() << std::endl;
	}
	font = TTF_OpenFont("assets/Roboto-Medium.ttf", 12);
	if (font == NULL) {
		std::cout << SDL_GetError << std::endl;
	}

	portion.x = 10;
	portion.y = 180;//100;
	portion.w = 300;
	portion.h = 120;
}
void healthrenderer::clean()
{
	TTF_CloseFont(font);
}

void healthrenderer::render(std::string text)
{
	SDL_Color colour = SDL_Color();
	colour.r = 255;
	colour.g = 255;
	colour.b = 255;
	colour.a = 0;


	SDL_Surface* textImage = TTF_RenderText_Solid(font, text.c_str(), colour);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textImage);

	SDL_RenderCopy(renderer, texture, NULL, &portion);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(textImage);
}