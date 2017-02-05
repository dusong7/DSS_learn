/*
	数据结构类型定义
*/

typedef int Data;

#define STACK_INIT_SIZE 100//初始大小
#define STACKINCREMENT 10//分配的增量大小

typedef Data ElemType;
typedef struct{
	ElemType *top;//栈顶指针
	ElemType *base;//栈的初始为空
	int stacksize;//已分配的栈空间
}SqStack;