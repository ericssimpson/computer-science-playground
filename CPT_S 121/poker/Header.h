/*
Eric Simpson PA7 12/02/2019 CPTS_121 Lab Section 2
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

//START IMPORT
//Authors: Deitel & Deitel - C How to Program
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[]);
//END IMPORT

typedef struct card
{
	int face;
	int suit;
} Card;
typedef struct hand
{
	Card hand[5];
} Hand;
typedef struct player
{
	char player_name[32];
	int player_type;
	int total_chips;
	int wager_chips;
	int folded;
	double rating;
	Hand hand;
} Player;

int game_menu(void);
int game_rules(void);
int game_play(void);
void game_exit(void);

void one_pair(Hand temphand);
void two_pair(Hand temphand);
void three_of_a_kind(Hand temphand);
void four_of_a_kind(Hand temphand);
void five_of_a_suit(Hand temphand);
void five_straight(Hand temphand);