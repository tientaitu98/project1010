//1010
#include "use_sdl.h"
#include "array_work.h"
#include "process.h"
#include "audio.h"
#include <SDL_image.h>
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
short player_highscore,player_score=0,challenger_highscore;
short blockB=2,blockS=1,lifesign=0;
short theme =1;
bool state_music = true	, state_sound = true , allow_to_save=true;
short challenge = 5000;
SDL_TimerID term;
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
SDL_Surface* gStretchedBlock;
SDL_Surface* gStretchednumber;
SDL_Surface* gStretchedScreen[14];
//The music that will be played
Mix_Music *gMusic = NULL;
//The sound effects that will be used
Mix_Chunk* gDisappear = NULL;
Mix_Chunk* gDrop = NULL;
Mix_Chunk* gAddblobk = NULL;
Mix_Chunk* gGameover = NULL;

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

short Background=0,Start=1,Dead=2,Leave=3,Homechose=4,Settingchose=5,View=6;
short Setting=7,Cup=8,Sound=9,Home=10;
bool loadMedia()
{
	//Loading success flag
	bool success = true;
	//Load stretching surface
	gStretchedBlock = loadSurfacebmp( "block_color/bigblock.bmp" );
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
	gStretchedScreen[9] = loadSurfacebmp("icon/S&E.bmp");
	gStretchedScreen[10] = loadSurfacebmp("icon/home.bmp");
	//Load audio
	gDisappear = Mix_LoadWAV( "disapear.wav" );
	gDrop = Mix_LoadWAV( "drop.wav" );
	gAddblobk = Mix_LoadWAV("addblock.wav");
	gGameover = Mix_LoadWAV("game_over.wav");
	gMusic = Mix_LoadMUS( "Symphony-Clean-Bandit-Zara-Larsson.mp3" );
	return success;
}


void close()
{
	//Destroy window
	SDL_DestroyWindow( gWindow );gWindow = NULL;
	SDL_FreeSurface(gScreenSurface);gScreenSurface=NULL;
	SDL_FreeSurface(gStretchedBlock);gStretchedBlock=NULL;
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
	//Free the music
	Mix_FreeMusic( gMusic );
	gMusic = NULL;
	Mix_FreeChunk( gDisappear );
	gDisappear = NULL;
	Mix_FreeChunk( gDrop );
	gDrop = NULL;
	Mix_FreeChunk( gAddblobk );
	gAddblobk = NULL;
	Mix_FreeChunk( gGameover );
	gGameover = NULL;

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

unsigned int addblock(unsigned int interval, void * param)
{
	short* posx = new short;
	short* posy = new short;
	short* color = new short;
	while (1)
	{
		srand(time(NULL));
		*posx = 1 + rand() % 10;
		*posy = 1 + rand() % 10;
		*color = 1 + rand() % 11;
		if( arr_game_screen[*posx][*posy] == 0 )
		{
			arr_game_screen[*posx][*posy] = *color;
			effect(gAddblobk);
			break;
		}
	}
	delete posx;
	delete posy;
	delete color;
	return interval;
}

void run_term()
{
	if ( allow_to_save == false )
	{
		term =SDL_AddTimer(challenge,addblock,NULL);
	}
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
		while( SDL_PollEvent( &e ) != 0 )
		{
			Blit(300,480,500,200,gStretchedScreen[Leave],gScreenSurface);
			SDL_UpdateWindowSurface( gWindow );
			if( SDL_MOUSEBUTTONDOWN )
			{
				if(e.button.button == SDL_BUTTON_LEFT)
				{
					if(400<=e.motion.x && e.motion.x<=450 && 580<=e.motion.y && e.motion.y<=630)
					{
						return true;
					}
					else if(655<=e.motion.x && e.motion.x<=700 && 580<=e.motion.y && e.motion.y<=630)
					{
						return false;
					}
				}
			}
		}
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
		file(2,&player_highscore,&challenger_highscore,&theme);//get highscore-theme from file
	}
	//Event handler
	while(1)
	{
		while( SDL_PollEvent( &e ) != 0 )
		{
			Blit(0,0,1100,700,gStretchedScreen[Start],gScreenSurface);
			printscore(player_highscore,510,250,1);
			SDL_UpdateWindowSurface( gWindow );
			if(e.type == SDL_QUIT)
			{
				if(leavegame()== true) return false;
				else if(leavegame() == false) continue;
			}
			if( SDL_MOUSEBUTTONDOWN )
			{
				if(e.button.button == SDL_BUTTON_LEFT)
				{
					if(370<=e.motion.x && e.motion.x<=540 && 310<=e.motion.y && e.motion.y<=435)
					{
						allow_to_save =true;
						return true;
					}
					if(550<=e.motion.x && e.motion.x<=715 && 310<=e.motion.y && e.motion.y<=5435)
					{
						allow_to_save = false;
						run_term();
						return true;
					}
					if(370<=e.motion.x && e.motion.x<=480 && 430<=e.motion.y && e.motion.y<=535)
					{
						savegame(2,&player_score,arr_game_screen,arr_game_creat,&game_block_in);
						return true;
					}
					if(490<=e.motion.x && e.motion.x<=600 && 430<=e.motion.y && e.motion.y<=535)
					{
						if( leavegame() == true) return false;
						else if( leavegame() == false ) continue;
					}
					if(605<=e.motion.x && e.motion.x<=715 && 430<=e.motion.y && e.motion.y<=535)
					{
						player_highscore =0;
						challenger_highscore = 0;
						player_score = 0;
						console(arr_game_screen);
						arr_game_creat_random(arr_game_get_block,arr_game_creat,&game_block_in);
					}

				}
			}
		}
	}
}

