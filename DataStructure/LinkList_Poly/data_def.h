/*
	���ݽṹ���Ͷ���
*/

typedef struct {
	float coef;//ϵ��
	int expn;//ָ��
}trem,ElemType;

typedef struct LNode{
	ElemType data;//�洢�ռ������ַ
	struct LNode *next;//��һ����ַ
}*LinkList,*Postion;

typedef LinkList polynomail;//˳���Ķ���