#include "array_work.h"
void console(short arr_game_screen[11][11])
{
	short* i = new short;
	short* j = new short;
	for( *i=0;*i<=11;(*i)++)	for( *j=0;*j<=11;(*j)++)	arr_game_screen[*i][*j]=-2;
	for( *i=1;*i<=10;(*i)++)	for( *j=1;*j<=10;(*j)++)	arr_game_screen[*i][*j]=0;
	delete i;
	delete j;
}

void arr_game_creat_random(short arr_game_get_block[18][6],short arr_game_creat[3][4],short *game_block_in)
{
	short* i = new short;
	short* j = new short;
	for( *i=1;*i<=17;(*i)++)	for( *j=1;*j<=5;(*j)++)	arr_game_get_block[*i][*j]=0;
	srand(time(0));
	for( *i=1;*i<=3;(*i)++)//shape
	{
		(*game_block_in)=3;
		arr_game_creat[1][*i]=rand()	% 19 + 1;
	}
	for( *i=1;*i<=3;(*i)++)//color
	{
		arr_game_creat[2][*i]=rand() % 11 + 1;
	}
	delete i;
	delete j;
}

void cleararea(short area,short arr_game_creat[3][4],short arr_game_get_block[18][6])
{
	arr_game_creat[1][area]=0;
	short* i = new short;
	short* j = new short;
	switch(area)
	{
		case 1:
		{
			for( *i=1;*i<=5;(*i)++) for( *j=1;*j<=5;(*j)++) arr_game_get_block[*i][*j]=0;
			break;
		}
		case 2:
		{
			for( *i=7;*i<=11;(*i)++) for( *j=1;*j<=5;(*j)++) arr_game_get_block[*i][*j]=0;
			break;
		}
		case 3:
		{
			for( *i=13;*i<=17;(*i)++) for( *j=1;*j<=5;(*j)++) arr_game_get_block[*i][*j]=0;
			break;
		}
	}
	delete i;
	delete j;
}
void check_full_row_or_colum(short arr_game_screen[11][11],short row[11],short colum[11],short* player_score)
{
	short* tempcount = new short;*tempcount=0;
	short* countdeletecolum = new short;*countdeletecolum=0;
	short* countdeleterrow = new short;*countdeleterrow=0;
	short* i = new short;
	short* j = new short;
	for( *i=1;*i<=10;(*i)++)
		{
			row[*i]=0;
			for( *j=1;*j<=10;(*j)++)
			{
				if(arr_game_screen[*i][*j] > 0) (*tempcount)++;
				else break;
			}
			if((*tempcount)==10)
			{
				row[*i]=*i;
				(*countdeleterrow)++;
			}
			(*tempcount)=0;
		}
		(*tempcount)=0;
		for( *i=1;*i<=10;(*i)++)
		{
			colum[*i]=0;
			for( *j=1;*j<=10;(*j)++)
			{
				if(arr_game_screen[*j][*i] > 0) (*tempcount)++;
				else break;
			}
			if((*tempcount)==10)
			{
				colum[*i]=*i;
				(*countdeletecolum)++;
			}
			(*tempcount)=0;
		}
		if(*countdeletecolum + *countdeleterrow > 1)
		{
			if( *countdeletecolum > 0 && *countdeleterrow > 0)
			{*player_score = *player_score -(*countdeletecolum + *countdeleterrow)*(abs(*countdeletecolum - *countdeleterrow)+1);}

			*player_score = *player_score + 10*(*countdeletecolum + *countdeleterrow);
		}
	delete tempcount;
	delete countdeletecolum;
	delete countdeleterrow;
	delete i;
	delete j;
}

