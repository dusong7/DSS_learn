/*
	���ݽṹ���Ͷ���
*/


//����������
typedef int TElemType;
typedef struct BiTNode{
	TElemType data;//������
	struct BiTNode *lchild;//��ָ��
	struct BiTNode *rchild;//��ָ��
}BiTNode,*BiTree;


typedef BiTree ElemType;

#define STACK_INIT_SIZE 100//��ʼ��С
#define STACKINCREMENT 10//�����������С

typedef struct{
	ElemType *top;//ջ��ָ��
	ElemType *base;//ջ�ĳ�ʼΪ��
	int stacksize;//�ѷ����ջ�ռ�
}SqStack;