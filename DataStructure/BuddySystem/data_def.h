/*
	���ݽṹ���Ͷ���
*/

#define m 16 //�����ÿռ�������64K�ֵ�2���ݴΣ��ֱ�ĸ���Ϊm+1

typedef int OtherType;

typedef struct WORD_b{
	WORD_b *llink;//ָ��ǰ��
	int tag;//0���� 1ռ��
	int kval;//���С ֵΪ2���ݴ� k
	WORD_b *rlink;//ָ����
	OtherType other;//���������Ϣ
}WORD_b,head;

typedef struct HeadNode{
	int nodesize;//��������п�Ĵ�С
	WORD_b *first;//����ͷָ��
}FreeList[m+1];//��ͷ��������