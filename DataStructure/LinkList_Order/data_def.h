/*
	数据结构类型定义
*/

#define LIST_INIT_SIZE 100//初始化长度
#define LISTINCREMENT 10//每次增加的数据长度

typedef struct{
	char name[20];
	int age;
}Data,*DATA;
typedef DATA ElemType;

typedef struct {
	ElemType *elem;//存储空间基数地址
	int	length;//数据长度
	int listsize;//数据总个数
}SqList;