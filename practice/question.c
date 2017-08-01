#include <stdio.h>

int main(int argc, char *argv[]) {

	int row, col, num, j;
	printf("Enter a number: ");
	scanf("%d", &num);
	j = num;
	for (row = 1; row <= num; row++) {
		for (col = 1; col<= j; col++) {
			printf("*");
		}
	printf("\n");
	j--;
	}
	return 0;
}
