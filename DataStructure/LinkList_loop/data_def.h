/*
	数据结构类型定义
*/

typedef struct {
	char name[20];
	int age;
}ElemType;

typedef struct DuLNode{
	ElemType data;//数据
	struct DuLNode *prior;//上一个
	struct DuLNode *next;//下一个
}DuLNode,*DuLinkList;