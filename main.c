#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"

int check_gameEnd(void);
int get_number(void);

int main(void){
	srand((unsigned)time(NULL));
	
	int isEnd = 0;
	
	//������ 
	printf("********************************************\n");
	printf("              BINGO GAME\n");
	printf("********************************************\n");
	
	bingo_init();
	bingo_printBoard();
	//����
	while(!isEnd){
		bingo_inputNum(get_number());
		bingo_printBoard();
		if (bingo_countCompletedLine() >= N_BINGO) isEnd = 1;
	}
	//����
	printf("********************************************\n");
	printf("              CONGRATULATION\n");
	printf("********************************************\n");
	
	
	return 0;
}

int check_gameEnd(void){
	//int res = BINGO_RES_UNFINISHED;
} 

//���� ��ȣ �Է¹ޱ� 
int get_number(void){
	int selNum =0;
	do {
		printf("���ڸ� ����ּ���: ");
		scanf("%d", &selNum);
		fflush(stdin);
		if (selNum<1 ||selNum> N_SIZE*N_SIZE ||bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT) {
			printf("%i�� ���忡 �����ϴ�. �ٽ� �Է����ּ���\n", selNum);
		}
	} while(selNum<1 ||selNum> N_SIZE*N_SIZE ||bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT);
	
	return selNum;
} 

