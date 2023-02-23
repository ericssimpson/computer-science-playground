/*
Eric Simpson PA7 12/02/2019 CPTS_121 Lab Section 2
*/

#include "Header.h"

//START IMPORT
//Authors: Deitel & Deitel - C How to Program
/* shuffle cards in deck */
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* deal each of the 52 cards */
	for (card = 1; card <= 52; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}
//END IMPORT

int game_main(void)
{
	int option = 0;

	do
	{
		option = game_menu();

		if (option == 3)
		{
			game_exit();
		}

	} while (option != 2);

	return option;
}

int game_menu(void)
{
	int option = 0;

	do
	{
		printf("Welcome to Poker!\n\n");

		printf("Enter the Option Number:\n");
		printf("1. Print game rules\n");
		printf("2. Start a game of Poker\n");
		printf("3. Exit\n\n");

		printf("Menu Option: "); scanf("%d", &option); system("pause"); system("cls");

		if (option == 1)
		{
			option = game_rules();
		}

	} while ((option != 2) && (option != 3));

	return option;
}

int game_rules(void)
{
	printf("The Rules of Poker: (Adapted from Wikipedia 'Five-Card Draw')\n\n");

	printf("In Poker the first betting round begins with the player to the left of the big blind, and subsequent rounds begin with the player to the dealer's left.\n");
	printf("Play begins with each player being dealt five cards, one at a time, all face down. The remaining deck is placed aside, often protected by placing a chip\n");
	printf("or other marker on it. Players pick up the cards and hold them in their hands, being careful to keep them concealed from the other players, then a round\n");
	printf("of betting occurs. If more than one player remains after the first round, the 'draw' phase begins. Each player specifies how many of their cards they wish\n");
	printf("to replace and discards them. The deck is retrieved, and each player is dealt in turn from the deck the same number of cards they discarded so that each\n");
	printf("player again has five cards. A second 'after the draw' betting round occurs beginning with the player to the dealer's left. This is followed by a showdown,\n");
	printf("if more than one player remains, the player with the best hand wins the pot. Any of your questions can be answered with a quick google search, including hands.\n\n");

	int option = 0;

	system("pause"); system("cls"); option = game_menu();

	return option;
}

int game_play(void)
{
	//otherwise if option 2 is entered, then continue on to step (4); player 1 starts the game
	return 0;
}

void game_exit(void)
{
	//otherwise if option 3 is entered, then print a goodbye message and quit the program
	printf("Goodbye!\n"); system("pause"); exit(0);
}