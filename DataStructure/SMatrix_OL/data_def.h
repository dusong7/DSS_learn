/*
	���ݽṹ���Ͷ���
*/

typedef int ElemType;

typedef struct OLNode{
	int i;//��
	int j;//��
	ElemType e;//����
	struct OLNode *right;//�����еĺ��
	struct OLNode *down;//�����еĺ��
}OLNode,*OLink;

typedef struct{
	OLink *rhead;//��ͷָ��
	OLink *chead;//��ͷָ��
	int mu;//ϡ���������
	int nu;//ϡ���������
	int tu;//ϡ��������Ԫ�ظ���
}CrossList;
