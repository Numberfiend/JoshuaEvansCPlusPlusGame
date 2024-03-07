#include "musicplayer.h"

musicplayer::musicplayer() {
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096) == -1) {
		printf("Audio Mixer could not be created! SDL_Error: %s\n", SDL_GetError());
	}

	musicPlayer = Mix_LoadMUS("assets/lifelike-126735.mp3");
	
}


void musicplayer::PlaySound() {
	Mix_PlayMusic(musicPlayer, -1);
}