/*
	数据结构类型定义
*/

typedef int KeyType;//数据类型

#define EQ(a,b) ((a)==(b))//判断相等
#define LT(a,b) ((a) <(b))//小于
#define LQ(a,b) ((a)<=(b))//小于等于

typedef struct{
	KeyType key;
	int weight;//权域
}ElemType;

typedef struct {
	ElemType *elem;//数据元素基址，0为空
	int length;//长度
}SSTable;

//定义树
typedef struct BiTNode{
	ElemType data;//数据域
	int id;//对应的序号
	struct BiTNode *lchild;//左指针
	struct BiTNode *rchild;//右指针
}BiTNode,*BiTree;

typedef BiTree SOSTree;