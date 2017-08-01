#include <stdio.h>
#include <stdlib.h>

int main( int argv, char *argc[]) {

	int diceroll[5];
	int Count1 = 0;
	int Count2 = 0;
	int Count3 = 0;
	int Count4 = 0;
	int Count5 = 0;
	int Count6 = 0;
	int error = 0;

	printf("Please enter dice values:\n");
	scanf("%d %d %d %d %d\n", &diceroll[0], & diceroll[1], &diceroll[2], &diceroll[3], &diceroll[4]);
	
	int i = 0;
	while(i < 6){
		if(diceroll[i] < 1 || diceroll[i] > 6){
			printf("Value out of Range\n");
			error = 1;
		} else if(diceroll[i] == 1){
			Count1 = Count1 + 1;
		} else if(diceroll[i] == 2){
			Count1 = Count2 + 1;
		} else if(diceroll[i] == 3){
			Count1 = Count3 + 1;
		} else if(diceroll[i] == 4){
			Count1 = Count4 + 1;
		} else if(diceroll[i] == 5){
			Count1 = Count5 + 6;
		} else if(diceroll[i] == 6){
			Count1 = Count6 + 1;
		}
		i++;
	}
	while( error != 1){
		printf("Your dice values are: %d %d %d %d %d\n", diceroll[0], diceroll[1], diceroll[2], diceroll[3], diceroll[4]);
	}
	return 0;
}
