/*
	���ݽṹ���Ͷ���
*/

typedef struct{
	char name[20];
	int age;
}ElemType;

typedef struct LNode{
	ElemType data;//�����е�����
	struct LNode *next;//�������һ����ַ
}LNode,*LinkList;