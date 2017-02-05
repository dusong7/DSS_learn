/*
	数据结构类型定义
*/

#define MAX_NUM_OF_KEY 8 //关键字项数最大值
#define RADIX 10 //关键字基数 此时为10进制整数
#define MAX_SPACE 10

typedef int KeysType;
typedef int InfoType;
typedef struct {
	KeysType keys[MAX_NUM_OF_KEY];
	InfoType otheritems;
	int next;
}SLCell;
typedef struct {
	SLCell r[MAX_SPACE];//0为头结点
	int keynum;//关键字个数
	int recnum;//静态链表长度
}SLList;
typedef int ArrType[RADIX];//指针数组类型