void adnimation(short temp,short x,short y,short length,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface)
{
	if(temp == 1)
	{
		short* temp = new short;*temp = 50;
		while(*temp < length -1)
		{
			output();
			Blit(x,y,50,*temp,gStretchedTemp,gScreenSurface);
			*temp+=10;
			SDL_Delay(5);
			SDL_UpdateWindowSurface(gWindow);
		}
		delete temp;
	}
	else if(temp == 2)
	{
		short* temp = new short;*temp = 250;
		while(*temp > 50)
		{
			output();
			Blit(x,y,50,*temp,gStretchedTemp,gScreenSurface);
			*temp-=10;
			SDL_Delay(5);
			SDL_UpdateWindowSurface(gWindow);
		}
		delete temp;
	}
}
void home_button()
{
	output();
    Blit(2,52,50,250,gStretchedScreen[Homechose],gScreenSurface);
}

bool menuchose(SDL_Event e)
{
	adnimation(1,2,52,250,gStretchedScreen[Homechose],gScreenSurface);
	SDL_RemoveTimer(term);
	while( 1 )
	{
		do
		{
			home_button();
			SDL_UpdateWindowSurface( gWindow );
			if( SDL_MOUSEBUTTONDOWN )
			{
				if(e.button.button == SDL_BUTTON_LEFT)
				{
					if(2<=e.motion.x && e.motion.x<=52 && 253<=e.motion.y && e.motion.y<=302)
					{
						adnimation(2,2,52,250,gStretchedScreen[Homechose],gScreenSurface);
						run_term();
						return false;
					}
					if(2<=e.motion.x && e.motion.x<=52 && 103<=e.motion.y && e.motion.y<=152)
					{
						console(arr_game_screen);
						arr_game_creat_random(arr_game_get_block,arr_game_creat,&game_block_in);
						player_score=0;
						run_term();
						return false;
					}
					if(2<=e.motion.x && e.motion.x<=52 && 53<=e.motion.y && e.motion.y<=102)
					{
						console(arr_game_screen);
						arr_game_creat_random(arr_game_get_block,arr_game_creat,&game_block_in);
						player_score=0;
						if(newgame(0) == true) return false;
						else
						{
							run_term();
							return true;
						}
					}
					if(2<=e.motion.x && e.motion.x<=52 && 153<=e.motion.y && e.motion.y<=202)
					{
						if(allow_to_save == true)
						{
							savegame(1,&player_score,arr_game_screen,arr_game_creat,&game_block_in);
							return true;
						}
					}
					if(2<=e.motion.x && e.motion.x<=52 && 203<=e.motion.y && e.motion.y<=252)
					{
						if( leavegame()==true) return true;
						else
						{
							run_term();
							return false;
						}
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
	Blit(300,200,500,100,gStretchedScreen[Dead],gScreenSurface);
	Blit(1048,2,50,50,gStretchedScreen[View],gScreenSurface);
}

bool deadchose(SDL_Event e)
{
	while(1)
	{
		while( SDL_PollEvent( &e ) != 0 )
		{
			dead();
			SDL_UpdateWindowSurface( gWindow );
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
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
}


void setting_menu()
{
	output();
	Blit(1048,52,50,300,gStretchedScreen[Settingchose],gScreenSurface);
	if(state_sound == false) Blitsound(1,1050,255,gStretchedScreen[Sound],gScreenSurface);
	else					  Blitsound(2,1077,255,gStretchedScreen[Sound],gScreenSurface);
	if(state_music == false) Blitsound(3,1050,279,gStretchedScreen[Sound],gScreenSurface);
	else					  Blitsound(4,1077,279,gStretchedScreen[Sound],gScreenSurface);
}

void setting_chose()
{
	adnimation(1,1048,52,300,gStretchedScreen[Settingchose],gScreenSurface);
	SDL_RemoveTimer(term);
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
					if(1048<=e.motion.x && e.motion.x<=1098 && 303<=e.motion.y && e.motion.y<=352)
					{
						adnimation(2,1048,52,300,gStretchedScreen[Settingchose],gScreenSurface);
						quit =true;
						run_term();
						break;
					}
					if(1048<=e.motion.x && e.motion.x<=1098 && 53<=e.motion.y && e.motion.y<=102)
					{
						theme =1;
					}
					if(1048<=e.motion.x && e.motion.x<=1098 && 103<=e.motion.y && e.motion.y<=152)
					{
						theme =2;
					}
					if(1048<=e.motion.x && e.motion.x<=1098 && 153<=e.motion.y && e.motion.y<=202)
					{
						theme =3;
					}
					if(1048<=e.motion.x && e.motion.x<=1098 && 203<=e.motion.y && e.motion.y<=252)
					{
						theme =4;
					}
					if(state_sound == false && 1050<=e.motion.x && e.motion.x<=1071 && 255<=e.motion.y && e.motion.y<=276)
					{
						state_sound =true;
					}
					if(state_sound == true && 1077<=e.motion.x && e.motion.x<=1098 && 255<=e.motion.y && e.motion.y<=276)
					{
						state_sound = false;
					}
					if(state_music == false && 1050<=e.motion.x && e.motion.x<=1071 && 279<=e.motion.y && e.motion.y<=300)
					{
						state_music = true;
						audio(gMusic);
					}
					if(state_music == true && 1077<=e.motion.x && e.motion.x<=1098 && 279<=e.motion.y && e.motion.y<=300)
					{
						state_music = false;
						audio(gMusic);
					}
				}
			}
		}

	}
}

void output()
{
	short* i = new short;
	short* j = new short;
	BlitBackground(theme,gStretchedScreen[Background],gScreenSurface);
	Blit(2,2,50,50,gStretchedScreen[Home],gScreenSurface);
    Blit(1048,2,50,50,gStretchedScreen[Setting],gScreenSurface);
	if(player_score < player_highscore)
	{
		BlitCup(theme,1,60,280,gStretchedScreen[Cup],gScreenSurface);
		printscore(player_score,110,230,theme);
		if(allow_to_save ==true)
		{
			printscore(player_highscore,110,450,theme);
		}
		else printscore(challenger_highscore,110,450,theme);
	}
	else
	{
		BlitCup(theme,0,60,280,gStretchedScreen[Cup],gScreenSurface);
		if(allow_to_save ==true)
		{
			printscore(player_highscore,110,450,theme);
		}
		else printscore(challenger_highscore,110,450,theme);
	}
	for(*i=300;*i<=750;(*i)+=B) // w
	{
		for(*j=150;*j<=600;(*j)+=B) //h
		{
			short* arr_game_pos_x = new short;	*arr_game_pos_x=(*i-250)/B;
			short* arr_game_pos_y = new short;	*arr_game_pos_y=(*j-100)/B;

			if( arr_game_screen[*arr_game_pos_y][*arr_game_pos_x] > -1 )
			{
				BlitBigBlock(arr_game_screen[*arr_game_pos_y][*arr_game_pos_x],*i,*j,gStretchedBlock,gScreenSurface);
			}
			delete arr_game_pos_x;
			delete arr_game_pos_y;
		}
	}
	for(*i=210;*i<=570;(*i)+=180)
		{
			if(arr_game_creat[1][*i]!=0);
			draw_shape(900,*i,blockS,arr_game_creat[1][(*i-30)/180],arr_game_creat[2][(*i-30)/180],arr_game_get_block,gStretchedBlock,gScreenSurface);		}
	delete i;
	delete j;
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
			if(state_sound==true) effect(gDisappear);
			for(  *k=1;*k<=10;(*k)++)
			{
				arr_game_screen[*i][*k]=0;
				output();
				SDL_Delay(15);
				SDL_UpdateWindowSurface( gWindow );
			}
			player_score+=10;

		}
		if(colum[*i]==*i)
		{
			if(state_sound==true) effect(gDisappear);
			for( *k=1;*k<=10;(*k)++)
			{
				arr_game_screen[*k][*i]=0;
				output();
				SDL_Delay(15);
				SDL_UpdateWindowSurface( gWindow );
			}
			player_score+=10;

		}
	}
	delete i;
	delete k;
	delete [] row;
	delete [] colum;
}



void deadanimation()
{
	short *i = new short;
	short *j = new short;
	effect(gGameover);
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
				BlitBigBlock(12,*i,*j,gStretchedBlock,gScreenSurface);
				SDL_Delay(25);
				SDL_UpdateWindowSurface( gWindow );
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
				while( quit == false )
				{
					//Handle events on queue
					while( SDL_PollEvent( &e ) != 0 || SDL_PollEvent(&e) == 0 )
					{
						output();
						if(e.type == SDL_QUIT)
						{
							if(leavegame()==true)
							{
								quit=true;
								break;
							}
							if(leavegame()==false) continue;
						}
						if(game_block_in == 0)
						{
							arr_game_creat_random(arr_game_get_block,arr_game_creat,&game_block_in);
						}
						if( gameover() == true )
						{
							SDL_RemoveTimer(term);
							deadanimation();
							quit=deadchose(e);
							if (quit == true ) break;
						}
						else
						{
							dropin=0;dropped=0;
							posX=(e.motion.x-810)/30,posY=(e.motion.y-120)/30;
							comparision(&player_score,&player_highscore,&challenger_highscore,&allow_to_save);
							if( SDL_MOUSEBUTTONDOWN )
							{
								if(e.button.button == SDL_BUTTON_LEFT)
								{
									if(2<=e.motion.x && e.motion.x<=52 && 2<=e.motion.y && e.motion.y<=52)
									{
										dropped=1;
										quit=menuchose(e);
										if (quit == true ) break;
									}
									if(1048<=e.motion.x && e.motion.x<=1098 && 2<=e.motion.y && e.motion.y<=52)
									{
										dropped=1;
										setting_chose();
									}
									if(300<=e.motion.x && e.motion.x<=800 && 150<=e.motion.y && e.motion.y<=650)
									{
										drop(e.motion.x,e.motion.y,tempshape,tempcolor,1,arr_game_screen,&dropin,&lifesign);
										output();
										if(dropin==1)
										{
											if(state_sound==true)
											{
												effect(gDrop);
											}
											cleararea(posofshape,arr_game_creat,arr_game_get_block);
											game_block_in--;
											tempcolor=0;
											tempshape=0;
										}
										delete_full_row_or_colum();
									}
									if(1<=posX && posX<=5 && 1<=posY && posY<=17)
									{
										if( 1 <= arr_game_get_block[posY][posX] && arr_game_get_block[posY][posX]<=19)
										{
											if(150<=e.motion.y && e.motion.y<=300)
											{
												tempcolor = arr_game_creat[2][1];
												posofshape=1;
											}
											if(330<=e.motion.y && e.motion.y<=480)
											{
												tempcolor = arr_game_creat[2][2];
												posofshape=2;
											}
											if(510<=e.motion.y && e.motion.y<=660)
											{
												tempcolor = arr_game_creat[2][3];
												posofshape=3;
											}
											tempshape=arr_game_get_block[posY][posX];
										}
									}
								}
								if(e.button.button == SDL_BUTTON_RIGHT)
								{
									dropped=1;
									tempcolor=0;
									tempshape=0;
								}
							}
							if( dropped==0)
							{
								draw_shape(e.motion.x-25,e.motion.y-25,blockB,tempshape,tempcolor,arr_game_get_block,gStretchedBlock,gScreenSurface);
							}

						}
						//Update the surface
						SDL_UpdateWindowSurface( gWindow );
					}
				}
			}
		}
	}
	// print highscore-theme to file
	file(1,&player_highscore,&challenger_highscore,&theme);
	//Free resources and close SDL
	close();
	return 0;
}
