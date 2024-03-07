#pragma once
#include <SDL.h>
#include <vector>
#include "SDL_image.h"
#include <iostream>
#include "GameLoop.h"
#include "BulletShooting.h"
#include "testenemy.h"
class Player {
public:
	Player(SDL_Renderer* sdlRenderer, int windowWidth, int windowHeight);


	 
	void init();
	void render();
	void playsound();
	
   
	void update();
	void clean();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void shoot();


	
	SDL_Rect getbulletbox();
	SDL_Rect getplayerbox() {
		return portion;
	}

	void bulletmove(SDL_Rect&bullet);


	int score = 0;
	int health = 1;
private:
	//player position and speed
	int Speed = 7;
	int Speedbul = 10;
	int screenWidth = 0;
	int screenHeight = 0;

	SDL_Texture* hearttexture = nullptr;
	SDL_Rect heartportion = SDL_Rect();

	SDL_Rect portion = SDL_Rect();
	SDL_Rect portionbul = SDL_Rect();
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Texture* bultexture = nullptr;

	bool leftright = false;
	bool updown = false;
	int direction = 0;
	int buldirection = 0;
	int portx = 100;
	int porty = portion.y;
	
	bool shooting = false;
	Mix_Chunk* shootsound;
	std::vector<SDL_Rect> bullets; //vector for bullets

	//start and end point (2secs) for timer
	int shootingstart = 0;
	int shootingdelay = 2000;
};