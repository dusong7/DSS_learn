/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	MazeType maze={
		/*    0 1 2 3 4 5 6 7 8 9*/
		/*0*/{1,1,1,1,1,1,1,1,1,1},
		/*1*/{1,0,0,1,0,0,0,1,0,1},
		/*2*/{1,0,0,1,0,0,0,1,0,1},
		/*3*/{1,0,0,0,0,1,1,0,0,1},
		/*4*/{1,0,1,1,1,0,0,0,0,1},
		/*5*/{1,0,0,0,1,0,0,0,0,1},
		/*6*/{1,0,1,0,0,0,1,0,0,1},
		/*7*/{1,0,1,1,1,0,1,1,0,1},
		/*8*/{1,1,0,0,0,0,0,0,0,1},
		/*9*/{1,1,1,1,1,1,1,1,1,1}
	};
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)printf("%d ",maze[i][j]);
		printf("\n");
	}
	PosType start={1,1},end={8,8};
	SqStack S;
	if(MazePath(maze,start,end,S)){
		printf("OK\n");
	}else{
		printf("ERROR\n");
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)printf("%d ",maze[i][j]);
		printf("\n");
	}

	printf("\nResult End!\n");
	system("pause");
	return 0;
}