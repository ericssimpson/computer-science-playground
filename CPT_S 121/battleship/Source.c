/*
Eric Simpson PA6 11/07/2019 CPTS_121 Lab Section 2
*/

#include "Header.h"

int welcome_screen(void)
{//displays an initial program welcome message along with the rules of Battleship
	int selection = 0;

	printf("***** Welcome to Battleship! *****\n\n"); printf("Rules of the Game:\n\n");

	printf("1. This is a two player game.\n\n");

	printf("2. Player1 is you and Player2 is the computer.\n\n");

	printf("3. To win you must be the first to sink all 5 of your opponent's ships.\n\n");

	printf("4. You loose if all your ships have been sunk.\n\n");

	printf("Hit any key to start the game!"); system("pause > nul"); system("cls");

	do 
	{
		printf("Please select from the following menu:\n\n");

		printf("1. Enter positions of ships manually.\n\n");

		printf("2. Allow the program to randomly select positions of ships.\n\n");

		printf("Selection: "); scanf("%d", &selection);

		if ((selection != 1) && (selection != 2))
		{
			printf("\nPlease choose a valid selection (1 OR 2)!\n"); system("pause"); system("cls");
		}

	} while ((selection != 1) && (selection != 2));

	system("pause"); system("cls");

	return selection;
}

void initialize_game_board(Cell board[ROWS][COLS], char player[32])
{//sets each cell in a game board to '-'
	int index_1 = 0; int index_2 = 0; char water = '-';

	for (index_1 = 0; index_1 < ROWS; index_1++)
	{
		for (index_2 = 0; index_2 < COLS; index_2++)
		{
			board[index_1][index_2].type = water;
		}
	}
	printf("%s board has been generated.\n", player); system("pause"); system("cls");
}

int select_who_start_first(char player1[32], char player2[32])
{//determines if Player1 or Player2 goes first in the game.
	int who = 0;

	do
	{
		srand(time(0)); who = rand() % 2 + 1;

		if (who == 1)
		{
			printf("%s has been randomly selected to go first.\n", player1); system("pause"); system("cls");
		}
		else if (who == 2)
		{
			printf("%s has been randomly selected to go first.\n", player2); system("pause"); system("cls");
		}
	} while ((who != 1) && (who != 2));

	return who;
}

void print_board(Cell board[ROWS][COLS], int player)
{
	int index_1 = 0; int index_2 = 0;

	printf("Player %d Board:\n\n", player);

	for (index_1 = 0; index_1 < ROWS; index_1++)
	{
		printf("%d ", 9 - index_1);

		for (index_2 = 0; index_2 < COLS; index_2++)
		{
			printf("%c ", board[index_1][index_2].type);
		}
		printf("\n");
	}

	for (index_1 = 0; index_1 < ROWS + 1; index_1++)
	{
		printf("%d ", index_1);
	}

	printf("\n\n");
}

void place_ship(Cell board[ROWS][COLS], char type, int xcoord1, int xcoord2, int ycoord1, int ycoord2)
{
	int start = 0; int end = 0;

	if (xcoord1 > xcoord2)
	{
		start = xcoord2; end = xcoord1;

		for (start; start < end + 1; start++)
		{
			board[ycoord1][start].type = type;
		}
	}
	else if (xcoord2 > xcoord1)
	{
		start = xcoord1; end = xcoord2;

		for (start; start < end + 1; start++)
		{
			board[ycoord1][start].type = type;
		}
	}
	else if (ycoord1 < ycoord2)
	{
		start = ycoord1; end = ycoord2;

		for (start; start < end + 1; start++)
		{
			board[start][xcoord1].type = type;
		}
	}
	else if (ycoord2 < ycoord1)
	{
		start = ycoord2; end = ycoord1;

		for (start; start < end + 1; start++)
		{
			board[start][xcoord1].type = type;
		}
	}
}

