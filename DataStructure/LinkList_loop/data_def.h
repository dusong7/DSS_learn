/*
	���ݽṹ���Ͷ���
*/

typedef struct {
	char name[20];
	int age;
}ElemType;

typedef struct DuLNode{
	ElemType data;//����
	struct DuLNode *prior;//��һ��
	struct DuLNode *next;//��һ��
}DuLNode,*DuLinkList;