/*
	数据结构类型定义
*/
typedef int KeyType;

#define EQ(a,b) ((a)==(b))//判断相等
#define LT(a,b) ((a) <(b))//小于
#define LQ(a,b) ((a)<=(b))//小于等于

typedef struct{
	KeyType key;
}ElemType;

typedef struct{
	ElemType *elem;
	int count;
	//int sizeindex;
}HashTable;

#define NULLKEY -1
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