void get_ship_coords(Cell board[ROWS][COLS], int length, char type, char type_name[32], int mode, int player)
{
	int xcoord1, ycoord1, xcoord2, ycoord2;
	int ox1, ox2, oy1, oy2;
	int start = 0; int end = 0; char blank = '-'; int conflict = 0;

	if (mode == 1)
	{
		do
		{
			do
			{
				print_board(board, player);

				printf("Please enter first and last cells to place the %s across %d cells (ONLY HORIZONTAL OR VERTICAL)\n\n", type_name, length);
				printf("First  Coordinate Pair X Y: "); scanf("%d %d", &xcoord1, &ycoord1); printf("\n");
				printf("Second Coordinate Pair X Y: "); scanf("%d %d", &xcoord2, &ycoord2); printf("\n");

				ox1 = xcoord1; ox2 = xcoord2; oy1 = ycoord1, oy2 = ycoord2;
				xcoord1 = xcoord1 - 1; ycoord1 = abs(ycoord1 - 9);
				xcoord2 = xcoord2 - 1; ycoord2 = abs(ycoord2 - 9);

				if ((xcoord1 > 9 || xcoord2 > 9 || ycoord1 > 9 || ycoord2 > 9) || (xcoord1 < 0 || xcoord2 < 0 || ycoord1 < 0 || ycoord2 < 0))
				{
					printf("Out of Bounds! Choose a valid coordinate combiantion!\n"); system("pause"); system("cls");
				}
				else if (((abs(xcoord1 - xcoord2) != (length - 1)) && (ycoord1 == ycoord2)) || ((abs(ycoord1 - ycoord2) != (length - 1)) && (xcoord1 == xcoord2)))
				{
					printf("Please choose a valid coordinate combiantion!\n"); system("pause"); system("cls");
				}
			} while (((abs(xcoord1 - xcoord2) != (length - 1)) && (ycoord1 == ycoord2)) || ((abs(ycoord1 - ycoord2) != (length - 1)) && (xcoord1 == xcoord2)) || (((xcoord1 > 9 || xcoord2 > 9 || ycoord1 > 9 || ycoord2 > 9) || (xcoord1 < 0 || xcoord2 < 0 || ycoord1 < 0 || ycoord2 < 0))));

			conflict = 0;

			if (xcoord1 > xcoord2)
			{
				start = xcoord2; end = xcoord1;

				for (start; start < end + 1; start++)
				{
					if (board[ycoord1][start].type != blank) { conflict++; }
				}
			}
			else if (xcoord2 > xcoord1)
			{
				start = xcoord1; end = xcoord2;

				for (start; start < end + 1; start++)
				{
					if (board[ycoord1][start].type != blank) { conflict++; }
				}
			}
			else if (ycoord1 < ycoord2)
			{
				start = ycoord1; end = ycoord2;

				for (start; start < end + 1; start++)
				{
					if (board[start][xcoord1].type != blank) { conflict++; }
				}
			}
			else if (ycoord2 < ycoord1)
			{
				start = ycoord2; end = ycoord1;

				for (start; start < end + 1; start++)
				{
					if (board[start][xcoord1].type != blank) { conflict++; }
				}
			}

			if (conflict != 0) { printf("Overlapping Ships! Choose a valid coordinate combiantion!\n"); system("pause"); system("cls"); }

		} while (conflict > 0);

		char temp_type = type;

		place_ship(board, temp_type, xcoord1, xcoord2, ycoord1, ycoord2);
		system("cls"); print_board(board, player);

		printf("Please enter first and last cells to place the %s across %d cells (ONLY HORIZONTAL OR VERTICAL)\n\n", type_name, length);
		printf("First  Coordinate Pair X Y: "); printf("%d %d", ox1, oy1); printf("\n\n");
		printf("Second Coordinate Pair X Y: "); printf("%d %d", ox2, oy2); printf("\n\n");

		system("pause"); system("cls");
	}
	if (mode == 2)
	{
		do
		{
			do
			{
				srand(time(0));

				int direction = 0;

				direction = rand() % 2 + 1;

				int negative = 0;

				while (negative == 0)
				{
					negative = rand() % 3 - 1;
				}

				if (direction == 1)
				{
					xcoord1 = rand() % 9 + 1; ycoord1 = rand() % 9 + 1;
					xcoord2 = xcoord1;

					if ((ycoord1 + (negative * length) - 1) < 1) { ycoord2 = ycoord1 + length - 1; }
					else { ycoord2 = ycoord1 + ((negative * length) - 1); }
				}
				else if (direction == 2)
				{
					xcoord1 = rand() % 9 + 1; ycoord1 = rand() % 9 + 1;
					ycoord2 = ycoord1;

					if ((xcoord1 + (negative * length) - 1) < 1) { xcoord2 = xcoord1 + length - 1; }
					else { xcoord2 = xcoord1 + (negative * length) - 1; }
				}
				
			} while (((abs(xcoord1 - xcoord2) != (length - 1)) && (ycoord1 == ycoord2)) || ((abs(ycoord1 - ycoord2) != (length - 1)) && (xcoord1 == xcoord2)) || (((xcoord1 > 9 || xcoord2 > 9 || ycoord1 > 9 || ycoord2 > 9) || (xcoord1 < 0 || xcoord2 < 0 || ycoord1 < 0 || ycoord2 < 0))));

			conflict = 0;

			if (xcoord1 > xcoord2)
			{
				start = xcoord2; end = xcoord1;

				for (start; start < end + 1; start++)
				{
					if (board[ycoord1][start].type != blank) { conflict++; }
				}
			}
			else if (xcoord2 > xcoord1)
			{
				start = xcoord1; end = xcoord2;

				for (start; start < end + 1; start++)
				{
					if (board[ycoord1][start].type != blank) { conflict++; }
				}
			}
			else if (ycoord1 < ycoord2)
			{
				start = ycoord1; end = ycoord2;

				for (start; start < end + 1; start++)
				{
					if (board[start][xcoord1].type != blank) { conflict++; }
				}
			}
			else if (ycoord2 < ycoord1)
			{
				start = ycoord2; end = ycoord1;

				for (start; start < end + 1; start++)
				{
					if (board[start][xcoord1].type != blank) { conflict++; }
				}
			}

		} while (conflict > 0);

		char temp_type = type;

		place_ship(board, temp_type, xcoord1, xcoord2, ycoord1, ycoord2); system("cls");

		print_board(board, player); printf("Player %d %s Generated\n\n", player, type_name); system("pause"); system("cls");
	}
}

