/*
	���ݽṹ���Ͷ���
*/

//�¼�ģ��
typedef struct{
	int ArrivaTime;//����ʱ��
	int Duration;//����ҵ������ʱ��
}QElemType;//�ж�����Ԫ������

typedef struct{
	int OccurTime;//�¼�����ʱ��
	int NType;//�¼����ͣ�0Ϊ���1-4Ϊ�뿪
}Event,ElemType;


//�жӲ���
typedef struct QNode{
	QElemType data;//����
	struct QNode *next;//��һ�����
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;//����ͷ
	QueuePtr rear;//����β
}LinkQueue;

//������
typedef struct LNode{
	ElemType data;//�����е�����
	struct LNode *next;//�������һ����ַ
}LNode,*LinkList;

//�¼�ģ��
typedef LinkList EvenList;