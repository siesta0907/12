#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"

int main(void){
	srand((unsigned)time(NULL));
	
	int isEnd = 0;
	
	//������ 
	printf("********************************************\n");
	printf("              BINGO GAME\n");
	printf("********************************************\n");
	
	//����
	while(!isEnd){
		bingo_init();
		bingo_printBoard();
		isEnd = 1;
	}
	
	//����
	printf("********************************************\n");
	printf("              CONGRATULATION\n");
	printf("********************************************\n");
	
	
	return 0;
}
