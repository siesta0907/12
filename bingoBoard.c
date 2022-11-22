// bingoBoard.c


#define HOLE -1


#include "bingoBoard.h"
#include <stdlib.h>
#include <time.h>

static int bingoBoard[N_SIZE][N_SIZE];
static int numberStatus[N_SIZE*N_SIZE];

//���� ������ 
void bingo_init(void){
	int i, j ,cnt = 0;
	int randNum;
	int maxNum = N_SIZE*N_SIZE;
	
	for (i=0; i<maxNum; i++){
		numberStatus[i] = 0;
	}
	
	for (i =0; i< N_SIZE; i++){
		for (j = 0; j< N_SIZE; j++){
			while(1){
				//1~25������ ���� 
				randNum = (rand()%(maxNum))+1;
				
				//�Ҵ���� ����  �� 
				if ((numberStatus[randNum-1])==0){
					bingoBoard[i][j] = randNum;
					numberStatus[randNum-1] = N_SIZE*i+j;
					printf("%d\n", randNum); 
					break; 
				}
			}
		}
	}
}

//���� ����ϴ� �Լ� 
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

//���� �Է¹޾� ���� �մ� �Լ� 
void bingo_inputNum(int sel){
	int i = numberStatus[sel-1] / N_SIZE;
	int j = numberStatus[sel-1] % N_SIZE;
	bingoBoard[i][j] = HOLE;
	numberStatus[sel-1] = HOLE;
}

//���� ������ ���������? 
int bingo_countCompletedLine(void){
	int i,j;
	int cnt =0;
	int checkBingo;
	
	//���� Ȯ�� 
	for (i=0; i<N_SIZE; i++){
		checkBingo = 1;
		for (j =0; j<N_SIZE; j++){
			if (bingoBoard[i][j] >0){
				checkBingo= 0;
				break;
			}
		}
		if (checkBingo ==1){
			cnt ++;
		}
	}
	
	//���� Ȯ��
	for (i=0; i<N_SIZE; i++){
		checkBingo = 1;
		for (j =0; j<N_SIZE; j++){
			if (bingoBoard[j][i] >0){
				checkBingo= 0;
				break;
			}
		}
		if (checkBingo ==1){
			cnt ++;
		}
	}
	
	//�밢�� Ȯ��
	//(0,0) (1,1) (2,2) (3,3) (4,4)
	 for (i=0; i<N_SIZE; i++){
		checkBingo = 1;
		if (bingoBoard[i][i] >0){
			checkBingo= 0;
			break;
			}
	}
	if (checkBingo ==1) cnt ++;
	//�밢�� Ȯ��2
	// (0,4) (1,3) (2,2) (3,1) (4,0)
	
	for (i=0; i<N_SIZE; i++){
		checkBingo = 1;
		if (bingoBoard[i][N_SIZE-1-i] >0){
			checkBingo= 0;
			break;
			}
		
		}
	if (checkBingo ==1)cnt ++;
	
	
	return cnt;
}


//���忡 ��ȣ�� �ֳ�? 
int bingo_checkNum(int selNum){
	if (numberStatus[selNum-1]==HOLE) return BINGO_NUMSTATUS_ABSENT;
	else return BINGO_NUMSTATUS_PRESENT;
}


