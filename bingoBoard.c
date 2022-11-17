// bingoBoard.c

#define N_SIZE 5
#define N_BINGO 2
#define HOLE 99
#include "bingoBoard.h"
#include <stdlib.h>
#include <time.h>

static int bingoBoard[N_SIZE][N_SIZE];
static int numberStatus[N_SIZE*N_SIZE];

void bingo_init(void){
	int i, j ,cnt = 1;
	for (i =0; i<N_SIZE; i++){
		for (j = 0; j<N_SIZE; j++){
			bingoBoard[i][j] = cnt;
			numberStatus[cnt-1] = N_SIZE*i+j;
			cnt++;
		}
	}
}

//빙고 출력하는 함수 
void bingo_printBoard(void){
	
	int i,j;
	
	printf("=================================\n");
	
	for (i =0; i<N_SIZE; i++){
		for (j = 0; j<N_SIZE; j++){
			if(bingoBoard[i][j]>0 && bingoBoard[i][j]<= N_SIZE*N_SIZE) {
				printf("%i\t", bingoBoard[i][j]);
			}
			else printf("X\t");
		}
		printf("\n");
	}
	
	printf("=================================\n");
}
void bingo_inputNum(int sel){
	int i = numberStatus[sel-1] / N_SIZE;
	int j = numberStatus[sel-1] % N_SIZE;
	bingoBoard[i][j] = HOLE;
	numberStatus[sel-1] = HOLE;
}
int bingo_countCompletedLine(void){
	
}

