//main

#include "use_sdl.h"
#include "array_work.h"
#include "process.h"
#include "audio.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <iomanip>


#define B 50
#define	S 30
#define game_block_max 3
//Screen dimension constants
const short SCREEN_WIDTH=1100;
const short SCREEN_HEIGHT=700;


//console
short arr_game_screen[11][11],arr_game_creat[3][4],arr_game_get_block[18][6];
short dropped=0,dropin=0;//0 no 1 yes
//score
short game_block_in=0;
short player_highscore,player_score=0;
short blockB=2,blockS=1,lifesign=0;
short theme =1;
//Catch event
SDL_Event mainEvent;

//Starts up SDL and creates window
bool init();
//Loads media
bool loadMedia();
//Set color modulation
void setColor( Uint8 red, Uint8 green, Uint8 blue );
//Frees media and shuts down SDL
void close();
//Output
void output();
void menuchose();

void setting_chose();
//Loads individual image
SDL_Surface* loadSurfacebmp( std::string path );
SDL_Surface* loadSurfacepng( std::string path );
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//Current displayed image
//SDL_Surface* gStretchedBlockB[13];
SDL_Surface* gStretchedBlockB;
//SDL_Surface* gStretchedBlockS[12];
SDL_Surface* gStretchedBlockS;
//SDL_Surface* gStretchedNumber[10];
SDL_Surface* gStretchednumber;
SDL_Surface* gStretchedScreen[14];


//The music that will be played
Mix_Music *gMusic = NULL;
//The sound effects that will be used
//Mix_Music *gDisappear = NULL;

bool init()
{
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "1010 by Nguyen Duc Tien", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
		int imgFlags = IMG_INIT_PNG;
		if( !( IMG_Init( imgFlags ) & imgFlags ) )
		{
			printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
			success = false;
		}
		if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
		{
			printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
			success = false;
		}
	}
	return success;
}

short Background=0,Start=1,Dead=2,Leave=3;
short Homechose=4,Settingchose=5,View=6,Setting=7,Cup=8,Musicon=9,Musicoff=10,Soundon=11,Soundoff=12,Home=13;
bool loadMedia()
{
	//Loading success flag
	bool success = true;
	//Load stretching surface
	gStretchedBlockB = loadSurfacebmp( "block_color_50x50/bigblock.bmp" );
    gStretchedBlockS = loadSurfacebmp("block_color_30x30/smallblock.bmp");
	gStretchednumber = loadSurfacebmp("number/number.bmp");

	gStretchedScreen[0] = loadSurfacebmp("icon/background.bmp");
	gStretchedScreen[1] = loadSurfacebmp("icon/start.bmp");
	gStretchedScreen[2] = loadSurfacebmp("icon/gameover.bmp");
	gStretchedScreen[3] = loadSurfacebmp("icon/leave.bmp");
	gStretchedScreen[4] = loadSurfacebmp("icon/menuchose.bmp");
	gStretchedScreen[5] = loadSurfacebmp("icon/settingchose.bmp");
	gStretchedScreen[6] = loadSurfacebmp("icon/view.bmp");
	gStretchedScreen[7] = loadSurfacebmp("icon/setting.bmp");
	gStretchedScreen[8] = loadSurfacebmp("icon/cup.bmp");
	gStretchedScreen[9] = loadSurfacebmp("icon/musicon.bmp");
	gStretchedScreen[10] = loadSurfacebmp("icon/musicoff.bmp");
	gStretchedScreen[11] = loadSurfacebmp("icon/soundon.bmp");
	gStretchedScreen[12] = loadSurfacebmp("icon/soundoff.bmp");
	gStretchedScreen[13] = loadSurfacebmp("icon/home.bmp");
	//Load audio
	//gDisappear = Mix_LoadMUS( "disappear.mp3" );
	gMusic = Mix_LoadMUS( "Symphony-Clean-Bandit-Zara-Larsson.mp3" );
	return success;
}


