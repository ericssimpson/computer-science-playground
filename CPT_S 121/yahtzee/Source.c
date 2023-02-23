#include "Header.h"

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

void basic_menu(int turn_counter, char name[32])
{
	printf("%s's Turn:\n", name);
	printf("ROUND %d\n\n", turn_counter + 1);
}

void combo_menu(int die[5], int combos[13], char combo_names[16][256], int player, int turn_counter, char name[32], int scores[13])
{


	system("cls"); basic_menu(turn_counter, name, scores);

	int index = 0;

	int selection = 0;

	while (index < 5)
	{
		printf("Die %d: ", index + 1);
		printf("%d\n", die[index]);
		index++;
	}

	printf("\n");

	for (index = 0; index < 13; index++)
	{
		if (combos[index] == 0)
		{
			printf("%d.%s\n", index + 1, combo_names[index]);
		}
		else
		{
			printf("X.%s\n", combo_names[index]);
		}
	}

	printf("\n");
}

int game_score(int turn_counter, int player, char p1_name[32], int p1_scores[13], char p2_name[32], int p2_scores[13])
{
	//(10 pts) Print the scores for both players and print the winner; If the total score in the upper section is greater than or equal to 63 for a player, then add 35 points to the total score
	int index = 0; int p1_total = 0; int p2_total = 0;

	if (player == 0)
	{
		for (index = 0; index < 13; index++)
		{
			p1_total = p1_scores[index] + p1_total;
		}

		for (index = 0; index < 13; index++)
		{
			p2_total = p2_scores[index] + p2_total;
		}

		if ((p1_scores[0] + p1_scores[1] + p1_scores[2] + p1_scores[3] + p1_scores[4] + p1_scores[5]) > 63)
		{
			p1_total = p1_total + 35;
		}
		if ((p2_scores[0] + p2_scores[1] + p2_scores[2] + p2_scores[3] + p2_scores[4] + p2_scores[5]) > 63)
		{
			p2_total = p2_total + 35;
		}

		if (p1_total == p2_total)
		{
			system("cls");

			printf("\nAnd That's The Game!\n\n");

			printf("You Both Tied With %d Points!\n\n", p1_total); game_exit();
		}

		if (p1_total > p2_total)
		{
			system("cls");

			printf("\nAnd That's The Game!\n\n");

			printf("%s Wins With %d Points! %s You Ended With %d Points, Better Luck Next Time!\n\n", p1_name, p1_scores, p2_name, p2_scores); game_exit();
		}

		if (p1_total < p2_total)
		{
			system("cls");

			printf("\nAnd That's The Game!\n\n");

			printf("%s Wins With %d Points! %s You Ended With %d Points, Better Luck Next Time!\n\n", p2_name, p2_scores, p1_name, p1_scores); game_exit();
		}
	}

	else if (player == 1)
	{
		for (index = 0; index < 13; index++)
		{
			p1_total = p1_scores[index] + p1_total;
		}

		if ((p1_scores[0] + p1_scores[1] + p1_scores[2] + p1_scores[3] + p1_scores[4] + p1_scores[5]) > 63)
		{
			p1_total = p1_total + 35;
		}

		printf("\n%s You Have %d Points!\n", p1_name, p1_total); system("pause"); system("cls");
	}

	else if (player == 2)
	{
		for (index = 0; index < 13; index++)
		{
			p2_total = p2_scores[index] + p2_total;
		}

		if ((p2_scores[0] + p2_scores[1] + p2_scores[2] + p2_scores[3] + p2_scores[4] + p2_scores[5]) > 63)
		{
			p2_total = p2_total + 35;
		}

		printf("\n%s You Have %d Points!\n", p2_name, p2_total); system("pause"); system("cls");
	}
	else
	{
		printf("\n\n\nYou Shouldn't Be Here...\n\n\n"); system("pause > nul"); game_exit();
	}
}

