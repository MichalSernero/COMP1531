#include <stdio.h>

int main (int argc, char *argv[]) {

	int number = 0;
	int i = 1;
	int sum = 0;

	printf("Enter number: ");
	scanf("%d", &number);
	printf("The factors of %d are:\n", number);

	for(i=1; i<=number; ++i) {
		if(number%i == 0) {
			sum = sum + i;
			printf("%d\n", i);
	}
	}

	sum = sum - number;
	printf("Sum of factors = %d\n", sum);

	if(number == sum) {
		printf("%d is a perfect number.\n", number);
	} else {
		printf("%d is not a perfect number.\n", number);
	}
	return 0;
}
