/*
Eric Simpson PA5 Reworked 11/11/2019 CPTS_121 Lab Section 2

Portions of Outside Functions Used For Small Straight and Large Straight Logic
Mitchell Weholt from Github @ https://github.com/mweholt/Yahtzee/blob/master/Yahtzee.c

NOTE: Cheat Mode Can Be Turned On for Testing, To Turn On Change Final Arg in "roll_dice()" to 1; EX: roll_dice(die, turn_counter, p1_name, p1_scores, 1);
*/
#include "Header.h"

int main(void)
{
	int option = 0;

	char combo_names[16][256] = {"Sum of 1s", "Sum of 2s", "Sum of 3s", "Sum of 4s", "Sum of 5s", "Sum of 6s", "Three of a kind", "Four of a kind", "Full house", "Small Straight", "Large Straight", "YAHTZEE", "Chance"};

	do 
	{
		option = game_main(); system("cls"); //(20 pts) Print a game menu for Yahtzee; Get a menu option from the user; Clear the screen; Execute option

		int turn_counter = 0;
		int p1_scores[13] = { 0 }; int p2_scores[13] = { 0 };
		int p1_combinations[13] = { 0 }; int p2_combinations[13] = { 0 };
		char p1_name[32] = "PLAYER ONE"; char p2_name[32] = "PLAYER TWO";

		printf("Player One Name: "); scanf("%s", p1_name);
		printf("Player Two Name: "); scanf("%s", p2_name);

		int die[5] = { 0 }; system("pause"); system("cls");

		while (turn_counter < 14)
		{
			int player = 0;

			// PLAYER 1
			player = 1;
			basic_menu(turn_counter, p1_name);
			
			//(10 pts) Ask the player to hit any key to continue on to roll the five dice; Roll the five dice and display the face values of each die
			roll_dice(die, turn_counter, p1_name, p1_scores, 0);

			//(15 pts) If the number of rolls is three or "yes" is entered, then save the combination and it may not be selected again in the future
			combo_select(die, p1_combinations, combo_names, player, turn_counter, p1_name, p1_scores);

			//(5 pts) Print the scores for both players and print the winner
			game_score(turn_counter, player, p1_name, p1_scores, p2_name, p2_scores);

			//(5 pts) Alternate players
			// PLAYER 2
			player = 2;
			basic_menu(turn_counter, p2_name);

			//(10 pts) Ask the player to hit any key to continue on to roll the five dice; Roll the five dice and display the face values of each die
			roll_dice(die, turn_counter, p2_name, p2_scores, 0);

			//(15 pts) If the number of rolls is three or "yes" is entered, then save the combination and it may not be selected again in the future
			combo_select(die, p2_combinations, combo_names, player, turn_counter, p2_name, p2_scores);

			//(5 pts) Print the scores for both players and print the winner
			game_score(turn_counter, player, p1_name, p1_scores, p2_name, p2_scores);

			//(10 pts) If each player has rolled for the round, then increment the round number
			turn_counter++;
		}

		int player = 0;

		//(10 pts) Print the scores for both players and print the winner; If the total score in the upper section is greater than or equal to 63 for a player, then add 35 points to the total score
		game_score(turn_counter, player, p1_name, p1_scores, p2_name, p2_scores);

	} while (option != 3);

	return 0;
}