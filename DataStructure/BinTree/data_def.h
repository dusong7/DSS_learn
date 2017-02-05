/*
	数据结构类型定义
*/


//二叉树定义
typedef int TElemType;
typedef struct BiTNode{
	TElemType data;//数据域
	struct BiTNode *lchild;//左指针
	struct BiTNode *rchild;//右指针
}BiTNode,*BiTree;


typedef BiTree ElemType;

#define STACK_INIT_SIZE 100//初始大小
#define STACKINCREMENT 10//分配的增量大小

typedef struct{
	ElemType *top;//栈顶指针
	ElemType *base;//栈的初始为空
	int stacksize;//已分配的栈空间
}SqStack;