/*
	���ݽṹ���Ͷ���
*/

#define LIST_INIT_SIZE 100//��ʼ������
#define LISTINCREMENT 10//ÿ�����ӵ����ݳ���

typedef struct{
	char name[20];
	int age;
}Data,*DATA;
typedef DATA ElemType;

typedef struct {
	ElemType *elem;//�洢�ռ������ַ
	int	length;//���ݳ���
	int listsize;//�����ܸ���
}SqList;