void drop(short x,short	y, short shape, short color, short subject,short arr_game_screen[11][11],short* dropin,short* lifesign)
{
	if(subject==1){		y=(y/50)-2;		x=(x/50)-5;}
	if(arr_game_screen[y][x]==0 && shape != 0 )
	{
		switch(shape)
		{
			case 1:
			{
				arr_game_screen[y][x]			=color;
				(*dropin)=1;
				(*lifesign)=1;
				break;
			}
			case 2:
			{
				if(arr_game_screen[y][x-1] == 0 )
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y][x-1]		=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 3:
			{
				if(arr_game_screen[y-1][x] == 0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y-1][x]		=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 4:
			{
				if(arr_game_screen[y][x-1] ==0 && arr_game_screen[y][x+1] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y][x-1]		=color;
						arr_game_screen[y][x+1]		=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 5:
			{
				if(arr_game_screen[y-1][x] ==0 && arr_game_screen[y+1][x] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y-1][x]		=color;
						arr_game_screen[y+1][x]		=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 6:
			{
				if(arr_game_screen[y][x-1] == 0 && arr_game_screen[y-1][x] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y][x-1]		=color;
						arr_game_screen[y-1][x]		=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 7:
			{
				if(arr_game_screen[y-1][x] == 0 && arr_game_screen[y][x+1] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y-1][x]		=color;
						arr_game_screen[y][x+1]		=color;

						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 8:
			{
				if(arr_game_screen[y][x-1] == 0 && arr_game_screen[y+1][x] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y][x-1]		=color;
						arr_game_screen[y+1][x]		=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 9:
			{
				if(arr_game_screen[y+1][x] == 0 && arr_game_screen[y][x+1] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y+1][x]		=color;
						arr_game_screen[y][x+1]		=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 10:
			{
				if(arr_game_screen[y+1][x] == 0 && arr_game_screen[y][x+1] ==0 && arr_game_screen[y+1][x+1] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y+1][x+1]	=color;
						arr_game_screen[y+1][x]		=color;
						arr_game_screen[y][x+1] 	=color;

						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 11:
			{
				if(arr_game_screen[y][x-1] == 0 && arr_game_screen[y][x+1] ==0 && arr_game_screen[y][x+2] ==0 )
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y][x-1]		=color;
						arr_game_screen[y][x+1] 	=color;
						arr_game_screen[y][x+2] 	=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 12:
			{
				if(arr_game_screen[y-1][x] == 0 && arr_game_screen[y+1][x] ==0 && arr_game_screen[y+2][x] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y-1][x] 	=color;
						arr_game_screen[y+1][x] 	=color;
						arr_game_screen[y+2][x] 	=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 13:
			{
				if(arr_game_screen[y][x-2] == 0 && arr_game_screen[y][x-1] ==0 && arr_game_screen[y][x+1] ==0 && arr_game_screen[y][x+2] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y][x-2] 	=color;
						arr_game_screen[y][x-1] 	=color;
						arr_game_screen[y][x+1] 	=color;
						arr_game_screen[y][x+2] 	=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 14:
			{
				if(arr_game_screen[y-2][x] == 0 && arr_game_screen[y-1][x] ==0 && arr_game_screen[y+1][x] ==0 && arr_game_screen[y+2][x] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y-2][x] 	=color;
						arr_game_screen[y-1][x] 	=color;
						arr_game_screen[y+1][x] 	=color;
						arr_game_screen[y+2][x] 	=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 15:
			{
				if(arr_game_screen[y][x-1] == 0 && arr_game_screen[y][x-2] ==0 && arr_game_screen[y-2][x] ==0 && arr_game_screen[y-1][x] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y-2][x] 	=color;
						arr_game_screen[y-1][x] 	=color;
						arr_game_screen[y][x-1] 	=color;
						arr_game_screen[y][x-2] 	=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 16:
			{
				if(arr_game_screen[y-2][x] == 0 && arr_game_screen[y-1][x] ==0 && arr_game_screen[y][x+1] ==0 && arr_game_screen[y][x+2] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y-2][x] 	=color;
						arr_game_screen[y-1][x] 	=color;
						arr_game_screen[y][x+1] 	=color;
						arr_game_screen[y][x+2] 	=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 17:
			{
				if(arr_game_screen[y][x+2] == 0 && arr_game_screen[y][x+1] == 0 && arr_game_screen[y+1][x] == 0 && arr_game_screen[y+2][x] == 0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y][x+1] 	=color;
						arr_game_screen[y][x+2] 	=color;
						arr_game_screen[y+1][x] 	=color;
						arr_game_screen[y+2][x] 	=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 18:
			{
				if(arr_game_screen[y][x-1] == 0 && arr_game_screen[y][x-2] ==0 && arr_game_screen[y+1][x] ==0 && arr_game_screen[y+2][x] ==0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y][x-1] 	=color;
						arr_game_screen[y][x-2] 	=color;
						arr_game_screen[y+1][x] 	=color;
						arr_game_screen[y+2][x] 	=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
			case 19:
			{
				if(arr_game_screen[y-1][x-1] == 0 && arr_game_screen[y-1][x] == 0 && arr_game_screen[y-1][x+1] == 0 && arr_game_screen[y][x-1] == 0 && arr_game_screen[y][x+1] == 0 && arr_game_screen[y+1][x] == 0 && arr_game_screen[y+1][x-1] == 0 && arr_game_screen[y+1][x+1] == 0)
				{
					if(subject==1)
					{
						arr_game_screen[y][x]		=color;
						arr_game_screen[y-1][x-1] 	=color;
						arr_game_screen[y-1][x] 	=color;
						arr_game_screen[y-1][x+1] 	=color;
						arr_game_screen[y][x-1] 	=color;
						arr_game_screen[y][x+1] 	=color;
						arr_game_screen[y+1][x] 	=color;
						arr_game_screen[y+1][x-1] 	=color;
						arr_game_screen[y+1][x+1] 	=color;
						(*dropin)=1;
					}
					if(subject==2)
					{
						(*lifesign)=1;
					}
				}
				break;
			}
		}
	}
}
