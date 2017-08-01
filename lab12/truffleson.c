#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){
	
	FILE *f;
	char areaCode[12];
//	char * area;
	char buff[255];
	int i;

	char * truffle;
	for(i = 0; i < 100; i++){
		sprintf(areaCode, "area%d.txt", i);
		f = fopen(areaCode, "r");
		fscanf(f, "%s", buff);
		truffle = strstr(buff, "truffle");
		if(truffle != NULL){
			printf("area%d\n", i);
		}
		fclose(f);
	}
	
	return 0;
}
