#include "Player.h"
#include "GameLoop.h"
#include "BulletShooting.h"
#include "musicplayer.h"


int GameLoop::init() 
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{

		std::cout << "could not initalize SDL" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}
	window = SDL_CreateWindow(
		"GameWindow",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		screenWidth, screenHeight,
		SDL_WINDOW_SHOWN
	);
	if (window == NULL) 
	{
		std::cout << "could not initalise window!" << std::endl;
		return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL)
	{
		std::cout << "could not intitalise window!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}
	screensurface = SDL_GetWindowSurface(window);
	
	player = new Player(renderer, screenWidth, screenHeight);
	player->init();
    
	healthbar = new heartcontainer(renderer);
	healthbar->init();

	testen = new testenemy(renderer);
	testen->init();
	testen2 = new testenemy(renderer);
	testen2->init();
	testen3 = new testenemy(renderer);
	testen3->init();
	testen4 = new testenemy(renderer);
	testen4->init();
	testen5 = new testenemy(renderer);
	testen5->init();

	//portbul = player->getplayerbox(); //scrapped collsiion functions
	//porten = testen->getenemybox();

	musicPlayer = std::unique_ptr<musicplayer>(new musicplayer());
	musicPlayer->PlaySound();

	fontRenderer = std::unique_ptr<FontRenderer>(new FontRenderer(renderer));
	fontRenderer->init();

	healthRenderer = std::unique_ptr<healthrenderer>(new healthrenderer(renderer));
	healthRenderer->init();


	tiledMap = std::unique_ptr<TiledMap>(new TiledMap(renderer, "assets/tilemap.png"));
	tiledMap->init();

	tiledMap2 = std::unique_ptr<tilemaplose>(new tilemaplose(renderer, "assets/tilemap.png"));
	tiledMap2->init();
	return 1;
}

void GameLoop::countdown() {
	

}

void GameLoop::update() {
	
	portplay = player->getplayerbox();
	porten = testen->getenemybox();
	porten2 = testen2->getenemybox();
	porten3 = testen3->getenemybox();
	porten4 = testen4->getenemybox();
	porten5 = testen5->getenemybox();
	if (SDL_HasIntersection(&portplay , &porten))//https: //wiki.libsdl.org/SDL2/SDL_HasIntersection (from here I found an SDL intersection function which should detect collision)
	{	
		player->health = player->health - 1;
		testen->clean();
    }
	if (SDL_HasIntersection(&portplay, &porten2))
	{
		player->health = player->health - 1;
		testen2->clean();
	}
	if (SDL_HasIntersection(&portplay, &porten3))
	{
		player->health = player->health - 1;
		testen3->clean();
	}
	if (SDL_HasIntersection(&portplay, &porten4))
	{
		player->health = player->health - 1;
		testen4->clean();
	}
	if (SDL_HasIntersection(&portplay, &porten5))
	{
		player->health = player->health - 1;
		testen5->clean();
	}
	


	player->update();
	if (keyStates[UP]) {
		player->moveUp();
	}
	if (keyStates[DOWN]) {
		player->moveDown();
	}
	if (keyStates[LEFT]) {
		player->moveLeft();
	}
	if (keyStates[RIGHT]) {
		player->moveRight();
	}
	if (keyStates[SPACE]) {
		player->shoot();
		player->playsound();
	}
	if (keyStates[ZERO]) {
		player->health - 1;
	}
	if (keyStates[ONE]) {
		player->score + 1;
	}


}


void GameLoop::render() 
{

	SDL_RenderClear(renderer);
	
	
	if (player->health >=1 || player->score==11) { //will render the correct tile map when needed
		tiledMap->render();
	}
	else 
	{
		tiledMap2->render();
		
	}

	testen->render(); //renders all 5 instances of enemies
	testen2->render();
	testen3->render();
	testen4->render();
	testen5->render();
	if (player->health >= 1) { //determines if you've won
		if (player->score <= 10) {
			fontRenderer->render("Score: " + to_string(player->score));
			healthbar->render();
		}
		else {
			fontRenderer->render("Score: You win!");
			healthbar->render();
		}
	}
	if (player->score <= 10) { //determines if you have lost
		if (player->health >= 1) {
			healthRenderer->render("Health: " + to_string(player->health));
		}
		else {
			healthRenderer->render("You Lose");
			testen->clean(); //detroys all enemies when you lose
			testen2->clean();
			testen3->clean();
			testen4->clean();
			testen5->clean();
		}
	}

	
    player->render();
	
	SDL_RenderPresent(renderer);
}

void GameLoop::clean() 
{
	fontRenderer->clean();
	tiledMap->clean();
	delete player;
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void GameLoop::handleInput(SDL_Scancode& keyScanCode) {
	switch (keyScanCode) {
	case SDL_SCANCODE_ESCAPE:
		SDL_DestroyWindow(window);
		SDL_Quit();
		break;
	}

}
// where the keystates for movement are changed
bool GameLoop::keepAlive() {
	SDL_Event userInput;
	while (SDL_PollEvent(&userInput)) {
		if (userInput.type == SDL_QUIT) {
			return false;
		}

		if (userInput.type == SDL_KEYDOWN) {
			switch (userInput.key.keysym.sym) {
			case SDLK_LEFT:
				keyStates[LEFT] = true;
				break;
			case SDLK_RIGHT:
				keyStates[RIGHT] = true;
				break;
			case SDLK_UP:
				keyStates[UP] = true;
				break;
			case SDLK_DOWN:
				keyStates[DOWN] = true;
				break;
			case SDLK_SPACE:
				keyStates[SPACE] = true;
				player->score++;
				break;
			case SDLK_0:
				keyStates[ZERO] = true;
				break;
			case SDLK_1:
				keyStates[ONE] = true;
				break;
			}
		}
		else if (userInput.type == SDL_KEYUP) {
			switch (userInput.key.keysym.sym) {
			case SDLK_LEFT:
				keyStates[LEFT] = false;
				break;
			case SDLK_RIGHT:
				keyStates[RIGHT] = false;
				break;
			case SDLK_UP:
				keyStates[UP] = false;
				break;
			case SDLK_DOWN:
				keyStates[DOWN] = false;
				break;
			case SDLK_SPACE:
				keyStates[SPACE] = false;
				break;
			case SDLK_0:
				keyStates[ZERO] = false;
				break;
			case SDLK_1:
				keyStates[ONE] = false;
				break;
			}
			

		}

		//if (userInput.type == SDL_KEYDOWN) {
			//handleInput(userInput.key.keysym.scancode);
			//switch (userInput.key.keysym.scancode) {
			//case SDL_SCANCODE_F:
				//player->score + 1;
				//break;
			//case SDL_SCANCODE_E:
				//player->health - 1;
				//break;
			//}
		//}
	}
	
	return true;
}   