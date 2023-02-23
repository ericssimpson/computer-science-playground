/*
Eric Simpson PA6 11/07/2019 CPTS_121 Lab Section 2

92 pts for adherence to the instructions stated above

o   3 pts - for displaying a welcome screen

o   6 pts (3 pts/board) - for initializing player 1’s and 2’s boards

o   2 pts – for alternating players

o   5 pts – for displaying the game boards accurately

o   2 pts - for randomly selecting which player goes first

o   12 pts - for the manual placement of ships on the game board; must not allow overlapping of ships

o   15 pts – for the random placement of ships on the game board; must not allow overlapping of ships

o   3 pts -  for determining if a shot is a hit or miss

o   5 pts – for determining if a ship is sunk

o   3 pts -  for updating the board to indicate hits and misses

o   4 pts – for not allowing the same coordinates for a shot to be used each turn

o   2 pts – for opening the logfile

o   15 pts – for writing moves by each player to a file; also for writing if a ship was hit, missed, and sunk

o   2 pts - for closing the logfile

o   8 pts (4 pts/player) – for computing and outputting stats to the logfile

o   5 pts – for determining the winner

8 pts for appropriate top-down design of functions, commenting, and good style
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <dos.h>
#include <windows.h>
#include <ctype.h>

//displays an initial program welcome message along with the rules of Battleship
int welcome_screen(void);

//sets each cell in a game board to '-'
#define ROWS 9
#define COLS 9

typedef struct cell {
	char type;
} Cell;

void initialize_game_board(Cell board[ROWS][COLS], char player[32]);

void print_board(Cell board[ROWS][COLS], int player);

void place_ship(Cell board[ROWS][COLS], char type, int xcoord1, int xcoord2, int ycoord1, int ycoord2);

void get_ship_coords(Cell board[ROWS][COLS], int length, char type, char type_name[32], int mode, int player);

//determines if Player1 or Player2 goes first in the game
int select_who_starts_first(char player1[32], char player2[32]);

//allows the user to place each of the 5 types of ships on his/her game board
void manually_place_ships_on_board(Cell board[ROWS][COLS], int player);

//randomly places the 5 types of ships on a given board
void randomly_place_ships_on_board(Cell board[ROWS][COLS], int player);

//determines if the shot taken was a hit or a miss
void check_shot(void);

//determines if a winner exists
void is_winner(void);

//updates the board every time a shot is taken; '*' indicates a hit and 'm' indicates a miss
void update_board(void);

//displays a board to the screen; Note that Player1's board should be displayed differently than Player2's board
void display_board(void);

//writes the position of the shot taken by the current player to the log file; It also writes whether or not it was a hit, miss, and if the ship was sunk
void output_current_move(void);

//determines if a ship was sunk
void check_if_sunk_ship(void);

//writes the statistics collected on each player to the log file
void out_put_stats(void);