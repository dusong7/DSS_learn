/*
	���ݽṹ���Ͷ���
*/

typedef int Data;

#define STACK_INIT_SIZE 100//��ʼ��С
#define STACKINCREMENT 10//�����������С

typedef Data ElemType;
typedef struct{
	ElemType *top;//ջ��ָ��
	ElemType *base;//ջ�ĳ�ʼΪ��
	int stacksize;//�ѷ����ջ�ռ�
}SqStack;