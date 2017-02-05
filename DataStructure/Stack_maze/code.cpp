/*
	数据结构操作源码
*/

#include "head.h"


Status Pass(MazeType maze,PosType cur){
	//判断该点是否走过
	if(maze[cur.x][cur.y]==0)return 1;
	else return 0;
}//Pass

Status Footprint(MazeType &maze,PosType cur){
	maze[cur.x][cur.y]=2;
	return OK;
}//Footprint

Status MarkPrint(MazeType &maze,PosType cur){
	maze[cur.x][cur.y]=3;
	return OK;
}//MarkPrint

PosType NextPos(PosType &cur,int i){
	switch(i){
	case 1:--cur.x;break;
	case 2:++cur.x;break;
	case 3:--cur.y;break;
	case 4:++cur.y;break;
	default:exit(OVERFLOW);
	}
	return cur;
}
Status MazePath(MazeType &maze,PosType start,PosType end,SqStack &S){
	InitStack(S);
	PosType curpos=start;
	int curstep=1;//初始步数
	ElemType e;
	do{
		if(Pass(maze,curpos)){
			Footprint(maze,curpos);
			e.ord=curstep;e.seat=curpos;e.di=1;
			Push(S,e);
			if(curpos.x==end.x && curpos.y==end.y)return TRUE;
			curpos=NextPos(curpos,1);
			curstep++;
		}else{
			if(!StackEmpty(S)){
				Pop(S,e);
				while(e.di==4 && !StackEmpty(S)){
					MarkPrint(maze,e.seat);
					Pop(S,e);
				}//while
				if(e.di<4){
					e.di++;
					Push(S,e);
					curpos=NextPos(e.seat,e.di);
				}
			}
		}
	}while(!StackEmpty(S));

	return FALSE;
}//MazePath