void close()
{
	//Destroy window
	SDL_DestroyWindow( gWindow );gWindow = NULL;
	SDL_FreeSurface(gScreenSurface);gScreenSurface=NULL;
	SDL_FreeSurface(gStretchedBlockB);gStretchedBlockB=NULL;
	SDL_FreeSurface(gStretchedBlockS);gStretchedBlockS=NULL;
	SDL_FreeSurface(gStretchednumber);gStretchednumber=NULL;
	SDL_FreeSurface(gStretchedScreen[0]);gStretchedScreen[0]=NULL;
	SDL_FreeSurface(gStretchedScreen[1]);gStretchedScreen[1]=NULL;
	SDL_FreeSurface(gStretchedScreen[2]);gStretchedScreen[2]=NULL;
	SDL_FreeSurface(gStretchedScreen[3]);gStretchedScreen[3]=NULL;
	SDL_FreeSurface(gStretchedScreen[4]);gStretchedScreen[4]=NULL;
	SDL_FreeSurface(gStretchedScreen[5]);gStretchedScreen[5]=NULL;
	SDL_FreeSurface(gStretchedScreen[6]);gStretchedScreen[6]=NULL;
	SDL_FreeSurface(gStretchedScreen[7]);gStretchedScreen[7]=NULL;
	SDL_FreeSurface(gStretchedScreen[8]);gStretchedScreen[8]=NULL;
	SDL_FreeSurface(gStretchedScreen[9]);gStretchedScreen[9]=NULL;
	SDL_FreeSurface(gStretchedScreen[10]);gStretchedScreen[10]=NULL;
	SDL_FreeSurface(gStretchedScreen[11]);gStretchedScreen[11]=NULL;
	SDL_FreeSurface(gStretchedScreen[12]);gStretchedScreen[12]=NULL;
	SDL_FreeSurface(gStretchedScreen[13]);gStretchedScreen[13]=NULL;
	//Free the music
	Mix_FreeMusic( gMusic );
	gMusic = NULL;
	//Mix_FreeMusic(gDisappear);
	//gDisappear = 0;
	//Quit SDL subsystems
	//TTF_Quit();
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurfacebmp( std::string path )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	if( loadedSurface == NULL )				printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
		if( optimizedSurface == NULL )		printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	return optimizedSurface;
}
SDL_Surface* loadSurfacepng( std::string path )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

bool gameover()
{
	lifesign = 0;
	short* k = new short;
	short* i = new short;
	short* j = new short;
	for(*k=1;*k<=3;(*k)++)
	{
		for(*i=1;*i<=10;(*i)++)
		{
			for(*j=1;*j<=10;(*j)++)
			{
				if(arr_game_creat[1][*k] !=0 )	drop(*j,*i,arr_game_creat[1][*k],0,2,arr_game_screen,&dropin,&lifesign);
				if (lifesign==1)
				{
					delete k;
					delete i;
					delete j;
					return false;
				}
			}
		}
	}
	delete k;
	delete i;
	delete j;
	return true;
}

bool leavegame()
{
	SDL_Event e;
	while(1)
	{
		do
		{
			//Blit(300,300,500,200,gStretchedScreen[Leave],gRenderer);
			Blit(300,300,500,200,gStretchedScreen[Leave],gScreenSurface);
			SDL_UpdateWindowSurface( gWindow );
			//SDL_RenderPresent( gRenderer );
			if( SDL_MOUSEBUTTONDOWN )
				{
					if(e.button.button == SDL_BUTTON_LEFT)
					{
						if(400<=e.motion.x && e.motion.x<=450 && 400<=e.motion.y && e.motion.y<=450)
						{
							return true;
						}
						else if(655<=e.motion.x && e.motion.x<=700 && 400<=e.motion.y && e.motion.y<=450)
						{
							return false;
						}
					}
				}
		}
		while( SDL_PollEvent( &e ) != 0 );
	}
}

