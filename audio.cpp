#include "audio.h"

void audio(Mix_Music* gTempMusic)
{
	//If there is no music playing
	if( Mix_PlayingMusic() == 0 )
	{
		Mix_PlayMusic(gTempMusic,-1);
	}
	//If music is being played
	else if( Mix_PlayingMusic() == 1 )
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
	/*
	{
		//Stop the music
		Mix_HaltMusic();
	}

	*/

}
void effect(Mix_Chunk* gTempMusic)
{
	//Mix_PlayMusic( gTempMusic, 0 );
	Mix_PlayChannel( -1, gTempMusic, 0 );
}
