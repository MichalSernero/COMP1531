#include <stdio.h>

#define TRUE     1
#define FALSE    0

#define SIZE     3

#define NONE    -1
#define NOUGHTS  0
#define CROSSES  1
#define EMPTY    2

void  scanBoard( int board[SIZE][SIZE] );
void printBoard( int board[SIZE][SIZE] );
void   getWinner( int board[SIZE][SIZE] );

int main( void ){

  int board[SIZE][SIZE];

  printf("Please enter the board:\n");
  scanBoard( board );
   
  printf("Here is the board:\n");
  printBoard( board );

  getWinner( board );

  return 0;
}

void scanBoard ( int board[SIZE][SIZE] ) {
	int row = 0;
	while(row < SIZE){
		int col = 0;
		while(col < SIZE){
			int marker = 0; 
			scanf("%d", &marker);
			board[row][col] = marker;
			col++;
		}
		row++;	
	}
}

void printBoard(int board[SIZE][SIZE]) {
	int row = 0;
	while(row < SIZE){
		int col = 0;
		while(col < SIZE){
			if(board[row][col] == NOUGHTS){
				printf("O ");
			}else if(board[row][col] ==CROSSES){
				printf("X ");
			}else if(board[row][col] == EMPTY){
				printf(". ");
			}
			
		col++;
		}
	printf("\n");
	row++;
	}
}


void getWinner( int board[SIZE][SIZE]){ 
	int winner = NONE;
	int row = 0;
	int col = 0;
	int NoughtCount = 0;
	int CrossesCount = 0;


	while(row < SIZE){
		while(col < SIZE){
			if(board[row][col] == NOUGHTS){
				NoughtCount = NoughtCount + 1;
			}else if(board[row][col] == CROSSES){	
				CrossesCount = CrossesCount + 1;
			}
			col++;
		}
			if (NoughtCount == SIZE){
				printf("Noughts Win\n");
				winner = TRUE;
			}else if(CrossesCount == SIZE){
				printf("Crosses Win\n");
				winner = TRUE;
			} else{ 
				winner = FALSE;
			}
		NoughtCount = 0;
		CrossesCount = 0;
		row++;
	}
row = 0;
col = 0;
	while(winner != TRUE){
		while(col < SIZE && winner != TRUE){
			while(row < SIZE){
				if(board[row][col] == NOUGHTS){
					NoughtCount = NoughtCount + 1;}
				else if(board[row][col] == CROSSES){
					CrossesCount = CrossesCount + 1;}
				row++;
				}
			}
			if (NoughtCount == SIZE){
				printf("Noughts Win\n");
				winner = TRUE;}
			else if(CrossesCount == SIZE){
				printf("Crosses Win\n");
				winner = TRUE;}
			NoughtCount = 0;
			CrossesCount = 0;
			col++;
		}	
		printf("%d\n",winner);		
}

	row = 0;
	col = 0;
	while(winner != TRUE){
		while(row < SIZE && col < SIZE){
				if(board[row][col] == NOUGHTS){
					NoughtCount = NoughtCount + 1;}
				else if(board[row][col] == CROSSES){
					CrossesCount = CrossesCount + 1;}
				row++;
				col++;
				}
			if (NoughtCount == SIZE){
				printf("Noughts Win\n");
				winner = TRUE;}
			else if(CrossesCount == SIZE){
				printf("Crosses Win\n");
				winner = TRUE;}
			NoughtCount = 0;
			CrossesCount = 0;
		
}

	row = 0;
	col = SIZE - 1;
	while(winner != TRUE){
		while(row < SIZE && col > 0){
			if(board[row][col] == NOUGHTS){
				NoughtCount = NoughtCount + 1;}
			else if(board[row][col] == CROSSES){
				CrossesCount = CrossesCount + 1;}
			row++;
			col--;
			}
		if (NoughtCount == SIZE){
			printf("Noughts Win\n");
			winner = TRUE;}
		else if(CrossesCount == SIZE){
			printf("Crosses Win\n");
			winner = TRUE;}
		NoughtCount = 0;
		CrossesCount = 0;
		}

	if(winner == FALSE){
		printf("No Winner\n");
}
