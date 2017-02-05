/*
	数据结构类型定义
*/

//事件模拟
typedef struct{
	int ArrivaTime;//到达时刻
	int Duration;//办理业务所需时间
}QElemType;//列队数据元素类型

typedef struct{
	int OccurTime;//事件发生时刻
	int NType;//事件类型，0为到达，1-4为离开
}Event,ElemType;


//列队操作
typedef struct QNode{
	QElemType data;//数据
	struct QNode *next;//下一个结点
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;//队列头
	QueuePtr rear;//队列尾
}LinkQueue;

//链表定义
typedef struct LNode{
	ElemType data;//链表中的数据
	struct LNode *next;//链表的下一个地址
}LNode,*LinkList;

//事件模拟
typedef LinkList EvenList;