/*
	���ݽṹ���Ͷ���
*/

typedef int KeyType;//��������

#define EQ(a,b) ((a)==(b))//�ж����
#define LT(a,b) ((a) <(b))//С��
#define LQ(a,b) ((a)<=(b))//С�ڵ���

typedef struct{
	KeyType key;
	int weight;//Ȩ��
}ElemType;

typedef struct {
	ElemType *elem;//����Ԫ�ػ�ַ��0Ϊ��
	int length;//����
}SSTable;

//������
typedef struct BiTNode{
	ElemType data;//������
	int id;//��Ӧ�����
	struct BiTNode *lchild;//��ָ��
	struct BiTNode *rchild;//��ָ��
}BiTNode,*BiTree;

typedef BiTree SOSTree;