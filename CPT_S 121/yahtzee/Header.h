#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//(5 pts) Print a game menu for Yahtzee
int game_menu(void);

//(10 pts) If option 1 is entered, then print the game rules stated aboveand repeat step(1)
int game_rules(void);

//otherwise if option 2 is entered, then continue on to step (4); player 1 starts the game
int game_play(void);

//otherwise if option 3 is entered, then print a goodbye message and quit the program
void game_exit(void);

//(10 pts) Ask the player to hit any key to continue on to roll the five dice; Roll the five dice and display the face values of each die
void roll_dice(int die[5], int turn_counter, char name[32], int scores[13],int cheat_mode);

//(15 pts) If the number of rolls is three or "yes" is entered, then save the combination and it may not be selected again in the future
void combo_print(int die[5], int combos[13], char combo_names[16][256], int player, int turn_counter, char name[32], int scores[13]);
void combo_select(int die[5], int combos[13], char combo_names[16][256], int player, int turn_counter, char name[32], int scores[13]);

//(10 pts) Print the scores for both players and print the winner; If the total score in the upper section is greater than or equal to 63 for a player, then add 35 points to the total score
int game_score(int turn_counter, int player, char p1_name[32], int p1_scores[13], char p2_name[32], int p2_scores[13]);

//PRINTING FUNCTIONS
int game_main(void);
void basic_menu(int turn_counter, char name[32]);

//UPPER SECTION
void ones(int die[5], int combos[13], int scores[13]);
void twos(int die[5], int combos[13], int scores[13]);
void threes(int die[5], int combos[13], int scores[13]);
void fours(int die[5], int combos[13], int scores[13]);
void fives(int die[5], int combos[13], int scores[13]);
void sixes(int die[5], int combos[13], int scores[13]);

//LOWER SECTION
void three_of_a_kind(int die[5], int combos[13], int scores[13]);
void four_of_a_kind(int die[5], int combos[13], int scores[13]);
void full_house(int die[5], int combos[13], int scores[13]);
void sm_straight(int die[5], int combos[13], int scores[13]);
void lg_straight(int die[5], int combos[13], int scores[13]);
void yahtzee(int die[5], int combos[13], int scores[13]);
void chance(int die[5], int combos[13], int scores[13]);