/*
	���ݽṹ���Ͷ���
*/

#define SIZE 100 //��̬������
typedef int RcdType;

typedef struct{
	RcdType rc;//��¼��
	int next;//ָ����
}SLNode;

typedef struct{
	SLNode r[SIZE];//��¼ֵ
	int length;//����
}SLinkListType;