void manually_place_ships_on_board(Cell board[ROWS][COLS], int player)
{//allows the user to place each of the 5 types of ships on his/her game board

	int mode = 1;

	//CARRIER
	char carrier = 'c'; int c_length = 5; char c_type_name[32] = "Carrier";
	get_ship_coords(board, c_length, carrier, c_type_name, mode, player);
	
	//BATTLESHIP
	char battleship = 'b'; int b_length = 4; char b_type_name[32] = "Battleship";
	get_ship_coords(board, b_length, battleship, b_type_name, mode, player);

	//CRUISER
	char cruiser = 'r'; int r_length = 3; char r_type_name[32] = "Cruiser";
	get_ship_coords(board, r_length, cruiser, r_type_name, mode, player);

	//SUBMARINE
	char submarine = 's'; int s_length = 3; char s_type_name[32] = "Submarine";
	get_ship_coords(board, s_length, submarine, s_type_name, mode, player);

	//DESTROYER
	char destroyer = 'd'; int d_length = 3; char d_type_name[32] = "Destroyer";
	get_ship_coords(board, d_length, destroyer, d_type_name, mode, player);
}

void randomly_place_ships_on_board(Cell board[ROWS][COLS], int player)
{//randomly places the 5 types of ships on a given board

	int mode = 2;

	//CARRIER
	char carrier = 'c'; int c_length = 5; char c_type_name[32] = "Carrier";
	printf("Generating Player %d %s...", player, c_type_name);
	get_ship_coords(board, c_length, carrier, c_type_name, mode, player);

	//BATTLESHIP
	char battleship = 'b'; int b_length = 4; char b_type_name[32] = "Battleship";
	printf("Generating Player %d %s...", player, b_type_name);
	get_ship_coords(board, b_length, battleship, b_type_name, mode, player);

	//CRUISER
	char cruiser = 'r'; int r_length = 3; char r_type_name[32] = "Cruiser";
	printf("Generating Player %d %s...", player, r_type_name);
	get_ship_coords(board, r_length, cruiser, r_type_name, mode, player);

	//SUBMARINE
	char submarine = 's'; int s_length = 3; char s_type_name[32] = "Submarine";
	printf("Generating Player %d %s...", player, s_type_name);
	get_ship_coords(board, s_length, submarine, s_type_name, mode, player);

	//DESTROYER
	char destroyer = 'd'; int d_length = 3; char d_type_name[32] = "Destroyer";
	printf("Generating Player %d %s...", player, d_type_name);
	get_ship_coords(board, d_length, destroyer, d_type_name, mode, player);
}