#include "use_sdl.h"

void Blitsound(short temp,short x,short y, SDL_Surface* gStretchedTemp, SDL_Surface* gScreenSurface)
{
    short* w = new short;*w=21;
    short* h = new short;*h=21;
    switch(temp)
    {
		case 1:
		{
			SDL_Rect temp;
			temp.x = x;	temp.y = y;	temp.w = *w;	temp.h = *h;
			SDL_Rect sound;
			sound.x= 0;	sound.y= 0;	sound.w= *w;	sound.h= *h;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
		case 2:
		{
			SDL_Rect temp;
			temp.x = x;	temp.y = y;	temp.w = *w;	temp.h = *h;
			SDL_Rect sound;
			sound.x= 21;	sound.y= 0;	sound.w= *w;	sound.h= *h;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
		case 3:
		{
			SDL_Rect temp;
			temp.x = x;	temp.y = y;	temp.w = *w;	temp.h = *h;
			SDL_Rect sound;
			sound.x= 0;	sound.y= 21;	sound.w= *w;	sound.h= *h;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
		case 4:
		{
			SDL_Rect temp;
			temp.x = x;	temp.y = y;	temp.w = *w;	temp.h = *h;
			SDL_Rect sound;
			sound.x= 21;	sound.y= 21;	sound.w= *w;	sound.h= *h;
			SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
			break;
		}
    }
}

void Blit(short x,short y,short w,short h,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface)
{
	SDL_Rect temp;
	temp.x = x;	temp.y = y;	temp.w = w;	temp.h = h;
	SDL_Rect sound;
	sound.x= 0;	sound.y= 0;	sound.w= w;	sound.h= h;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
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
	sound.x=48*number;	sound.y=0;	sound.w=28;	sound.h=24;
	temp.x = x+1;	temp.y = y+3;	temp.w = 28;	temp.h = 24;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);

	//top of block
	sound.x=48*number;	sound.y=0;	sound.w=24;	sound.h=1;
	temp.x = x+3;	temp.y = y+1;	temp.w = 24;	temp.h = 1;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);

	sound.x=48*number;	sound.y=0;	sound.w=26;	sound.h=1;
	temp.x = x+2;	temp.y = y+2;	temp.w = 26;	temp.h = 1;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);

	//bottom of block
	sound.x=48*number;	sound.y=0;	sound.w=26;	sound.h=1;
	temp.x = x+2;	temp.y = y+27;	temp.w = 26;	temp.h = 1;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);

	sound.x=48*number;	sound.y=0;	sound.w=24;	sound.h=1;
	temp.x = x+3;	temp.y = y+28;	temp.w = 24;	temp.h = 1;
	SDL_BlitSurface(gStretchedTemp,&sound,gScreenSurface,&temp);
}


void draw_shape(short x,short y, short status,short shape, short color,short arr_game_get_block[18][6],SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface)
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
                    BlitSmallBlock(color,x,y,gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					BlitBigBlock(color,x,y,gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=2;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x-*B;	tempy[2] = y;
					for(int i=1;i<=2;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=2;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x;		tempy[2] = y-*B;
					for(int i=1;i<=2;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=3;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x+*B;	tempy[2] = y;
					tempx[3] = x-*B;	tempy[3] = y;
					for(int i=1;i<=3;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=3;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x;		tempy[2] = y+*B;
					tempx[3] = x;		tempy[3] = y-*B;
					for(int i=1;i<=3;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=3;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x-*B;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y-*B;
					for(int i=1;i<=3;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=3;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x+*B;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y-*B;
					for(int i=1;i<=3;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=3;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x-*B;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y+*B;
					for(int i=1;i<=3;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=3;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x+*B;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y+*B;
					for(int i=1;i<=3;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=4;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x+*B;	tempy[2] = y;
					tempx[3] = x;		tempy[3] = y+*B;
					tempx[4] = x+*B;	tempy[4] = y+*B;
					for(int i=1;i<=4;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=4;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x-*B;		tempy[2] = y;
					tempx[3] = x+*B;		tempy[3] = y;
					tempx[4] = x+2*(*B);	tempy[4] = y;
					for(int i=1;i<=4;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=4;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x;		tempy[2] = y-*B;
					tempx[3] = x;		tempy[3] = y+*B;
					tempx[4] = x;		tempy[4] = y+2*(*B);
					for(int i=1;i<=4;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=5;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x-*B;		tempy[2] = y;
					tempx[3] = x-2*(*B);	tempy[3] = y;
					tempx[4] = x+(*B);		tempy[4] = y;
					tempx[5] = x+2*(*B);	tempy[5] = y;
					for(int i=1;i<=5;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=5;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;		tempy[1] = y;
					tempx[2] = x;		tempy[2] = y-*B;
					tempx[3] = x;		tempy[3] = y-2*(*B);
					tempx[4] = x;		tempy[4] = y+(*B);
					tempx[5] = x;		tempy[5] = y+2*(*B);
					for(int i=1;i<=5;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=5;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x;			tempy[2] = y-*B;
					tempx[3] = x;			tempy[3] = y-2*(*B);
					tempx[4] = x-*B;		tempy[4] = y;
					tempx[5] = x-2*(*B);	tempy[5] = y;
					for(int i=1;i<=5;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=5;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x;			tempy[2] = y-(*B);
					tempx[3] = x;			tempy[3] = y-2*(*B);
					tempx[4] = x+*B;		tempy[4] = y;
					tempx[5] = x+2*(*B);	tempy[5] = y;
					for(int i=1;i<=5;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=5;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x;			tempy[2] = y+*B;
					tempx[3] = x;			tempy[3] = y+2*(*B);
					tempx[4] = x+*B;		tempy[4] = y;
					tempx[5] = x+2*(*B);	tempy[5] = y;
					for(int i=1;i<=5;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=5;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
				}
				else if(status==2)
				{
					tempx[1] = x;			tempy[1] = y;
					tempx[2] = x;			tempy[2] = y+*B;
					tempx[3] = x;			tempy[3] = y+2*(*B);
					tempx[4] = x-*B;		tempy[4] = y;
					tempx[5] = x-2*(*B);	tempy[5] = y;
					for(int i=1;i<=5;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=9;i++)	BlitSmallBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
					for(int i=1;i<=9;i++)	BlitBigBlock(color,tempx[i],tempy[i],gStretchedTemp,gScreenSurface);
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
