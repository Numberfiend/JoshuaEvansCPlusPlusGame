#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "musicplayer.h"
#include "Player.h"
#include "TiledMap.h"
#include "FontRenderer.h"
#include "BulletShooting.h"
#include "enemies.h"
#include "testenemy.h"
#include "heartcontainer.h"
#include "healthrenderer.h"
#include "tilemaplose.h"

using namespace std;

const int screenWidth = 1920;//800;
const int screenHeight = 1080;//640;

class Player;
class enemies;
class testenemy;
class heartcontainer;


class GameLoop
{
public:

	int init();
	void countdown();
	void update();
	void render();
	void handleInput(SDL_Scancode& keyScanCode);
	bool keepAlive();
	void clean();
   

	SDL_Renderer* getRenderer() { return renderer; }
	
	SDL_Rect portbul; 
	SDL_Rect porten;
	SDL_Rect porten2;
	SDL_Rect porten3;
	SDL_Rect porten4;
	SDL_Rect porten5;
	SDL_Rect portplay;
	
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Surface* screensurface = nullptr;



	std::unique_ptr<musicplayer> musicPlayer;
	std::unique_ptr<FontRenderer> fontRenderer;
	std::unique_ptr<TiledMap> tiledMap;
	std::unique_ptr<tilemaplose> tiledMap2;
	std::unique_ptr<healthrenderer> healthRenderer;

	enemies* enemy = nullptr;
	Player* player = nullptr;
	heartcontainer* healthbar = nullptr;
	testenemy* testen = nullptr;
	testenemy* testen2 = nullptr;
	testenemy* testen3 = nullptr;
	testenemy* testen4 = nullptr;
	testenemy* testen5 = nullptr;
	
	//float rotationAngle;
	
	bool keyDown[512];	
	enum KeyStates {
	LEFT = 0,
	RIGHT,
	UP,
	DOWN,
	SPACE,
	ZERO,
	ONE,
	KEYSTATES_COUNT
    };
	bool keyStates[KeyStates::KEYSTATES_COUNT];
};

