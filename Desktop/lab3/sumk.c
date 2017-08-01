#include <stdio.h>

int main (int argc, char *argv[]) {

	int k = 1;
	int sum = 0;

	while( k<16 ) {
		sum = sum + k;
		printf("%4d %4d\n", k, sum);
		++k;
}

	return 0;
}
