#include "use_sdl.h"

void Blit(short x,short y,short w,short h,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface)
{
	SDL_Rect temp;
	temp.x = x;	temp.y = y;	temp.w = w;	temp.h = h;
	SDL_BlitSurface(gStretchedTemp,0,gScreenSurface,&temp);
}

void Blitnumber(short theme,short number,short x,short y,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface)
{
	short* w = new short;		*w=15;
	short* h = new short;		*h=20;
	switch(theme)
	{
		case 1:
		{
			SDL_Rect sound;
			sound.x=15*number;	sound.y=(theme-1)*(*h);	sound.w=*w;	sound.h=*h;
			SDL_Rect temp;
			temp.x = x;	temp.y = y;	temp.w = *w;	temp.h = *h;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
		case 2:
		{
			SDL_Rect sound;
			sound.x=15*number;	sound.y=(theme-1)*(*h);	sound.w=*w;	sound.h=*h;
			SDL_Rect temp;
			temp.x = x;	temp.y = y;	temp.w = *w;	temp.h = *h;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
		case 3:
		{
			SDL_Rect sound;
			sound.x=15*number;	sound.y=(theme-1)*(*h);	sound.w=*w;	sound.h=*h;
			SDL_Rect temp;
			temp.x = x;	temp.y = y;	temp.w = *w;	temp.h = *h;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
		case 4:
		{
			SDL_Rect sound;
			sound.x=15*number;	sound.y=(theme-1)*(*h);	sound.w=*w;	sound.h=*h;
			SDL_Rect temp;
			temp.x = x;	temp.y = y;	temp.w = *w;	temp.h = *h;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
	}
	delete w;
	delete h;
}

void BlitBackground(short theme,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface)
{
	short* width = new short;		*width = 1100;
	short* height = new short;		*height = 700;
	switch(theme)
	{
		case 1:
		{
			SDL_Rect sound;
			sound.x=0;	sound.y=(theme-1)*(*height);	sound.w=*width;	sound.h=*height;
			SDL_Rect temp;
			temp.x = 0;	temp.y = 0;	temp.w = *width;	temp.h = *height;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
		case 2:
		{
			SDL_Rect sound;
			sound.x=0;	sound.y=(theme-1)*(*height);	sound.w=*width;	sound.h=*height;
			SDL_Rect temp;
			temp.x = 0;	temp.y = 0;	temp.w = *width;	temp.h = *height;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
		case 3:
		{
			SDL_Rect sound;
			sound.x=0;	sound.y=(theme-1)*(*height);	sound.w=*width;	sound.h=*height;
			SDL_Rect temp;
			temp.x = 0;	temp.y = 0;	temp.w = *width;	temp.h = *height;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
		case 4:
		{
			SDL_Rect sound;
			sound.x=0;	sound.y=(theme-1)*(*height);	sound.w=*width;	sound.h=*height;
			SDL_Rect temp;
			temp.x = 0;	temp.y = 0;	temp.w =*width;	temp.h = *height;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
	}
	delete width;
	delete height;
}

void BlitCup(short theme,short cup,short x,short y,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface)//0 = gold, 1 = silver
{
	short* length = new short; *length =160;
	switch(theme)
	{
		case 1:
		{
			SDL_Rect sound;
			sound.x=cup*(*length);	sound.y=(theme-1)*(*length);	sound.w = *length;	sound.h = *length;
			SDL_Rect temp;
			temp.x = x;	temp.y = y;	temp.w = *length;	temp.h = *length;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
		case 2:
		{
			SDL_Rect sound;
			sound.x=cup*(*length);	sound.y=(theme-1)*(*length);	sound.w=*length;	sound.h=*length;
			SDL_Rect temp;
			temp.x = x;	temp.y = y;	temp.w = *length;	temp.h = *length;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
		case 3:
		{
			SDL_Rect sound;
			sound.x=cup*(*length);	sound.y=(theme-1)*(*length);	sound.w=*length;	sound.h=*length;
			SDL_Rect temp;
			temp.x = x;	temp.y = y;	temp.w = *length;	temp.h = *length;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
		case 4:
		{
			SDL_Rect sound;
			sound.x=cup*(*length);	sound.y=(theme-1)*(*length);	sound.w=*length;	sound.h=*length;
			SDL_Rect temp;
			temp.x = x;	temp.y = y;	temp.w = *length;	temp.h = *length;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
	}
	delete length;
}

void BlitBigBlock(short number,short x,short y,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface)
{

	SDL_Rect sound;
	SDL_Rect temp;
	sound.x=48*number;	sound.y=0;	sound.w=48;	sound.h=44;
	temp.x = x+1;	temp.y = y+3;	temp.w = 48;	temp.h = 44;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);

	//top of block
	sound.x=48*number;	sound.y=0;	sound.w=44;	sound.h=1;
	temp.x = x+3;	temp.y = y+1;	temp.w = 44;	temp.h = 1;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);

	sound.x=48*number;	sound.y=0;	sound.w=46;	sound.h=1;
	temp.x = x+2;	temp.y = y+2;	temp.w = 46;	temp.h = 1;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);

	//bottom of block
	sound.x=48*number;	sound.y=0;	sound.w=44;	sound.h=1;
	temp.x = x+3;	temp.y = y+48;	temp.w = 44;	temp.h = 1;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);

	sound.x=48*number;	sound.y=0;	sound.w=46;	sound.h=1;
	temp.x = x+2;	temp.y = y+47;	temp.w = 46;	temp.h = 1;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
}

void BlitSmallBlock(short number,short x,short y,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface)
{
	SDL_Rect sound;
	SDL_Rect temp;
	sound.x=28*number;	sound.y=0;	sound.w=28;	sound.h=24;
	temp.x = x+1;	temp.y = y+3;	temp.w = 28;	temp.h = 24;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);

	//top of block
	sound.x=28*number;	sound.y=0;	sound.w=24;	sound.h=1;
	temp.x = x+3;	temp.y = y+1;	temp.w = 24;	temp.h = 1;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);

	sound.x=28*number;	sound.y=0;	sound.w=26;	sound.h=1;
	temp.x = x+2;	temp.y = y+2;	temp.w = 26;	temp.h = 1;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);

	//bottom of block
	sound.x=28*number;	sound.y=0;	sound.w=26;	sound.h=1;
	temp.x = x+2;	temp.y = y+27;	temp.w = 26;	temp.h = 1;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);

	sound.x=28*number;	sound.y=0;	sound.w=24;	sound.h=1;
	temp.x = x+3;	temp.y = y+28;	temp.w = 24;	temp.h = 1;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
}


void draw_shape(short x,short y, short status,short shape, short color,short arr_game_get_block[18][6],SDL_Surface* gStretchedBlockB,SDL_Surface* gStretchedBlockS,SDL_Surface* gScreenSurface)
{
	short* B = new short;*B=50;
	short* S = new short;*S=30;
	SDL_Rect* creat = new SDL_Rect [10];
	short* tempx = new short [10];
	short* tempy = new short [10];
	short* posY = new short;*posY =(y-120)/30;//h
	short* posX = new short;*posX =(x-810)/30;//w
	switch (shape)
	{
		case 0: break;
		case 1:
			{
				if(status==1)
				{
					arr_game_get_block[*posY][*posX]=1;
                    BlitSmallBlock(color,x,y,gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					BlitBigBlock(color,x,y,gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 2:
			{
				if(status==1)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x-*S;	tempy[2] = y;
					arr_game_get_block[*posY][*posX]=2;
					arr_game_get_block[*posY][*posX-1]=2;
					for(int i=1;i<=2;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x-*B;	tempy[2] = y;
					for(int i=1;i<=2;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 3:
			{
				if(status==1)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x;		tempy[2] = y-*S;
					arr_game_get_block[*posY][*posX]=3;
					arr_game_get_block[*posY-1][*posX]=3;
					for(int i=1;i<=2;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x;		tempy[2] = y-*B;
					for(int i=1;i<=2;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 4:
			{
				if(status==1)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x+*S;	tempy[2] = y;
					tempx[3] = x-*S;	tempy[3] = y;
					arr_game_get_block[*posY][*posX]=4;
					arr_game_get_block[*posY][*posX+1]=4;
					arr_game_get_block[*posY][*posX-1]=4;
					for(int i=1;i<=3;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x+*B;	tempy[2] = y;
					tempx[3] = x-*B;	tempy[3] = y;
					for(int i=1;i<=3;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 5:
			{
				if(status==1)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x;		tempy[2] = y+*S;
					tempx[3] = x;		tempy[3] = y-*S;
					arr_game_get_block[*posY][*posX]=5;
					arr_game_get_block[*posY+1][*posX]=5;
					arr_game_get_block[*posY-1][*posX]=5;
					for(int i=1;i<=3;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x;		tempy[2] = y+*B;
					tempx[3] = x;		tempy[3] = y-*B;
					for(int i=1;i<=3;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 6:
			{
				if(status==1)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x-*S;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y-*S;
					arr_game_get_block[*posY][*posX]=6;
					arr_game_get_block[*posY][*posX-1]=6;
					arr_game_get_block[*posY-1][*posX]=6;
					for(int i=1;i<=3;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x-*B;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y-*B;
					for(int i=1;i<=3;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 7:
			{
				if(status==1)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x+*S;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y-*S;
					arr_game_get_block[*posY][*posX]=7;
					arr_game_get_block[*posY][*posX+1]=7;
					arr_game_get_block[*posY-1][*posX]=7;
					for(int i=1;i<=3;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x+*B;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y-*B;
					for(int i=1;i<=3;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 8:
			{
				if(status==1)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x-*S;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y+*S;
					arr_game_get_block[*posY][*posX]=8;
					arr_game_get_block[*posY][*posX-1]=8;
					arr_game_get_block[*posY+1][*posX]=8;
					for(int i=1;i<=3;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x-*B;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y+*B;
					for(int i=1;i<=3;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 9:
			{
				if(status==1)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x+*S;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y+*S;
					arr_game_get_block[*posY][*posX]=9;
					arr_game_get_block[*posY][*posX+1]=9;
					arr_game_get_block[*posY+1][*posX]=9;
					for(int i=1;i<=3;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x+*B;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y+*B;
					for(int i=1;i<=3;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 10:
			{
				if(status==1)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x+*S;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y+*S;
					tempx[4] = x+*S;	tempy[4] = y+*S;
					arr_game_get_block[*posY][*posX]=10;
					arr_game_get_block[*posY][*posX+1]=10;
					arr_game_get_block[*posY+1][*posX]=10;
					arr_game_get_block[*posY+1][*posX+1]=10;
					for(int i=1;i<=4;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x+*B;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y+*B;
					tempx[4] = x+*B;	tempy[4] = y+*B;
					for(int i=1;i<=4;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 11:
			{
				if(status==1)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x-*S;		tempy[2] = y;
					tempx[3] = x+*S;		tempy[3] = y;
					tempx[4] = x+2*(*S);	tempy[4] = y;
					arr_game_get_block[*posY][*posX]=11;
					arr_game_get_block[*posY][*posX-1]=11;
					arr_game_get_block[*posY][*posX+1]=11;
					arr_game_get_block[*posY][*posX+2]=11;
					for(int i=1;i<=4;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x-*B;		tempy[2] = y;
					tempx[3] = x+*B;		tempy[3] = y;
					tempx[4] = x+2*(*B);	tempy[4] = y;
					for(int i=1;i<=4;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 12:
			{
				if(status==1)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x;		tempy[2] = y-*S;
					tempx[3] = x;		tempy[3] = y+*S;
					tempx[4] = x;		tempy[4] = y+2*(*S);
					arr_game_get_block[*posY][*posX]=12;
					arr_game_get_block[*posY-1][*posX]=12;
					arr_game_get_block[*posY+1][*posX]=12;
					arr_game_get_block[*posY+2][*posX]=12;
					for(int i=1;i<=4;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x;		tempy[2] = y-*B;
					tempx[3] = x;		tempy[3] = y+*B;
					tempx[4] = x;		tempy[4] = y+2*(*B);
					for(int i=1;i<=4;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 13:
			{
				if(status==1)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x-*S;		tempy[2] = y;
					tempx[3] = x-2*(*S);	tempy[3] = y;
					tempx[4] = x+(*S);		tempy[4] = y;
					tempx[5] = x+2*(*S);	tempy[5] = y;
					arr_game_get_block[*posY][*posX]=13;
					arr_game_get_block[*posY][*posX-1]=13;
					arr_game_get_block[*posY][*posX-2]=13;
					arr_game_get_block[*posY][*posX+1]=13;
					arr_game_get_block[*posY][*posX+2]=13;
					for(int i=1;i<=5;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x-*B;		tempy[2] = y;
					tempx[3] = x-2*(*B);	tempy[3] = y;
					tempx[4] = x+(*B);		tempy[4] = y;
					tempx[5] = x+2*(*B);	tempy[5] = y;
					for(int i=1;i<=5;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 14:
			{
				if(status==1)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x;		tempy[2] = y-*S;
					tempx[3] = x;		tempy[3] = y-2*(*S);
					tempx[4] = x;		tempy[4] = y+(*S);
					tempx[5] = x;		tempy[5] = y+2*(*S);
					arr_game_get_block[*posY][*posX]=14;
					arr_game_get_block[*posY-1][*posX]=14;
					arr_game_get_block[*posY-2][*posX]=14;
					arr_game_get_block[*posY+1][*posX]=14;
					arr_game_get_block[*posY+2][*posX]=14;
					for(int i=1;i<=5;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x;		tempy[2] = y-*B;
					tempx[3] = x;		tempy[3] = y-2*(*B);
					tempx[4] = x;		tempy[4] = y+(*B);
					tempx[5] = x;		tempy[5] = y+2*(*B);
					for(int i=1;i<=5;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 15:
			{
				if(status==1)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x;			tempy[2] = y-*S;
					tempx[3] = x;			tempy[3] = y-2*(*S);
					tempx[4] = x-*S;		tempy[4] = y;
					tempx[5] = x-2*(*S);	tempy[5] = y;
					arr_game_get_block[*posY][*posX]=15;
					arr_game_get_block[*posY-1][*posX]=15;
					arr_game_get_block[*posY-2][*posX]=15;
					arr_game_get_block[*posY][*posX-1]=15;
					arr_game_get_block[*posY][*posX-2]=15;
					for(int i=1;i<=5;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x;			tempy[2] = y-*B;
					tempx[3] = x;			tempy[3] = y-2*(*B);
					tempx[4] = x-*B;		tempy[4] = y;
					tempx[5] = x-2*(*B);	tempy[5] = y;
					for(int i=1;i<=5;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 16:
			{
				if(status==1)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x;			tempy[2] = y-(*S);
					tempx[3] = x;			tempy[3] = y-2*(*S);
					tempx[4] = x+*S;		tempy[4] = y;
					tempx[5] = x+2*(*S);	tempy[5] = y;
					arr_game_get_block[*posY][*posX]=16;
					arr_game_get_block[*posY-1][*posX]=16;
					arr_game_get_block[*posY-2][*posX]=16;
					arr_game_get_block[*posY][*posX+1]=16;
					arr_game_get_block[*posY][*posX+2]=16;
					for(int i=1;i<=5;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x;			tempy[2] = y-(*B);
					tempx[3] = x;			tempy[3] = y-2*(*B);
					tempx[4] = x+*B;		tempy[4] = y;
					tempx[5] = x+2*(*B);	tempy[5] = y;
					for(int i=1;i<=5;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 17:
			{
				if(status==1)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x;			tempy[2] = y+*S;
					tempx[3] = x;			tempy[3] = y+2*(*S);
					tempx[4] = x+*S;		tempy[4] = y;
					tempx[5] = x+2*(*S);	tempy[5] = y;
					arr_game_get_block[*posY][*posX]=17;
					arr_game_get_block[*posY+1][*posX]=17;
					arr_game_get_block[*posY+2][*posX]=17;
					arr_game_get_block[*posY][*posX+1]=17;
					arr_game_get_block[*posY][*posX+2]=17;
					for(int i=1;i<=5;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x;			tempy[2] = y+*B;
					tempx[3] = x;			tempy[3] = y+2*(*B);
					tempx[4] = x+*B;		tempy[4] = y;
					tempx[5] = x+2*(*B);	tempy[5] = y;
					for(int i=1;i<=5;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 18:
			{
				if(status==1)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x;			tempy[2] = y+*S;
					tempx[3] = x;			tempy[3] = y+2*(*S);
					tempx[4] = x-*S;		tempy[4] = y;
					tempx[5] = x-2*(*S);	tempy[5] = y;
					arr_game_get_block[*posY][*posX]=18;
					arr_game_get_block[*posY+1][*posX]=18;
					arr_game_get_block[*posY+2][*posX]=18;
					arr_game_get_block[*posY][*posX-1]=18;
					arr_game_get_block[*posY][*posX-2]=18;
					for(int i=1;i<=5;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x;			tempy[2] = y+*B;
					tempx[3] = x;			tempy[3] = y+2*(*B);
					tempx[4] = x-*B;		tempy[4] = y;
					tempx[5] = x-2*(*B);	tempy[5] = y;
					for(int i=1;i<=5;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
		case 19:
			{
				if(status==1)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x-*S;	tempy[2] = y-*S;
					tempx[3] = x;		tempy[3] = y-*S;
					tempx[4] = x+*S;	tempy[4] = y-*S;
					tempx[5] = x-*S;	tempy[5] = y;
					tempx[6] = x+*S;	tempy[6] = y;
					tempx[7] = x-*S;	tempy[7] = y+*S;
					tempx[8] = x;		tempy[8] = y+*S;
					tempx[9] = x+*S;	tempy[9] = y+*S;
					arr_game_get_block[*posY][*posX]=19;
					arr_game_get_block[*posY-1][*posX-1]=19;
					arr_game_get_block[*posY-1][*posX]=19;
					arr_game_get_block[*posY-1][*posX+1]=19;
					arr_game_get_block[*posY][*posX-1]=19;
					arr_game_get_block[*posY][*posX+1]=19;
					arr_game_get_block[*posY+1][*posX-1]=19;
					arr_game_get_block[*posY+1][*posX]=19;
					arr_game_get_block[*posY+1][*posX+1]=19;
					for(int i=1;i<=9;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedBlockS,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x-*B;	tempy[2] = y-*B;
					tempx[3] = x;		tempy[3] = y-*B;
					tempx[4] = x+*B;	tempy[4] = y-*B;
					tempx[5] = x-*B;	tempy[5] = y;
					tempx[6] = x+*B;	tempy[6] = y;
					tempx[7] = x-*B;	tempy[7] = y+*B;
					tempx[8] = x;		tempy[8] = y+*B;
					tempx[9] = x+*B;	tempy[9] = y+*B;
					for(int i=1;i<=9;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedBlockB,gScreenSurface);
				}break;
			}
	}
	delete posX;
	delete posY;
	delete B;
	delete S;
	delete []creat;
	delete []tempx;
	delete []tempy;
}


/*
void Blit(short x,short y,short w,short h, SDL_Surface* tempSurface,SDL_Renderer* gRenderer)
{
	SDL_Texture* texture = NULL;
	SDL_Rect desRect;
	texture = SDL_CreateTextureFromSurface(gRenderer, tempSurface);

	desRect.x = x;
	desRect.y = y;
	desRect.w = w;
	desRect.h = h;
	// copy a portion of the texture to the current rendering target.
	SDL_RenderCopy(gRenderer, texture, 0, &desRect);
	//draw to the screen
}

void draw_shape(short x,short y, short status,short shape, short color,short arr_game_get_block[18][6],SDL_Surface* gStretchedBlockB[13],SDL_Surface* gStretchedBlockS[12],SDL_Renderer* gRenderer)
{
	short* creatx=new short[10];
	short* creaty=new short[10];
	short* creatw=new short[10];
	short* creath=new short[10];
	short* B = new short;*B=50;
	short* S = new short;*S=30;

	short* posY = new short;*posY =(y-120)/30;//h
	short* posX = new short;*posX =(x-810)/30;//w
	switch (shape)
	{
		case 0: break;
		case 1:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=1;
					Blit(creatx[1],creaty[1],creatw[1],creatw[1],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					Blit(creatx[1],creaty[1],creatw[1],creath[1],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 2:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=2;
					creatx[2] = x-*S;	creaty[2] = y;		creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY][*posX-1]=2;
					for(int i=1;i<=2;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x-*B;	creaty[2] = y;		creatw[2] = *B;		creath[2] = *B;
					for(int i=1;i<=2;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 3:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=3;
					creatx[2] = x;		creaty[2] = y-*S;	creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY-1][*posX]=3;
					for(int i=1;i<=2;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x;		creaty[2] = y-*B;	creatw[2] = *B;		creath[2] = *B;
					for(int i=1;i<=2;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 4:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=4;
					creatx[2] = x+*S;	creaty[2] = y;		creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY][*posX+1]=4;
					creatx[3] = x-*S;	creaty[3] = y;		creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY][*posX-1]=4;
					for(int i=1;i<=3;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x+*B;	creaty[2] = y;		creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x-*B;	creaty[3] = y;		creatw[3] = *B;		creath[3] = *B;
					for(int i=1;i<=3;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 5:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=5;
					creatx[2] = x;		creaty[2] = y+*S;	creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY+1][*posX]=5;
					creatx[3] = x;		creaty[3] = y-*S;	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY-1][*posX]=5;
					for(int i=1;i<=3;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x;		creaty[2] = y+*B;	creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y-*B;	creatw[3] = *B;		creath[3] = *B;
					for(int i=1;i<=3;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 6:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=6;
					creatx[2] = x-*S;	creaty[2] = y;		creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY][*posX-1]=6;
					creatx[3] = x;		creaty[3] = y-*S;	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY-1][*posX]=6;
					for(int i=1;i<=3;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x-*B;	creaty[2] = y;		creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y-*B;	creatw[3] = *B;		creath[3] = *B;
					for(int i=1;i<=3;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 7:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=7;
					creatx[2] = x+*S;	creaty[2] = y;		creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY][*posX+1]=7;
					creatx[3] = x;		creaty[3] = y-*S;	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY-1][*posX]=7;
					for(int i=1;i<=3;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x+*B;	creaty[2] = y;		creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y-*B;	creatw[3] = *B;		creath[3] = *B;
					for(int i=1;i<=3;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 8:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=8;
					creatx[2] = x-*S;	creaty[2] = y;		creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY][*posX-1]=8;
					creatx[3] = x;		creaty[3] = y+*S;	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY+1][*posX]=8;
					for(int i=1;i<=3;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x-*B;	creaty[2] = y;		creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y+*B;	creatw[3] = *B;		creath[3] = *B;
					for(int i=1;i<=3;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 9:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=9;
					creatx[2] = x+*S;	creaty[2] = y;		creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY][*posX+1]=9;
					creatx[3] = x;		creaty[3] = y+*S;	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY+1][*posX]=9;
					for(int i=1;i<=3;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x+*B;	creaty[2] = y;		creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y+*B;	creatw[3] = *B;		creath[3] = *B;
					for(int i=1;i<=3;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 10:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=10;
					creatx[2] = x+*S;	creaty[2] = y;		creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY][*posX+1]=10;
					creatx[3] = x;		creaty[3] = y+*S;	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY+1][*posX]=10;
					creatx[4] = x+*S;	creaty[4] = y+*S;	creatw[4] = *S;		creath[4] = *S;		arr_game_get_block[*posY+1][*posX+1]=10;
					for(int i=1;i<=4;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x+*B;	creaty[2] = y;		creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y+*B;	creatw[3] = *B;		creath[3] = *B;
					creatx[4] = x+*B;	creaty[4] = y+*B;	creatw[4] = *B;		creath[4] = *B;
					for(int i=1;i<=4;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 11:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=11;
					creatx[2] = x-*S;	creaty[2] = y;		creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY][*posX-1]=11;
					creatx[3] = x+*S;	creaty[3] = y;		creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY][*posX+1]=11;
					creatx[4] = x+2*(*S);	creaty[4] = y;		creatw[4] = *S;		creath[4] = *S;		arr_game_get_block[*posY][*posX+2]=11;
					for(int i=1;i<=4;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x-*B;	creaty[2] = y;		creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x+*B;	creaty[3] = y;		creatw[3] = *B;		creath[3] = *B;
					creatx[4] = x+2*(*B);	creaty[4] = y;		creatw[4] = *B;		creath[4] = *B;
					for(int i=1;i<=4;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 12:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=12;
					creatx[2] = x;		creaty[2] = y-*S;	creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY-1][*posX]=12;
					creatx[3] = x;		creaty[3] = y+*S;	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY+1][*posX]=12;
					creatx[4] = x;		creaty[4] = y+2*(*S);	creatw[4] = *S;		creath[4] = *S;		arr_game_get_block[*posY+2][*posX]=12;
					for(int i=1;i<=4;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x;		creaty[2] = y-*B;	creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y+*B;	creatw[3] = *B;		creath[3] = *B;
					creatx[4] = x;		creaty[4] = y+2*(*B);	creatw[4] = *B;		creath[4] = *B;
					for(int i=1;i<=4;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 13:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=13;
					creatx[2] = x-*S;	creaty[2] = y;		creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY][*posX-1]=13;
					creatx[3] = x-2*(*S);	creaty[3] = y;		creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY][*posX-2]=13;
					creatx[4] = x+*S;	creaty[4] = y;		creatw[4] = *S;		creath[4] = *S;		arr_game_get_block[*posY][*posX+1]=13;
					creatx[5] = x+2*(*S);	creaty[5] = y;		creatw[5] = *S;		creath[5] = *S;		arr_game_get_block[*posY][*posX+2]=13;
					for(int i=1;i<=5;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x-*B;	creaty[2] = y;		creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x-2*(*B);	creaty[3] = y;		creatw[3] = *B;		creath[3] = *B;
					creatx[4] = x+(*B);	creaty[4] = y;		creatw[4] = *B;		creath[4] = *B;
					creatx[5] = x+2*(*B);	creaty[5] = y;		creatw[5] = *B;		creath[5] = *B;
					for(int i=1;i<=5;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 14:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=14;
					creatx[2] = x;		creaty[2] = y-*S;	creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY-1][*posX]=14;
					creatx[3] = x;		creaty[3] = y-2*(*S);	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY-2][*posX]=14;
					creatx[4] = x;		creaty[4] = y+*S;	creatw[4] = *S;		creath[4] = *S;		arr_game_get_block[*posY+1][*posX]=14;
					creatx[5] = x;		creaty[5] = y+2*(*S);	creatw[5] = *S;		creath[5] = *S;		arr_game_get_block[*posY+2][*posX]=14;
					for(int i=1;i<=5;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x;		creaty[2] = y-*B;	creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y-2*(*B);	creatw[3] = *B;		creath[3] = *B;
					creatx[4] = x;		creaty[4] = y+(*B);	creatw[4] = *B;		creath[4] = *B;
					creatx[5] = x;		creaty[5] = y+2*(*B);	creatw[5] = *B;		creath[5] = *B;
					for(int i=1;i<=5;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 15:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=15;
					creatx[2] = x;		creaty[2] = y-*S;	creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY-1][*posX]=15;
					creatx[3] = x;		creaty[3] = y-2*(*S);	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY-2][*posX]=15;
					creatx[4] = x-*S;	creaty[4] = y;		creatw[4] = *S;		creath[4] = *S;		arr_game_get_block[*posY][*posX-1]=15;
					creatx[5] = x-2*(*S);	creaty[5] = y;		creatw[5] = *S;		creath[5] = *S;		arr_game_get_block[*posY][*posX-2]=15;
					for(int i=1;i<=5;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x;		creaty[2] = y-*B;	creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y-2*(*B);	creatw[3] = *B;		creath[3] = *B;
					creatx[4] = x-*B;	creaty[4] = y;		creatw[4] = *B;		creath[4] = *B;
					creatx[5] = x-2*(*B);	creaty[5] = y;		creatw[5] = *B;		creath[5] = *B;
					for(int i=1;i<=5;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 16:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=16;
					creatx[2] = x;		creaty[2] = y-*S;	creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY-1][*posX]=16;
					creatx[3] = x;		creaty[3] = y-2*(*S);	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY-2][*posX]=16;
					creatx[4] = x+*S;	creaty[4] = y;		creatw[4] = *S;		creath[4] = *S;		arr_game_get_block[*posY][*posX+1]=16;
					creatx[5] = x+2*(*S);	creaty[5] = y;		creatw[5] = *S;		creath[5] = *S;		arr_game_get_block[*posY][*posX+2]=16;
					for(int i=1;i<=5;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x;		creaty[2] = y-(*B);	creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y-2*(*B);	creatw[3] = *B;		creath[3] = *B;
					creatx[4] = x+*B;	creaty[4] = y;		creatw[4] = *B;		creath[4] = *B;
					creatx[5] = x+2*(*B);	creaty[5] = y;		creatw[5] = *B;		creath[5] = *B;
					for(int i=1;i<=5;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 17:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=17;
					creatx[2] = x;		creaty[2] = y+*S;	creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY+1][*posX]=17;
					creatx[3] = x;		creaty[3] = y+2*(*S);	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY+2][*posX]=17;
					creatx[4] = x+*S;	creaty[4] = y;		creatw[4] = *S;		creath[4] = *S;		arr_game_get_block[*posY][*posX+1]=17;
					creatx[5] = x+2*(*S);	creaty[5] = y;		creatw[5] = *S;		creath[5] = *S;		arr_game_get_block[*posY][*posX+2]=17;
					for(int i=1;i<=5;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x;		creaty[2] = y+*B;	creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y+2*(*B);	creatw[3] = *B;		creath[3] = *B;
					creatx[4] = x+*B;	creaty[4] = y;		creatw[4] = *B;		creath[4] = *B;
					creatx[5] = x+2*(*B);	creaty[5] = y;		creatw[5] = *B;		creath[5] = *B;
					for(int i=1;i<=5;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 18:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=18;
					creatx[2] = x;		creaty[2] = y+*S;	creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY+1][*posX]=18;
					creatx[3] = x;		creaty[3] = y+2*(*S);	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY+2][*posX]=18;
					creatx[4] = x-*S;	creaty[4] = y;		creatw[4] = *S;		creath[4] = *S;		arr_game_get_block[*posY][*posX-1]=18;
					creatx[5] = x-2*(*S);	creaty[5] = y;		creatw[5] = *S;		creath[5] = *S;		arr_game_get_block[*posY][*posX-2]=18;
					for(int i=1;i<=5;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x;		creaty[2] = y+*B;	creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y+2*(*B);	creatw[3] = *B;		creath[3] = *B;
					creatx[4] = x-*B;	creaty[4] = y;		creatw[4] = *B;		creath[4] = *B;
					creatx[5] = x-2*(*B);	creaty[5] = y;		creatw[5] = *B;		creath[5] = *B;
					for(int i=1;i<=5;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
		case 19:
			{
				if(status==1)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *S;		creath[1] = *S;		arr_game_get_block[*posY][*posX]=19;
					creatx[2] = x-*S;	creaty[2] = y-*S;	creatw[2] = *S;		creath[2] = *S;		arr_game_get_block[*posY-1][*posX-1]=19;
					creatx[3] = x;		creaty[3] = y-*S;	creatw[3] = *S;		creath[3] = *S;		arr_game_get_block[*posY-1][*posX]=19;
					creatx[4] = x+*S;	creaty[4] = y-*S;	creatw[4] = *S;		creath[4] = *S;		arr_game_get_block[*posY-1][*posX+1]=19;
					creatx[5] = x-*S;	creaty[5] = y;		creatw[5] = *S;		creath[5] = *S;		arr_game_get_block[*posY][*posX-1]=19;
					creatx[6] = x+*S;	creaty[6] = y;		creatw[6] = *S;		creath[6] = *S;		arr_game_get_block[*posY][*posX+1]=19;
					creatx[7] = x-*S;	creaty[7] = y+*S;	creatw[7] = *S;		creath[7] = *S;		arr_game_get_block[*posY+1][*posX-1]=19;
					creatx[8] = x;		creaty[8] = y+*S;	creatw[8] = *S;		creath[8] = *S;		arr_game_get_block[*posY+1][*posX]=19;
					creatx[9] = x+*S;	creaty[9] = y+*S;	creatw[9] = *S;		creath[9] = *S;		arr_game_get_block[*posY+1][*posX+1]=19;
					for(int i=1;i<=9;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockS[color],gRenderer);
				}
				else if(status==2)
				{
					creatx[1] = x;		creaty[1] = y;		creatw[1] = *B;		creath[1] = *B;
					creatx[2] = x-*B;	creaty[2] = y-*B;	creatw[2] = *B;		creath[2] = *B;
					creatx[3] = x;		creaty[3] = y-*B;	creatw[3] = *B;		creath[3] = *B;
					creatx[4] = x+*B;	creaty[4] = y-*B;	creatw[4] = *B;		creath[4] = *B;
					creatx[5] = x-*B;	creaty[5] = y;		creatw[5] = *B;		creath[5] = *B;
					creatx[6] = x+*B;	creaty[6] = y;		creatw[6] = *B;		creath[6] = *B;
					creatx[7] = x-*B;	creaty[7] = y+*B;	creatw[7] = *B;		creath[7] = *B;
					creatx[8] = x;		creaty[8] = y+*B;	creatw[8] = *B;		creath[8] = *B;
					creatx[9] = x+*B;	creaty[9] = y+*B;	creatw[9] = *B;		creath[9] = *B;
					for(int i=1;i<=9;i++)	Blit(creatx[i],creaty[i],creatw[i],creath[i],gStretchedBlockB[color],gRenderer);
				}break;
			}
	}
	delete posX;
	delete posY;
	delete B;
	delete S;
	delete []creatx;
	delete []creaty;
	delete []creatw;
	delete []creath;
}

*/
