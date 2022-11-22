#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"

int check_gameEnd(void);
int get_number(void);

int main(void){
	srand((unsigned)time(NULL));
	
	int isEnd = 0;
	
	//오프닝 
	printf("********************************************\n");
	printf("              BINGO GAME\n");
	printf("********************************************\n");
	
	bingo_init();
	bingo_printBoard();
	//게임
	while(!isEnd){
		bingo_inputNum(get_number());
		bingo_printBoard();
		if (bingo_countCompletedLine() >= N_BINGO) isEnd = 1;
	}
	//엔딩
	printf("********************************************\n");
	printf("              CONGRATULATION\n");
	printf("********************************************\n");
	
	
	return 0;
}

int check_gameEnd(void){
	//int res = BINGO_RES_UNFINISHED;
} 

//빙고 번호 입력받기 
int get_number(void){
	int selNum =0;
	do {
		printf("숫자를 골라주세요: ");
		scanf("%d", &selNum);
		fflush(stdin);
		if (selNum<1 ||selNum> N_SIZE*N_SIZE ||bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT) {
			printf("%i는 보드에 없습니다. 다시 입력해주세요\n", selNum);
		}
	} while(selNum<1 ||selNum> N_SIZE*N_SIZE ||bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT);
	
	return selNum;
} 

