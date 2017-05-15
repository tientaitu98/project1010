#include<fstream>
#include<iostream>
using namespace std;

void comparision(short* player_score,short* player_highscore,short* challenger_highscore,bool* allow_to_save);
void file(short status,short* player_highscore, short* challenger_highscore,short* theme);
void savegame(short starus,short* player_score, short arr_game_screen[11][11], short arr_game_creat[3][4], short* game_block_in);
