/*
	数据结构类型定义
*/
typedef int TElemType;
typedef enum PointerTag{
	Link,//指针
	Thread//线索
};
typedef struct BiThrNode{
	TElemType data;//数据域
	struct BiThrNode *lchild;//左孩子
	struct BiThrNode *rchild;//右孩子
	PointerTag LTag,RTag;//左右标记
}BiThrNode , *BiThrTree;

