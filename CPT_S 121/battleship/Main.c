/*
Eric Simpson PA6 11/07/2019 CPTS_121 Lab Section 2
*/

#include "Header.h"

int main(void)
{
	int selection = 0; 

	selection = welcome_screen(); int who_first = 0;

	Cell board1[ROWS][COLS] = { 0 }; char player1[32] = "Player1"; initialize_game_board(board1, player1);
	Cell board2[ROWS][COLS] = { 0 }; char player2[32] = "Player2"; initialize_game_board(board2, player2);

	if (selection == 1)
	{
		manually_place_ships_on_board(board1, 1);

		randomly_place_ships_on_board(board2, 2);
	}
	else if (selection == 2)
	{
		randomly_place_ships_on_board(board1, 1);

		randomly_place_ships_on_board(board2 , 2);
	}

	who_first = select_who_start_first(player1, player2);






	return 0;
}