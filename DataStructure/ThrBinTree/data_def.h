/*
	���ݽṹ���Ͷ���
*/
typedef int TElemType;
typedef enum PointerTag{
	Link,//ָ��
	Thread//����
};
typedef struct BiThrNode{
	TElemType data;//������
	struct BiThrNode *lchild;//����
	struct BiThrNode *rchild;//�Һ���
	PointerTag LTag,RTag;//���ұ��
}BiThrNode , *BiThrTree;

