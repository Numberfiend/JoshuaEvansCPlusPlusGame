#pragma once
#include <SDL_mixer.h>
#include <sstream>


using namespace std;


class musicplayer {

public:
	musicplayer();

	void PlaySound();
private:
	Mix_Music* musicPlayer;

};