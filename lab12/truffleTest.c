#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){
	
	char buff[255];
	char * truffle;
	FILE *f;
	f = fopen("area1.txt", "r");
	fscanf(f, "%s", buff);
	truffle = strstr(buff, "truffle");
	if (truffle != NULL){
		printf("area1\n");
	}
	fclose(f);

	return 0;
}