void printscore(short tempscore,short posx,short posy,short theme)
{
	short* a = new short [10];
	short* temp = new short; *temp =0;
	short* d = new short; *d=posx;
	short* i = new short;
	if(tempscore ==0)	{	(*d)+=17;Blitnumber(theme,0,*d,posy,gStretchednumber,gScreenSurface);}
	for(*i=0;*i<=9;(*i)++) a[*i]=-1;
	while(tempscore!=0)
		{
			a[*temp]=tempscore%10;
			tempscore=tempscore/10;
			(*temp)++;
		}
	for(*i=(*temp)/2;*i>=0;(*i)--)
	{
		if(a[*i]>=0)
			{
				(*d)+=17;
				switch(a[*i])
				{

					case 0:{	Blitnumber(theme,0,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 1:{	Blitnumber(theme,1,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 2:{	Blitnumber(theme,2,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 3:{	Blitnumber(theme,3,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 4:{	Blitnumber(theme,4,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 5:{	Blitnumber(theme,5,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 6:{	Blitnumber(theme,6,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 7:{	Blitnumber(theme,7,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 8:{	Blitnumber(theme,8,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 9:{	Blitnumber(theme,9,*d,posy,gStretchednumber,gScreenSurface);break;}
				}
			}
	}
	*d=posx+17;
	for(*i=((*temp)/2)+1;*i<*temp;(*i)++)
		{
		if(a[*i]>=0)
			{
				(*d)-=17;
				switch(a[*i])
				{

					case 0:{	Blitnumber(theme,0,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 1:{	Blitnumber(theme,1,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 2:{	Blitnumber(theme,2,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 3:{	Blitnumber(theme,3,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 4:{	Blitnumber(theme,4,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 5:{	Blitnumber(theme,5,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 6:{	Blitnumber(theme,6,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 7:{	Blitnumber(theme,7,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 8:{	Blitnumber(theme,8,*d,posy,gStretchednumber,gScreenSurface);break;}
					case 9:{	Blitnumber(theme,9,*d,posy,gStretchednumber,gScreenSurface);break;}
				}
			}
		}
	delete i;
	delete d;
	delete temp;
	delete [] a;

}

bool newgame(short time)
{
	SDL_Event e;
	if(time ==1)
	{
		console(arr_game_screen);
		arr_game_creat_random(arr_game_get_block,arr_game_creat,&game_block_in);
		file(2,&player_highscore,&theme);//get highscore-theme from file
	}

	//Event handler
	while(1)
		while( SDL_PollEvent( &e ) != 0 )
		{
			//Blit(0,0,1100,700,gStretchedScreen[Start],gRenderer);
			Blit(0,0,1100,700,gStretchedScreen[Start],gScreenSurface);
			printscore(player_highscore,510,250,1);
			//SDL_RenderPresent( gRenderer );
			SDL_UpdateWindowSurface( gWindow );
			if( SDL_MOUSEBUTTONDOWN )
			{
				if(e.button.button == SDL_BUTTON_LEFT)
				{
					if(370<=e.motion.x && e.motion.x<=715 && 390<=e.motion.y && e.motion.y<=515)
					{
						return true;
					}

					if(370<=e.motion.x && e.motion.x<=480 && 520<=e.motion.y && e.motion.y<=625)
					{
						savegame(2,&player_score,arr_game_screen,arr_game_creat,&game_block_in);
						return true;
					}

					if(490<=e.motion.x && e.motion.x<=600 && 520<=e.motion.y && e.motion.y<=625)
					{
						if( leavegame()==true) return false;
						else if (leavegame()==false) continue;
					}

					if(605<=e.motion.x && e.motion.x<=715 && 520<=e.motion.y && e.motion.y<=625)
					{
						player_highscore =0;
						player_score = 0;
						console(arr_game_screen);
						arr_game_creat_random(arr_game_get_block,arr_game_creat,&game_block_in);
					}

				}
			}
		}
}

void home_button()
{
	output();
    Blit(2,52,50,250,gStretchedScreen[Homechose],gScreenSurface);
	short* i = new short;
	short* j = new short;
	for(*i=300;*i<=750;(*i)+=B) // w
	{
		for(*j=150;*j<=600;(*j)+=B) //h
		{
			short* arr_game_pos_x = new short;	*arr_game_pos_x=(*i-250)/B;
			short* arr_game_pos_y = new short;	*arr_game_pos_y=(*j-100)/B;

			if( arr_game_screen[*arr_game_pos_y][*arr_game_pos_x] > -1 )
			{
				//Blit(*i,*j,B,B,gStretchedBlockB[arr_game_screen[*arr_game_pos_y][*arr_game_pos_x]],gScreenSurface);
				BlitBigBlock(arr_game_screen[*arr_game_pos_y][*arr_game_pos_x],*i,*j,gStretchedBlockB,gScreenSurface);
				//Blit(*i,*j,B,B,gStretchedBlockB[arr_game_screen[*arr_game_pos_y][*arr_game_pos_x]],gRenderer);
			}
			delete arr_game_pos_x;
			delete arr_game_pos_y;
		}
	}
	for(*i=210;*i<=570;(*i)+=180)
		{
			if(arr_game_creat[1][*i]!=0);
			draw_shape(900,*i,blockS,arr_game_creat[1][(*i-30)/180],arr_game_creat[2][(*i-30)/180],arr_game_get_block,gStretchedBlockB,gStretchedBlockS,gScreenSurface);
			//draw_shape(900,*i,blockS,arr_game_creat[1][(*i-30)/180],arr_game_creat[2][(*i-30)/180],arr_game_get_block,gStretchedBlockB,gStretchedBlockS,gRenderer);
		}
	delete i;
	delete j;
}

bool menuchose(SDL_Event e)
{
	while( 1 )
	{
		do
		{
			home_button();
			SDL_UpdateWindowSurface( gWindow );
			//SDL_RenderPresent( gRenderer );
			if( SDL_MOUSEBUTTONDOWN )
			{
				if(e.button.button == SDL_BUTTON_LEFT)
				{
					if(2<=e.motion.x && e.motion.x<=52 && 253<=e.motion.y && e.motion.y<=302)
					{
						return false;
					}
					if(2<=e.motion.x && e.motion.x<=52 && 103<=e.motion.y && e.motion.y<=152)
					{
						console(arr_game_screen);
						arr_game_creat_random(arr_game_get_block,arr_game_creat,&game_block_in);
						player_score=0;
						return false;
					}
					if(2<=e.motion.x && e.motion.x<=52 && 53<=e.motion.y && e.motion.y<=102)
					{
						SDL_Delay(200);
							if(newgame(0) == true) return false;
							else return true;

					}
					if(2<=e.motion.x && e.motion.x<=52 && 153<=e.motion.y && e.motion.y<=202)
					{
						savegame(1,&player_score,arr_game_screen,arr_game_creat,&game_block_in);
						return true;
					}
					if(2<=e.motion.x && e.motion.x<=52 && 203<=e.motion.y && e.motion.y<=252)
					{
						if( leavegame()==true) return true;
						else return false;
					}
				}
			}
		}
		while( SDL_PollEvent( &e ) != 0 );
	}
}
void dead()
{
	output();
	Blit(200,500,500,100,gStretchedScreen[Dead],gScreenSurface);
	if(player_score < player_highscore)
    {
		//Blit(60,280,160,160,gStretchedScreen[Silvercup],gScreenSurface);
		BlitCup(theme,1,60,280,gStretchedScreen[Cup],gScreenSurface);
		printscore(player_score,110,230,theme);
		printscore(player_highscore,110,450,theme);
	}
	if(player_score == player_highscore)
	{
		//Blit(60,280,160,160,gStretchedScreen[Goldcup],gScreenSurface);
		BlitCup(theme,0,60,280,gStretchedScreen[Cup],gScreenSurface);
		printscore(player_highscore,110,450,theme);
	}
	Blit(1048,2,50,50,gStretchedScreen[View],gScreenSurface);
}


bool deadchose(SDL_Event e)
{
	while(1 )
	{
		while( SDL_PollEvent( &e ) != 0 )
		{
			dead();
			SDL_UpdateWindowSurface( gWindow );
			//SDL_RenderPresent( gRenderer );
			if( SDL_MOUSEBUTTONDOWN )
			{
				if(e.button.button == SDL_BUTTON_LEFT)
				{
					if(2<=e.motion.x && e.motion.x<=52 && 2<=e.motion.y && e.motion.y<=52)
					{
						return menuchose(e);
					}
				}
			}
			if(1048<=e.motion.x && e.motion.x<=1098 && 2<=e.motion.y && e.motion.y<=52)
					{
						output();
						SDL_UpdateWindowSurface( gWindow );
						//SDL_RenderPresent(gRenderer);
					}
		}
	}
}


void setting_menu()
{
	output();
	Blit(1048,52,50,50,gStretchedScreen[Settingchose],gScreenSurface);
	/*
	if(*state_music == true)		Blit(*i+50,200,50,50,gStretchedScreen[Musicon],gScreenSurface);
	else 							Blit(*i+100,200,50,50,gStretchedScreen[Musicoff],gScreenSurface);
	if(*state_sound == true)		Blit(*i+50,300,50,50,gStretchedScreen[Soundon],gScreenSurface);
	else 							Blit(*i+100,300,50,50,gStretchedScreen[Soundoff],gScreenSurface);
	*/
}

void setting_chose()
{
	SDL_Event e;
	bool quit = false;
	while(quit == false)
	{
		while( SDL_PollEvent(&e) !=0)
		{
			setting_menu();
			SDL_UpdateWindowSurface(gWindow);
			if( SDL_MOUSEBUTTONDOWN )
			{
				if(e.button.button == SDL_BUTTON_LEFT)
				{
					if(1048<=e.motion.x && e.motion.x<=1098 && 253<=e.motion.y && e.motion.y<=302)
					{
						quit =true;
					}
					if(1048<=e.motion.x && e.motion.x<=1098 && 53<=e.motion.y && e.motion.y<=102)
					{
						//Background=Background1;
						theme =1;
					}
					if(1048<=e.motion.x && e.motion.x<=1098 && 103<=e.motion.y && e.motion.y<=152)
					{
						//Background=Background2;
						theme =2;
					}
					if(1048<=e.motion.x && e.motion.x<=1098 && 153<=e.motion.y && e.motion.y<=202)
					{
						//Background=Background3;
						theme =3;
					}
					if(1048<=e.motion.x && e.motion.x<=1098 && 203<=e.motion.y && e.motion.y<=253)
					{
						//Background=Background4;
						theme =4;
					}
					/*
					if(850<=e.motion.x && e.motion.x<=900 && 200<=e.motion.y && e.motion.y<=250)
					{
						*state_music =false;
					}
					if(901<=e.motion.x && e.motion.x<=950 && 200<=e.motion.y && e.motion.y<=250)
					{
						*state_music = true;
					}
					if(850<=e.motion.x && e.motion.x<=900 && 300<=e.motion.y && e.motion.y<=350)
					{
						*state_sound = false;
					}
					if(901<=e.motion.x && e.motion.x<=950 && 300<=e.motion.y && e.motion.y<=350)
					{
						*state_sound = true;
					}
					*/
				}
			}
		}

	}
}

void output()
{
	short* i = new short;
	short* j = new short;
	//Blit(0,0,1100,700,gStretchedScreen[Background],gRenderer);
	//Blit(2,2,50,50,gStretchedScreen[Home],gRenderer);
	BlitBackground(theme,gStretchedScreen[Background],gScreenSurface);
	Blit(2,2,50,50,gStretchedScreen[Home],gScreenSurface);
    Blit(1048,2,50,50,gStretchedScreen[Setting],gScreenSurface);
	//Blit(60,280,160,160,gStretchedScreen[Silvercup],gScreenSurface);
	BlitCup(theme,1,60,280,gStretchedScreen[Cup],gScreenSurface);
	printscore(player_score,110,230,theme);
	printscore(player_highscore,110,450,theme);
	//Apply the image stretched
	for(*i=300;*i<=750;(*i)+=B) // w
	{
		for(*j=150;*j<=600;(*j)+=B) //h
		{
			short* arr_game_pos_x = new short;	*arr_game_pos_x=(*i-250)/B;
			short* arr_game_pos_y = new short;	*arr_game_pos_y=(*j-100)/B;

			if( arr_game_screen[*arr_game_pos_y][*arr_game_pos_x] > -1 )
			{
				BlitBigBlock(arr_game_screen[*arr_game_pos_y][*arr_game_pos_x],*i,*j,gStretchedBlockB,gScreenSurface);
				//Blit(*i,*j,B,B,gStretchedBlockB[arr_game_screen[*arr_game_pos_y][*arr_game_pos_x]],gRenderer);
			}
			delete arr_game_pos_x;
			delete arr_game_pos_y;
		}
	}
	for(*i=210;*i<=570;(*i)+=180)
		{
			if(arr_game_creat[1][*i]!=0);
			draw_shape(900,*i,blockS,arr_game_creat[1][(*i-30)/180],arr_game_creat[2][(*i-30)/180],arr_game_get_block,gStretchedBlockB,gStretchedBlockS,gScreenSurface);
			//draw_shape(900,*i,blockS,arr_game_creat[1][(*i-30)/180],arr_game_creat[2][(*i-30)/180],arr_game_get_block,gStretchedBlockB,gStretchedBlockS,gRenderer);
		}
	delete i;
	delete j;
	//SDL_RenderPresent( gRenderer );
}

//void delete_full_row_or_colum(bool state_sound)
void delete_full_row_or_colum()
{
	short* colum=new short[11];
	short* row=new short[11];
	short* i = new short;
	short* k = new short;
	check_full_row_or_colum(arr_game_screen,row,colum,&player_score);
	for(*i=1;*i<=10;(*i)++)
	{
		if(row[*i]==*i)
		{
			for(  *k=1;*k<=10;(*k)++)
			{
				arr_game_screen[*i][*k]=0;
				output();
				SDL_Delay(15);
				SDL_UpdateWindowSurface( gWindow );
				//SDL_RenderPresent( gRenderer );
			}
			player_score+=10;
		}
		if(colum[*i]==*i)
		{
			for( *k=1;*k<=10;(*k)++)
			{
				arr_game_screen[*k][*i]=0;
				output();
				SDL_Delay(15);
				SDL_UpdateWindowSurface( gWindow );
				//SDL_RenderPresent( gRenderer );
			}
			player_score+=10;
		}
	}
	delete i;
	delete k;
	delete [] row;
	delete [] colum;
	//if( state_sound == true ) effect(gDisappear) ;
}



void deadanimation()
{
	short *i = new short;
	short *j = new short;
	for( *i=300;*i<=750;(*i)+=B) // w
	{
		for(*j=150;*j<=600;(*j)+=B) //h
		{
			short* arr_game_pos_x = new short;
			short* arr_game_pos_y = new short;
			*arr_game_pos_x=(*i-250)/B;
			*arr_game_pos_y=(*j-100)/B;
			if( arr_game_screen[*arr_game_pos_y][*arr_game_pos_x] == 0 )
			{
				//Blit(0,0,1100,700,gStretchedScreen[10],gRenderer);
				//Blit(*i,*j,B,B,gStretchedBlockB[12],gScreenSurface);
				BlitBigBlock(12,*i,*j,gStretchedBlockB,gScreenSurface);
				SDL_Delay(50);
				SDL_UpdateWindowSurface( gWindow );
				//SDL_RenderPresent( gRenderer );
			}
			delete arr_game_pos_x;
			delete arr_game_pos_y;
		}

	}
	delete i;
	delete j;
}

int main( int argc, char* args[] )
{
	short tempcolor, tempshape,posofshape,posX,posY;
	//bool state_music = true, state_sound = true;
	SDL_Event e;
	//Start up SDL and create window
	if( !init() )	{	printf( "Failed to initialize!\n" );	}
	else
	{
		//Load media
		if( !loadMedia() )	{	printf( "Failed to load media!\n" );	}
		else
		{
			if( newgame(1)==true )
			{
				audio(gMusic);
				//Main loop flag
				bool quit = false;
				//Event handler
				//While application is running
				while( !quit )
				{
					//effect(gDisappear);
					//Handle events on queue
					while( SDL_PollEvent( &e ) != 0 )
					{
						if(e.type == SDL_QUIT)
						{
							if(leavegame()==true)	quit=true;
							if(leavegame()==false) continue;
						}
						if(game_block_in == 0) arr_game_creat_random(arr_game_get_block,arr_game_creat,&game_block_in);
						output();
						if( gameover() == true )
						{
							deadanimation();
							SDL_Delay(2000);
							quit=deadchose(e);
						}
						else
						{
							dropin=0;dropped=0;
							posX=(e.motion.x-810)/30,posY=(e.motion.y-120)/30;
							if(player_highscore<=player_score) player_highscore=player_score;
							if( SDL_MOUSEBUTTONDOWN )
							{
								if(e.button.button == SDL_BUTTON_LEFT)
								{
									if(2<=e.motion.x && e.motion.x<=52 && 2<=e.motion.y && e.motion.y<=52)
									{
										dropped=1;
										quit=menuchose(e);
									}
									else if(1<=posX && posX<=5 && 1<=posY && posY<=17 && e.button.button == SDL_BUTTON_LEFT )
										{
											if( 1 <= arr_game_get_block[posY][posX] && arr_game_get_block[posY][posX]<=19)
											{
												if(150<=e.motion.y && e.motion.y<=300)		{tempcolor = arr_game_creat[2][1]; posofshape=1;}
												else if(330<=e.motion.y && e.motion.y<=480)	{tempcolor = arr_game_creat[2][2]; posofshape=2;}
												else if(510<=e.motion.y && e.motion.y<=660)	{tempcolor = arr_game_creat[2][3]; posofshape=3;}
												tempshape=arr_game_get_block[posY][posX];
											}
										}
								}
							}
							if( dropped==0) draw_shape(e.motion.x-25,e.motion.y-25,blockB,tempshape,tempcolor,arr_game_get_block,gStretchedBlockB,gStretchedBlockS,gScreenSurface);
											//draw_shape(e.motion.x-25,e.motion.y-25,blockB,tempshape,tempcolor,arr_game_get_block,gStretchedBlockB,gStretchedBlockS,gRenderer);
							if( SDL_MOUSEBUTTONDOWN )
							{
								if(e.button.button == SDL_BUTTON_LEFT)
									{
										if(300<=e.motion.x && e.motion.x<=800 && 150<=e.motion.y && e.motion.y<=650)
										{
											drop(e.motion.x,e.motion.y,tempshape,tempcolor,1,arr_game_screen,&dropin,&lifesign);
											//delete_full_row_or_colum(state_sound);
											delete_full_row_or_colum();
											if(dropin==1)
											{
												cleararea(posofshape,arr_game_creat,arr_game_get_block);
												game_block_in--;
												tempcolor=0;
												tempshape=0;
											}
										}
										else if( e.motion.x<300 && e.motion.y<200  )
										{
											dropped=1;
											tempcolor=0;
											tempshape=0;
										}
									}
							}

							if( SDL_MOUSEBUTTONDOWN )
							{
								if(e.button.button == SDL_BUTTON_LEFT)
								{
									if(1048<=e.motion.x && e.motion.x<=1098 && 2<=e.motion.y && e.motion.y<=52)
									{
										setting_chose();
									}
								}
							}

						}

						//Update the surface
						SDL_UpdateWindowSurface( gWindow );
						//SDL_RenderPresent( gRenderer );
						//SDL_RenderClear(gRenderer);
					}

				}
			}
		}
	}
	// print highscore-theme to file
	file(1,&player_highscore,&theme);
	//Free resources and close SDL
	close();
	return 0;
}
