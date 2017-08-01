#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){
	
	FILE *f;
	char areaCode[12];
//	char * area;
	char buff[255];
	int i;
	int count = 0;
	char * truffle;
	for(i = 0; i < 100; i++){
		sprintf(areaCode, "area%d", i);
		f = fopen(areaCode, "r");
		
		/*while (fscanf(f, "%s", buff)){
			char* truffle2 = "truffle"; 
			truffle = strstr(buff, truffle2);
		} */ 
 
        while (fgets(buff, 100, f)){
			char* truffle2 = "truffle"; 
			truffle = strstr(buff, truffle2);
			if(truffle != NULL && count == 0){
			printf("area%d\n", i);
			count++;
		}
		}
		/*if(truffle != NULL){
			printf("area%d\n", i);
		} */
		fclose(f);
		count = 0;
	}
	
	return 0;

}