int game_menu(void)
{
	int option = 0;

	do
	{
		printf("Welcome to Yahtzee!\n\n");

		//(5 pts) Print a game menu for Yahtzee with the following options:
		printf("Enter the Option Number:\n");
		printf("1. Print game rules\n");
		printf("2. Start a game of Yahtzee\n");
		printf("3. Exit\n\n");

		//(5 pts) Get a menu option from the user; clear the screen
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
	//(10 pts) If option 1 is entered, then print the game rules stated above and repeat step (1)
	printf("The Rules of Yahtzee:\n\n");

	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of\n");
	printf("thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists\n");
	printf("of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls\n");
	printf("four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen\n");
	printf("to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum\n");
	printf("of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players\n");
	printf("overall score as a bonus. The lower section contains a number of poker like combinations. See the table provided:\n\n");

	printf("|********* NAME *********|************ COMBINATION ************|************ SCORE ************|\n");
	printf("|Chance                  |May be used for any sequence of dice |Sum of all values on the 5 dice|\n");
	printf("|Three-of-a-kind         |Three dice with the same face        |Sum of all values on the 5 dice|\n");
	printf("|Four-of-a-kind          |Four dice with the same face         |Sum of all values on the 5 dice|\n");
	printf("|Full House              |One pair and a three-of-a-kind       |25                             |\n");
	printf("|Small Straight          |A sequence of four dice              |30                             |\n");
	printf("|Large Straight          |A sequence of five dice              |40                             |\n");
	printf("|Yahtzee (Five-of-a-kind)|Five dice with the same face         |50                             |\n\n");

	int option = 0;

	system("pause"); system("cls"); option = game_menu();

	return option;
}

int game_play(void)
{
	//otherwise if option 2 is entered, then continue on to step (4); player 1 starts the game
	return 0;
}

void roll_dice(int die[5], int turn_counter, char name[32], int scores[13], int cheat_mode)
{
	//(5 pts) Ask the player to hit any key to continue on to roll the five dice
	printf("Press Any Key to Roll the Dice\n\n"); system("pause > nul"); system("cls");

	//(5 pts) Roll the five dice and enumerate each die with a number 1 - 5; add 1 to the total number of rolls for this round
	int roll_counter = 0; int index = 0; roll_counter++;

	if (cheat_mode == 1)
	{
		printf("CHEAT MODE IS ON [SWITCH OFF IN MAIN IN ROLL DICE FUNCTION]\n\nEnter Desired Combination #: ");

		int cheat = 0; scanf("%d", &cheat); system("cls"); printf("You Decided to Keep it On I See...\n"); system("pause"); system("cls");

		if (cheat == 1)
		{
			die[0] = 1;
			die[1] = 1;
			die[2] = 1;
			die[3] = 1;
			die[4] = 1;
		}

		if (cheat == 2)
		{
			die[0] = 2;
			die[1] = 2;
			die[2] = 2;
			die[3] = 2;
			die[4] = 2;
		}

		if (cheat == 3)
		{
			die[0] = 3;
			die[1] = 3;
			die[2] = 3;
			die[3] = 3;
			die[4] = 3;
		}

		if (cheat == 4)
		{
			die[0] = 4;
			die[1] = 4;
			die[2] = 4;
			die[3] = 4;
			die[4] = 4;
		}

		if (cheat == 5)
		{
			die[0] = 5;
			die[1] = 5;
			die[2] = 5;
			die[3] = 5;
			die[4] = 5;
		}

		if (cheat == 6)
		{
			die[0] = 6;
			die[1] = 6;
			die[2] = 6;
			die[3] = 6;
			die[4] = 6;
		}

		if (cheat == 7)
		{
			die[0] = 6;
			die[1] = 6;
			die[2] = 6;
			die[3] = 5;
			die[4] = 4;
		}

		if (cheat == 8)
		{
			die[0] = 6;
			die[1] = 6;
			die[2] = 6;
			die[3] = 6;
			die[4] = 5;
		}

		if (cheat == 9)
		{
			die[0] = 6;
			die[1] = 6;
			die[2] = 6;
			die[3] = 5;
			die[4] = 5;
		}

		if (cheat == 10)
		{
			die[0] = 6;
			die[1] = 5;
			die[2] = 4;
			die[3] = 3;
			die[4] = 1;
		}
		
		if (cheat == 11)
		{
			die[0] = 6;
			die[1] = 5;
			die[2] = 4;
			die[3] = 3;
			die[4] = 2;
		}

		if (cheat == 12)
		{
			die[0] = 6;
			die[1] = 6;
			die[2] = 6;
			die[3] = 6;
			die[4] = 6;
			die[5] = 6;
		}

		if (cheat == 13)
		{
			die[0] = 6;
			die[1] = 6;
			die[2] = 6;
			die[3] = 6;
			die[4] = 6;
			die[5] = 6;
		}
	}

	else
	{
		srand(time(0));
		for (index = 0; index < 5; ++index)
		{
			die[index] = rand() % 6 + 1;
		}
	}

	index = 0;

	basic_menu(turn_counter, name);

	//display the face values of each die
	while (index < 5)
	{
		printf("Die %d: ", index + 1);
		printf("%d\n", die[index]);
		index++;
	}
	printf("\n");

	int number = 0;
	int die_reroll = 0;

	while (roll_counter < 3)
	{
		printf("Enter the Amount of Dice You Would Like to Re-Roll (If No Enter 0): ");
		scanf("%d", &number);

		if (number != 0)
		{
			roll_counter++;

			for (index = 0; index < number; index++)
			{
				printf("Enter the Die You Would Like to Re-Roll: ");
				scanf("%d", &die_reroll);
				die[die_reroll - 1] = rand() % 6 + 1;
			}

			index = 0;

			system("cls"); basic_menu(turn_counter, name);

			//display the face values of each die
			while (index < 5)
			{
				printf("Die %d: ", index + 1);
				printf("%d\n", die[index]);
				index++;
			}
			printf("\n");
		}
		else
		{
			break;
		}
	}
}

void combo_select(int die[5], int combos[13], char combo_names[16][256], int player, int turn_counter, char name[32], int scores[13])
{
	//(15 pts) If the number of rolls is three or "yes" is entered, ask the player (Y/N) if to select one of the game combinations
	int selection = 0;

	do
	{
		combo_menu(die, combos, combo_names, player, turn_counter, name, scores);

		printf("Enter the Number of the Combination: "); scanf("%d", &selection);

		selection = selection - 1;

		if (selection == 0)
		{
			ones(die, combos, scores);
		}
		else if (selection == 1)
		{
			twos(die, combos, scores);
		}
		else if (selection == 2)
		{
			threes(die, combos, scores);
		}
		else if (selection == 3)
		{
			fours(die, combos, scores);
		}
		else if (selection == 4)
		{
			fives(die, combos, scores);
		}
		else if (selection == 5)
		{
			sixes(die, combos, scores);
		}
		else if (selection == 6)
		{
			three_of_a_kind(die, combos, scores);
		}
		else if (selection == 7)
		{
			four_of_a_kind(die, combos, scores);
		}
		else if (selection == 8)
		{
			full_house(die, combos, scores);
		}
		else if (selection == 9)
		{
			sm_straight(die, combos, scores);
		}
		else if (selection == 10)
		{
			lg_straight(die, combos, scores);
		}
		else if (selection == 11)
		{
			yahtzee(die, combos, scores);
		}
		else if (selection == 12)
		{
			chance(die, combos, scores);
		}
		else
		{
			printf("Please Choose a Valid Combination! "); system("pause"); system("cls");
		}
	} 
	
	while ((selection != 0) && (selection != 1) && (selection != 2) && (selection != 3) && (selection != 4) && (selection != 5) && (selection != 6) && (selection != 7) && (selection != 8) && (selection != 9) && (selection != 10) && (selection != 11) && (selection != 12));

}

void game_exit(void)
{
	//otherwise if option 3 is entered, then print a goodbye message and quit the program
	printf("Goodbye!\n"); system("pause"); exit(0);
}

//UPPER SECTION
void ones(int die[5], int combos[13], int scores[13])
{
	int index = 0; int sum = 0;

	if (combos[0] == 0)
	{
		combos[0] = 1;

		//SUM OF ONES LOGIC
		for (index = 0; index < 5; index++)
		{
			if (die[index] == 1)
			{
				sum = sum + 1;
			}
		}
		scores[0] = sum;
	}
}

void twos(int die[5], int combos[13], int scores[13])
{
	int index = 0; int sum = 0;

	if (combos[1] == 0)
	{
		combos[1] = 1;

		//SUM OF TWOS LOGIC
		for (index = 0; index < 5; index++)
		{
			if (die[index] == 2)
			{
				sum = sum + 2;
			}
		}
		scores[1] = sum;
	}
}

void threes(int die[5], int combos[13], int scores[13])
{
	int index = 0; int sum = 0;

	if (combos[2] == 0)
	{
		combos[2] = 1;

		//SUM OF THREES LOGIC
		for (index = 0; index < 5; index++)
		{
			if (die[index] == 3)
			{
				sum = sum + 3;
			}
		}
		scores[2] = sum;
	}
}

void fours(int die[5], int combos[13], int scores[13])
{
	int index = 0; int sum = 0;

	if (combos[3] == 0)
	{
		combos[3] = 1;

		//SUM OF FOURS LOGIC
		for (index = 0; index < 5; index++)
		{
			if (die[index] == 4)
			{
				sum = sum + 4;
			}
		}
		scores[3] = sum;
	}
}

void fives(int die[5], int combos[13], int scores[13])
{
	int index = 0; int sum = 0;

	if (combos[4] == 0)
	{
		combos[4] = 1;

		//SUM OF FIVES LOGIC
		for (index = 0; index < 5; index++)
		{
			if (die[index] == 5)
			{
				sum = sum + 5;
			}
		}
		scores[4] = sum;
	}
}

void sixes(int die[5], int combos[13], int scores[13])
{
	int index = 0; int sum = 0;

	if (combos[5] == 0)
	{
		combos[5] = 1;

		//SUM OF SIXES LOGIC
		for (index = 0; index < 5; index++)
		{
			if (die[index] == 6)
			{
				sum = sum + 6;
			}
		}
		scores[5] = sum;
	}
}

//LOWER SECTION
void three_of_a_kind(int die[5], int combos[13], int scores[13])
{
	int index = 0; int sum = 0;

	if (combos[6] == 0)
	{
		combos[6] = 1;

		//THREE OF A KIND LOGIC GATE
		for (index = 0; index < 6; index++)
		{
			sum = 0;

			if (die[0]-1 == index)
			{
				sum = sum + 1;
			}
			if (die[1]-1 == index)
			{
				sum = sum + 1;
			}
			if (die[2]-1 == index)
			{
				sum = sum + 1;
			}
			if (die[3]-1 == index)
			{
				sum = sum + 1;
			}
			if (die[4]-1 == index)
			{
				sum = sum + 1;
			}
			//GATE PASSED
			if (sum >= 3)
			{
				scores[6] = die[0] + die[1] + die[2] + die[3] + die[4];

				break;
			}
		}
	}
}

void four_of_a_kind(int die[5], int combos[13], int scores[13])
{
	int index = 0; int sum = 0;

	if (combos[7] == 0)
	{
		combos[7] = 1;

		//FOUR OF A KIND LOGIC GATE
		for (index = 0; index < 6; index++)
		{
			sum = 0;

			if (die[0] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[1] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[2] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[3] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[4] - 1 == index)
			{
				sum = sum + 1;
			}
			//GATE PASSED
			if (sum >= 4)
			{
				scores[7] = die[0] + die[1] + die[2] + die[3] + die[4];

				break;
			}
		}
	}
}

void full_house(int die[5], int combos[13], int scores[13])
{
	int index = 0; int sum = 0;

	if (combos[8] == 0)
	{
		combos[8] = 1;

		int threes = 0;
		int twos = 0;

		//THREE OF A KIND LOGIC GATE
		for (index = 0; index < 6; index++)
		{
			sum = 0;

			if (die[0] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[1] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[2] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[3] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[4] - 1 == index)
			{
				sum = sum + 1;
			}
			//GATE PASSED
			if (sum >= 3)
			{
				threes = index;

				break;
			}
		}

		//TWO OF A KIND LOGIC GATE
		for (index = 0; index < 6; index++)
		{
			sum = 0;

			if (die[0] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[1] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[2] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[3] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[4] - 1 == index)
			{
				sum = sum + 1;
			}
			//GATE PASSED
			if (sum >= 2)
			{
				twos = index;

				break;
			}
		}
		//FULL HOUSE LOGIC GATE
		if (twos != threes)
		{
			scores[8] = 25;
		}
	}
}

//Mitchell Weholt from Github @ https://github.com/mweholt/Yahtzee/blob/master/Yahtzee.c
void sm_straight(int die[5], int combos[13], int scores[13])
{
	int index_1 = 0; int index_2 = 0; int index_3 = 0; int sum = 0;

	if (combos[9] == 0)
	{
		combos[9] = 1;

	//ORIGINAL COULD NOT GET TO WORK
	//	//SMALL STRAIGHT LOGIC
	//	int sort[32] = { 16 };

	//	//SORTING FOR COMPARISON
	//	for (index_1 = 0; index_1 < 5; index_1++)
	//	{
	//		for (index_2 = 0; index_2 < 5; index_2++)
	//		{
	//			if ((die[index_1] > die[index_2]) && (die[index_1] < sort[index_3]))
	//			{
	//				sort[index_3] = index_1;

	//				index_3++;
	//			}
	//		}
	//	}

	//	//COMPARE SORTED
	//	for (index_1 = 0; index_1 < 5; index_1++)
	//	{
	//		//GATE PASSED
	//		if ((die[sort[index_1]] == die[sort[index_1 + 1]] + 1) && (die[sort[index_1 + 1]] == die[sort[index_1 + 2]] + 1) && (die[sort[index_1 + 2]] == die[sort[index_1 + 3]] + 1))
	//		{
	//			scores[9] = 30;
	//		}
	//	}
	//}

	//BORROWED AND ADAPTED FROM Mitchell Weholt

	int index = 0, temp = 0, passes = 0, sum = 0, result = 0;

	//COMBO CHECK

		result = 1;

		for (passes = 1; passes < 5; passes++)
		{
			for (index = 0; index < 5 - passes; index++)
			{
				if (die[index] > die[index + 1])
				{
					temp = die[index];
					die[index] = die[index + 1];
					die[index + 1] = temp;
				}
			}
		}

		//SMALL STRAIGHT
		for (index = 4; index > 0; index--)
		{
			if (die[index] == die[index - 1] + 1)
			{
				sum++;
			}

		}

		if (sum >= 3)
		{
			scores[9] = 30;
		}
	}
}

//Mitchell Weholt from Github @ https://github.com/mweholt/Yahtzee/blob/master/Yahtzee.c
void lg_straight(int die[5], int combos[13], int scores[13])
{
	int index_1 = 0; int index_2 = 0; int index_3 = 0; int sum = 0;

	if (combos[10] == 0)
	{
		combos[10] = 1;

	//ORIGINAL COULD NOT GET TO WORK
	//	//LARGE STRAIGHT LOGIC
	//	int sort[32] = { 16 };

	//	//SORTING FOR COMPARISON
	//	for (index_1 = 0; index_1 < 5; index_1++)
	//	{
	//		for (index_2 = 0; index_2 < 5; index_2++)
	//		{
	//			if ((die[index_1] > die[index_2]) && (die[index_1] < sort[index_3]))
	//			{
	//				sort[index_3] = index_1;

	//				index_3++;
	//			}
	//		}
	//	}

	//	//COMPARE SORTED
	//	for (index_1 = 0; index_1 < 5; index_1++)
	//	{
	//		//GATE ONE PASSED
	//		if ((die[sort[index_1]] == die[sort[index_1 + 1]] + 1) && (die[sort[index_1 + 1]] == die[sort[index_1 + 2]] + 1) && (die[sort[index_1 + 2]] == die[sort[index_1 + 3]] + 1))
	//		{
	//			//GATE TWO PASSED
	//			if ((die[sort[index_1 + 3]] == die[sort[index_1 + 4]] + 1))
	//			{
	//				scores[10] = 30;
	//			}
	//		}
	//	}
	//}

	//BORROWED AND ADAPTED FROM Mitchell Weholt

	int index = 0, temp = 0, passes = 0, sum = 0, result = 0;

	//COMBO CHECK

		result = 1;

		for (passes = 1; passes < 5; passes++)
		{
			for (index = 0; index < 5 - passes; index++)
			{
				if (die[index] > die[index + 1])
				{
					temp = die[index];
					die[index] = die[index + 1];
					die[index + 1] = temp;
				}
			}
		}

		//SMALL STRAIGHT
		for (index = 4; index > 0; index--)
		{
			if (die[index] == die[index - 1] + 1)
			{
				sum++;
			}

		}

		if (sum >= 4)
		{
			scores[10] = 30;
		}
	}
}

void yahtzee(int die[5], int combos[13], int scores[13])
{
	int index = 0; int sum = 0;

	if (combos[11] == 0)
	{
		combos[11] = 1;

		//YAHTZEE LOGIC
		for (index = 0; index < 6; index++)
		{
			sum = 0;

			if (die[0] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[1] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[2] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[3] - 1 == index)
			{
				sum = sum + 1;
			}
			if (die[4] - 1 == index)
			{
				sum = sum + 1;
			}
			//GATE PASSED
			if (sum >= 5)
			{
				scores[11] = 50;

				break;
			}
		}
	}
}

void chance(int die[5], int combos[13], int scores[13])
{
	int index = 0; int sum = 0;

	if (combos[12] == 0)
	{
		combos[12] = 1;

		//CHANCE LOGIC
		sum = die[0] + die[1] + die[2] + die[3] + die[4];
		scores[12] = sum;
	}
}