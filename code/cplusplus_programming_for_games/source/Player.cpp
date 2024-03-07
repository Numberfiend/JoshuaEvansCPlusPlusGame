#include "Player.h"
#include "GameLoop.h"

Player::Player(SDL_Renderer* sdlRenderer, int window_Width, int window_Height) 
{
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096) == -1) {
		printf("Audio Mixer could not be created! SDL_Error: %s\n", SDL_GetError());
	}

	    shootsound = Mix_LoadWAV("assets/ping-82822.wav");
	    renderer = sdlRenderer;

		screenWidth = window_Width;
		screenHeight = window_Height;

		float playerWidth = 0.05f * (float)screenWidth;
		portion.w = (int)playerWidth;
		portion.h = (int)playerWidth;
		portion.x = 275;
		portion.y = 275;

		float bulletWidth = 0.05f * (float)screenWidth;
		portionbul.w = (int)playerWidth;
		portionbul.h = (int)playerWidth;
		portionbul.x = portion.x + 100; //makes sure the inital bullet won't spawn in the player
		portionbul.y = portion.y;
		
}

void Player::init() 
{
	SDL_Surface* image = IMG_Load("assets/Avasingle.png");
	if (image == nullptr) {
		std::cout << "Could not load image !!" << std::endl;

		std::cout << IMG_GetError << std::endl;
		return;
	}
	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_Surface* bulimage = IMG_Load("assets/bullet.png");
	if (bulimage == nullptr) {
		std::cout << "Could not load image !!" << std::endl;

		std::cout << IMG_GetError << std::endl;
		return;
	}
	bultexture = SDL_CreateTextureFromSurface(renderer, bulimage);

}

void Player::render()
{
	
	SDL_RenderCopy(renderer, texture, NULL, &portion);
	for (auto& bullet : bullets)
	{
	
		SDL_RenderCopy(renderer, bultexture, NULL, &bullet);
		bulletmove(bullet);
	}
}


void Player::playsound()
{
	Mix_PlayChannel(-1, shootsound, 0); //this is where i load the sound effect
}

void Player::update()
{
	for (auto& bullet : bullets)
	{
		bulletmove(bullet);
		
	}

	bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [&](SDL_Rect& bullet)
		{return bullet.x < 0 || bullet.x > screenWidth || bullet.y < 0 || bullet.y > screenHeight;}), bullets.end()); //ensures all of my bullets are destoryed when leaving the screen

	if (shooting && SDL_GetTicks() - shootingstart >= shootingdelay) //if the delay hasn't passed then you can't shoot
	{
		shooting = false;
	}
}


	

void Player::bulletmove(SDL_Rect& bullet)
{
	switch (buldirection)   //changes depending on your direction 
	{
	case 0:
		bullet.x += Speedbul;
		//portionbul.x += Speedbul;
		break;

	case 1:
		bullet.x -= Speedbul;
		//portionbul.x -= Speedbul;
		break;

	case 2:
		bullet.y -= Speedbul;
		//portionbul.y -= Speedbul;
		break;

	case 3:
		//portionbul.y += Speedbul;
		bullet.y += Speedbul;
		break;
	}
}
//movement functions
void Player::moveRight() 
{
	direction = 0;
	portx = 100;
	porty = 0;
	portion.x += Speed;
	if (portion.x + portion.w >= screenWidth) {
		portion.x = screenWidth - portion.w;
		health = health - 1;
	}
}
void Player::moveLeft() 
{
	direction = 1;
	portx = -100;
	porty = 0;
	portion.x -= Speed;
	if (portion.x <= 0)
	{
		portion.x = 0;
		health = health - 1;
	}
}
void Player::moveUp() 
{
	direction = 2;
	portx = 0;
	porty = -100;
	portion.y -= Speed;
	if (portion.y <= 0) 
	{ 
		portion.y = 0; 
		health = health - 1;
	}
}
void Player::moveDown() 
{
	direction = 3;
	portx = 0;
	porty = 100;
	portion.y += Speed;
	if (portion.y + portion.h >= screenHeight) {
		portion.y = screenHeight - portion.h;
		health = health - 1;
	}
}
void Player::shoot()
{
	if (!shooting) //makes sure you are not in the process of shooting your gun
	{
		SDL_Rect newBullet;
		newBullet.w = portionbul.w;
		newBullet.h = portionbul.h;

		newBullet.x = portion.x + portx; //ensures the new bullet is spawned away from the player
		newBullet.y = portion.y + porty;

		bullets.push_back(newBullet); //adds the bullet to the group of bullets already shooting

		buldirection = direction;
		shooting = true;

		shootingstart = SDL_GetTicks();
	}
}