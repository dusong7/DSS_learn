/*
	���ݽṹ���Ͷ���
*/

typedef int MazeType[10][10];//�Թ�����Ϊ10*10������,0Ϊͨ��,1Ϊ��ͨ��,2Ϊ�߹�,3Ϊ����ͨ��
typedef struct{
	int x;
	int y;
}PosType;
typedef struct{
	int ord;//ͨ�������� 1 2 3 4 5 6 
	PosType seat;//λ������
	int di;//��ͨ��������һ��ͨ���ķ��� 1 up 2 down 3 left 4 right
}ElemType;

//begin

#define STACK_INIT_SIZE 100//��ʼ��С
#define STACKINCREMENT 10//�����������С

typedef struct{
	ElemType *top;//ջ��ָ��
	ElemType *base;//ջ�ĳ�ʼΪ��
	int stacksize;//�ѷ����ջ�ռ�
}SqStack;