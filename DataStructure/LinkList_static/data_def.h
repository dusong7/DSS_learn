/*
	���ݽṹ���Ͷ���
*/

typedef struct {
	char name[20];
	int age;
}ElemType;

#define MAXSIZE 100

typedef struct{
	ElemType data;
	int cur;
}component ,SLinkList[MAXSIZE];