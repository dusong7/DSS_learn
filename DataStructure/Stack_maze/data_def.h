/*
	数据结构类型定义
*/

typedef int MazeType[10][10];//迷宫定义为10*10的数组,0为通道,1为非通道,2为走过,3为不能通过
typedef struct{
	int x;
	int y;
}PosType;
typedef struct{
	int ord;//通道块的序号 1 2 3 4 5 6 
	PosType seat;//位置坐标
	int di;//此通道走向下一块通道的方向 1 up 2 down 3 left 4 right
}ElemType;

//begin

#define STACK_INIT_SIZE 100//初始大小
#define STACKINCREMENT 10//分配的增量大小

typedef struct{
	ElemType *top;//栈顶指针
	ElemType *base;//栈的初始为空
	int stacksize;//已分配的栈空间
}SqStack;