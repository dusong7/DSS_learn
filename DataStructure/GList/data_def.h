/*
	广义表类型定义
	数据结构类型定义
*/


//串数据定义
#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN+1];//0存数据长度


typedef enum {
	ATOM,//原子
	LIST//子表
}ElemTag;

typedef struct{SString s;}AtomType;

typedef struct GLNode{
	ElemTag tag;//公共部分，用于区分原子结点和表结点
	union{
		AtomType atom;//原子结点值域
		struct{
			struct GLNode *hp;//指向表头
			struct GLNode *tp;//指向表尾
		}ptr;//表结点指针域
	};
}*GList;//广义表类型

//另一种定义
typedef struct GLNode2{
	ElemTag tag;//公共部分，用于区分原子结点和表结点
	union{
		AtomType atom;//原子结点值域
		struct GLNode2 *hp;//表结点的表头指针
	};
	struct GLNode2 *tp;//指向下一个元素的结点，相当于线性链表的下一个
}*GList2;//广义表类型GList是一种可拓展的线性链表

//m元多项式广义表
typedef struct MPNode{
	ElemTag tag;//区分原子结点还是表结点
	int exp;//指数区域
	union {
		float coef;//系数域
		struct MPNode *hp;//表结点
	};
	struct MPNode *tp;//指向下一个元素的结点
}*MPList;//m元多项式广义表类型

