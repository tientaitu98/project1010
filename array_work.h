#include <ctime>
#include <stdlib.h>

void console(short arr_game_screen[11][11]);
void arr_game_creat_random(short arr_game_get_block[18][6],short arr_game_creat[3][4],short *game_block_in);
void drop(short x,short	y, short shape, short color, short subject,short arr_game_screen[11][11],short* dropin,short* lifesign);
void cleararea(short area,short arr_game_creat[3][4],short arr_game_get_block[18][6]);
void check_full_row_or_colum(short arr_game_screen[11][11],short row[11],short colum[11],short* player_score);


