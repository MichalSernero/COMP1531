#include <stdio.h>
#include <stdlib.h>

int rotate_right(int ch);
int rotate_left(int ch);
int encode(int ch, int shift);

int main(int argv, char *argc[]){

	 int ch;
	 int shift = 0;
	 printf("Enter shift: ");
	 scanf("%d", &shift);
	 printf("Enter Text: ");
	 ch = getchar();
	 while(ch != EOF){
		putchar(encode(ch, shift));
		ch = getchar();
	}

return EXIT_SUCCESS;
}
	 

int rotate_right(int ch){
	 if (ch >= 'A' && ch < 'Z'){
			ch = ch + 1;
	}else if (ch == 'Z'){
			ch = 'A';
	}else if (ch >= 'a' && ch < 'z'){
			ch = ch + 1;
	}else if (ch == 'z'){
			ch = 'a';
	}

return ch;
}

int rotate_left(int ch){
	if (ch > 'A' && ch <= 'Z'){
			ch = ch - 1;
	}else if (ch == 'A'){
			ch = 'Z';
	}else if (ch > 'a' && ch <= 'z'){
			ch = ch - 1;
	}else if (ch == 'a'){
			ch = 'z';
	}

return ch;
}

int encode(int ch, int shift){
	int i = 0;
	if (shift > 0){
		while (i != shift){
			ch = rotate_right(ch);
			++i;
		}
	}else if(shift < 0){
		while (i != shift){
			ch = rotate_left(ch);
			--i;
		}
	}

return ch;
}
	
		
	
