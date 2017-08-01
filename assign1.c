#include <stdio.h>
#include <stdlib.h>

int main( int argv, char *argc[]){
	printf("Please enter dice values:\n");
	char c;
	char ch = ' ';
	int diceroll[100];
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	int count6 = 0;
	int i = 0;
	int error = 0;
	int rollcount = 0;
	int scorecount = 0;
	int scorechoice[4];
	int choice = 0;

	
	while((c = getchar()) != '\n' && error == 0){ // Checks the character inputted into the program to check for the correct format//
		if(ch >= '1' && c != ' ' && ch <= '6'){ // Checks if there are any characters not applicable//
			printf("\nIncorrect Input Format.\n\n");
			error++;
		}
		if ((c < '1' || c > '6') && ch == ' '){// Checks if there are any numbers higher/lower than the dice values//
			printf("\nValue Out of Range.\n\n");
			error++;
		}
		if (ch == ' ' && c >= '1' && c <= '6') {// Places the dice values into an array and counts the number of times each dice number appears//
			diceroll[i] = c - '0';
			if(diceroll[i] == 1){
				count1++;
			}
			else if(diceroll[i] == 2){
				count2++;
			}
			else if(diceroll[i] == 3){
				count3++;
			}
			else if(diceroll[i] == 4){
				count4++;
			}
			else if(diceroll[i] == 5){
				count5++;
			}
			else if(diceroll[i] == 6){
				count6++;
			}
			ch = c;
			i++;
			rollcount++;
		}
		if (c == ' ' && ch >= 1 && ch <= '6'){
			ch = c;
		}
	}
		if (rollcount != 5 && error == 0){// Checks if there are 5 dice values//
			printf("\nIncorrect Number of Values.\n\n");
			error++;
		}
	if (error < 1){
		printf("Your dice values are: %d %d %d %d %d\n", diceroll[0], diceroll[1], diceroll[2], diceroll[3], diceroll[4]); 

	
		printf("\n");
		printf("Please choose:\n");
		printf("1 -> Reroll some dice\n");
		printf("2 -> Reroll all dice\n");
		printf("3 -> Keep dice\n");

		while((c = getchar()) != '\n'){	
			if (c == '1' && choice == 0){
				printf("Rerolling all dice\n");
			}
			else if (c == '2' && choice == 0){
				printf("Rerolling some dice\n");
			}
			else if (c == '3' && choice == 0){
				choice = 3;
				printf("Your score options are:\n");
				printf("1 -> ");


				if (count1 >= 3){ // Checks for all score combinations with at least three 1s//
					printf("Three of a Kind (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
					scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];
					scorecount++;
					printf("%d -> ", scorecount + 1);
			
					if (count1 >= 4){
						printf("Four of a Kind (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
						scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];
						scorecount++;
						printf("%d -> ", scorecount + 1);
			
						if (count1 == 5){
							printf("Yahtzee (50 points)\n");
							scorechoice[scorecount] = 50;
							scorecount++;
							printf("%d -> ", scorecount + 1);
						}
					}
				if (count1 == 3 && count2 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count1 == 3 && count3 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count1 == 3 && count4 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count1 == 3 && count5 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count1 == 3 && count6 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
			}
		
		
			if (count2 >= 3){ // Checks for all combinations with at least three 2s// 
					printf("Three of a Kind (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
					scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];
					scorecount++;
					printf("%d -> ", scorecount + 1);
			
					if (count2 >= 4){
						printf("Four of a Kind (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
						scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];
						scorecount++;
						printf("%d -> ", scorecount + 1);
			
						if (count2 == 5){
							printf("Yahtzee (50 points)\n");
							scorechoice[scorecount] = 50;
							scorecount++;
							printf("%d -> ", scorecount + 1);
						}
					}
				if (count2 == 3 && count1 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count2 == 3 && count3 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count2 == 3 && count4 == 2){
					printf("Full House (25 points)\n");
					scorechoice[scorecount] = 25;
					scorecount++;
					printf("%d -> ", scorecount + 1);
				}
				if (count2 == 3 && count5 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count2 == 3 && count6 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
			}


			if (count3 >= 3){ // Checks for all combinations with at least three 3s//
					printf("Three of a Kind (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
					scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];
					scorecount++;
					printf("%d -> ", scorecount + 1);
			
					if (count3 >= 4){
						printf("Four of a Kind (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
						scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];
						scorecount++;
						printf("%d -> ", scorecount + 1);
			
						if (count3 == 5){
							printf("Yahtzee (50 points)\n");
							scorechoice[scorecount] = 50;
							scorecount++;
							printf("%d -> ", scorecount + 1);
						}
					}
				if (count3 == 3 && count1 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count3 == 3 && count2 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count3 == 3 && count4 == 2){
					printf("Full House (25 points)\n");
					scorechoice[scorecount] = 25;
					scorecount++;
					printf("%d -> ", scorecount + 1);
				}
				if (count3 == 3 && count5 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count3 == 3 && count6 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
			}


			if (count4 >= 3){ // Checks for all combinations with at least three 4s//
					printf("Three of a Kind (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
					scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];
					scorecount++;
					printf("%d -> ", scorecount + 1);
			
					if (count4 >= 4){
						printf("Four of a Kind (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
						scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];
						scorecount++;
						printf("%d -> ", scorecount + 1);
			
						if (count4 == 5){
							printf("Yahtzee (50 points)\n");
							scorechoice[scorecount] = 50;
							scorecount++;
							printf("%d -> ", scorecount + 1);
						}
					}
				if (count4 == 3 && count1 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count4 == 3 && count2 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count4 == 3 && count3 == 2){
					printf("Full House (25 points)\n");
					scorechoice[scorecount] = 25;
					scorecount++;
					printf("%d -> ", scorecount + 1);
				}
				if (count4 == 3 && count5 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count4 == 3 && count6 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
			}


			
			if (count5 >= 3){ // Checks for all combinations with at least three 5s//
					printf("Three of a Kind (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
					scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];
					scorecount++;
					printf("%d -> ", scorecount + 1);
			
					if (count5 >= 4){
						printf("Four of a Kind (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
						scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];
						scorecount++;
						printf("%d -> ", scorecount + 1);
			
						if (count5 == 5){
							printf("Yahtzee (50 points)\n");
							scorechoice[scorecount] = 50;
							scorecount++;
							printf("%d -> ", scorecount + 1);
						}
					}
				if (count5 == 3 && count1 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count5 == 3 && count2 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count5 == 3 && count3 == 2){
					printf("Full House (25 points)\n");
					scorechoice[scorecount] = 25;
					scorecount++;
					printf("%d -> ", scorecount + 1);
				}
				if (count5 == 3 && count4 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count5 == 3 && count6 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
			}


			if (count6 >= 3){ // Checks for all combinations with at least three 6s//
					printf("Three of a Kind (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
					scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];
					scorecount++;
					printf("%d -> ", scorecount + 1);
			
					if (count6 >= 4){
						printf("Four of a Kind (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
						scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];
						scorecount++;
						printf("%d -> ", scorecount + 1);
			
						if (count6 == 5){
							printf("Yahtzee (50 points)\n");
							scorechoice[scorecount] = 50;
							scorecount++;
							printf("%d -> ", scorecount + 1);
						}
					}
				if (count6 == 3 && count1 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count6 == 3 && count2 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count6 == 3 && count3 == 2){
					printf("Full House (25 points)\n");
					scorechoice[scorecount] = 25;
					scorecount++;
					printf("%d -> ", scorecount + 1);
				}
				if (count6 == 3 && count4 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
				if (count6 == 3 && count5 == 2){
						printf("Full House (25 points)\n");
						scorechoice[scorecount] = 25;
						scorecount++;
						printf("%d -> ", scorecount + 1);
				}
			}

			// Checks for all combinations in regards to small straights and straights//
			if (count1 >= 1 && count2  >= 1 && count3 >= 1 && count4 >= 1){
				printf("Small Straight (30 points)\n");
				scorechoice[scorecount] = 30;
				scorecount++;
				printf("%d -> ", scorecount + 1);
				if (count5 == 1){
					printf("Straight (40 points)\n");
					scorechoice[scorecount] = 40;
					scorecount++;
					printf("%d -> ", scorecount + 1);
				}
			}

			if (count2 >= 1 && count3  >= 1 && count4 >= 1 && count5 >= 1 && scorecount < 1){
				printf("Small Straight (30 points)\n");
				scorechoice[scorecount] = 30;
				scorecount++;
				printf("%d -> ", scorecount + 1);
				if (count1 == 1){
					printf("Straight (40 points)\n");
					scorechoice[scorecount] = 40;
					scorecount++;
					printf("%d -> ", scorecount + 1);
				}
				if (count6 == 1){
					printf("Straight (40 points)\n");
					scorechoice[scorecount] = 40;
					scorecount++;
					printf("%d -> ", scorecount + 1);
				}
			}

			if (count3 >= 1 && count4  >= 1 && count5 >= 1 && count6 >= 1 && scorecount < 1){
				printf("Small Straight (30 points)\n");
				scorechoice[scorecount] = 30;
				scorecount++;
				printf("%d -> ", scorecount + 1);
				if (count2 == 1){
					printf("Straight (40 points)\n");
					scorechoice[scorecount] = 40;
					scorecount++;
					printf("%d -> ", scorecount + 1);
				}
			}

			printf("Chance (%d points)\n", diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4]);
			scorechoice[scorecount] = diceroll[0] + diceroll[1] + diceroll[2] + diceroll[3] + diceroll[4];

		}// leave this brace alone. Closes choice 3//
			else{
				printf("Invalid Choice.\n");
				error++;
			}
		
		}
		c = getchar();
		while(c != '\n' && choice == 3 && error < 1){
				if (c == '1' && choice == 3){
					printf("Your score is: %d points\n", scorechoice[0]);
				}
				else if (c == '2' && scorecount >= 1 && choice == 3){
					printf("Your score is: %d points\n", scorechoice[1]);
				}
				else if (c == '3' && scorecount >= 2 && choice == 3){
					printf("Your score is: %d points\n", scorechoice[2]);
				}
				else if (c == '4' && scorecount == 3 && choice == 3){
					printf("Your score is: %d points\n", scorechoice[3]);
				}
				else {
					printf("Invalid Choice. \n");
				}
				c = getchar();
			}
	}
	return 0;
}
