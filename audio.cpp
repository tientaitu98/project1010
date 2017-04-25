//Using SDL, SDL_image, SDL_ttf, SDL_mixer, standard IO, math, and strings
#include "audio.h"

void audio(Mix_Music* gTempMusic)
{
	//If there is no music playing
	if( Mix_PlayingMusic() == 0 )
	{
		Mix_PlayMusic(gTempMusic,-1);
	}
	/*
	//If music is being played
	{
		//If the music is paused
		if( Mix_PausedMusic() == 1 )
		{
			//Resume the music
			Mix_ResumeMusic();
		}
		//If the music is playing
		else
		{
			//Pause the music
			Mix_PauseMusic();
		}
	}
		case 2:
		{
			Mix_HaltMusic();
			break;
		}
		*/	//Stop the music

	//}
}
void effect(Mix_Music* gTempMusic)
{
	Mix_PlayMusic( gTempMusic, 0 );
}
