#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"

int main(void){
	srand((unsigned)time(NULL));
	
	int isEnd = 0;
	
	//오프닝 
	printf("********************************************\n");
	printf("              BINGO GAME\n");
	printf("********************************************\n");
	
	//게임
	while(!isEnd){
		bingo_init();
		bingo_printBoard();
		isEnd = 1;
	}
	
	//엔딩
	printf("********************************************\n");
	printf("              CONGRATULATION\n");
	printf("********************************************\n");
	
	
	return 0;
}
