#include"process.h"

void file(short status,short* player_highscore,short* theme)
{
	if(status==1)
	{
		fstream gfile;
		gfile.open("highscore.txt");
		if(gfile.is_open())
		{
			gfile << *theme<<" ";
			gfile << *player_highscore;

		}
		gfile.close();
	}
	else if(status==2);
	{
		fstream gfile;
		gfile.open ("highscore.txt");
		if(gfile.is_open())
		{
			gfile >> *theme;
			gfile >> *player_highscore;
		}
		gfile.close();
	}
}

void savegame(short starus,short* player_score, short arr_game_screen[11][11], short arr_game_creat[3][4], short* game_block_in)
{
	fstream gfile;
	gfile.open ("save.txt");
	if( starus == 1)
	{
		if(gfile.is_open())
		{
			gfile << *player_score<<endl;
			gfile << *game_block_in<<endl;
			for(short i=0;i<=11;i++)
			{
				for(short j=0;j<=11;j++)
				{
					gfile << arr_game_screen[i][j]<<" ";
				}
				gfile<<endl;
			}
			for(short i=1;i<3;i++)
			{
				for(short j=1;j<4;j++)
				{
					gfile << arr_game_creat[i][j]<<" ";
				}
				gfile<<endl;
			}
		}
	}
	if ( starus ==2)
	{
 		fstream gfile;
		gfile.open ("save.txt");
		if(gfile.is_open())
		{
			gfile >>* player_score;
			gfile >>* game_block_in;
			for(short i=0;i<=11;i++)
			{
				for(short j=0;j<=11;j++)
				{
					gfile >> arr_game_screen[i][j];
				}
			}
			for(short i=1;i<3;i++)
			{
				for(short j=1;j<4;j++)
				{
					gfile >> arr_game_creat[i][j];
				}
			}
		}
	}
	gfile.close();
}

