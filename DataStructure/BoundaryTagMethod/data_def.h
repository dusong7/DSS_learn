/*
	���ݽṹ���Ͷ���
*/

typedef int OtherType;

typedef struct WORD{
	union {//head �� foot�ֱ��ǽ��ĵ�һ���ֺ�������
		WORD *llink;//ͷ����ָ��ǰ�����
		WORD *uplink;//�ײ���ָ�򱾽��ͷ��
	};
	int tag;//���־��0:���� 1:ռ�ã�ͷ����β������
	int size;//ͷ���򣬿��С
	WORD *rlink;//ͷ����ָ���̽��
	OtherType other;//�ֵ���������
} WORD, head, foot, *Space;

#define FootLoc(p) p+p->size-1//ָ��p��ָ���ĵײ