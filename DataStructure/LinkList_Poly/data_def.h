/*
	数据结构类型定义
*/

typedef struct {
	float coef;//系数
	int expn;//指数
}trem,ElemType;

typedef struct LNode{
	ElemType data;//存储空间基数地址
	struct LNode *next;//下一个地址
}*LinkList,*Postion;

typedef LinkList polynomail;//顺序表的定义