#include <SDL.h>
/*
void Blit(short x,short y,short w,short h,SDL_Surface* tempSurface,SDL_Renderer* gRenderer);
void draw_shape(short x,short y, short status,short shape, short color,short arr_game_get_block[18][6],SDL_Surface* gStretchedBlockB[13],SDL_Surface* gStretchedBlockS[12],SDL_Renderer* gRenderer);
*/
void Blitnumber(short theme,short number,short x,short y,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface);
void BlitBackground(short theme,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface);
void BlitCup(short theme,short cup,short x,short y,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface);
void BlitBigBlock(short number,short x,short y,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface);
void BlitSmallBlock(short number,short x,short y,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface);
void Blit(short x,short y,short w,short h,SDL_Surface* gStretchedTemp,SDL_Surface* gScreenSurface);
void draw_shape(short x,short y, short status,short shape, short color,short arr_game_get_block[18][6],SDL_Surface* gStretchedBlockB,SDL_Surface* gStretchedBlockS,SDL_Surface* gScreenSurface);

