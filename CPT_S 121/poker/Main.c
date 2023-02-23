/*
Eric Simpson PA7 12/02/2019 CPTS_121 Lab Section 2
*/

#include "Header.h"

int main(void)
{
	//START IMPORT
	//Authors: Deitel & Deitel - C How to Program
	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */

	shuffle(deck);
	deal(deck, face, suit);
	//END IMPORT

	system("cls"); int option = 0;

	do
	{
		option = game_main(); system("cls");

		int starting_chips = 0; printf("Starting Chips: "); scanf("%d", &starting_chips);
		int big_blind = 0; printf("Big Blind: "); scanf("%d", &big_blind);
		int small_blind = (big_blind / 2); printf("Small Blind: %d\n", small_blind);
		int total_players = 0; printf("Total Players: "); scanf("%d", total_players);

		Player list[32]; int j = total_players; int i = 0;
		for (i = 0; i < j; i++)
		{
			list[i].total_chips = starting_chips;
			list[i].player_type = 2; //AI PLAYER
			if (i == 0)
			{
				list[i].player_type = 0; //HUMAN PLAYER
			}
			if (i == 1)
			{
				list[i].player_type = 1; //AI DEALER
			}
		}

		system("pause"); system("cls");

		while (total_players > 1)
		{


		}

		int player = 0;

	} while (option != 3);

	return 0;
}