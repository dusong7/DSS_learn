/*
	数据结构类型定义
*/

#define MAXSIZE 10000
typedef int KeyType;//关键字类型
typedef int InfoType;
typedef struct{
	KeyType key;
	InfoType otherInfo;
}RedType;

typedef struct{
	RedType r[MAXSIZE+1];//r[0]闲置
	int length;//数据长度
}SqList;


#define EQ(a,b) ((a)==(b))//判断相等
#define LT(a,b) ((a) <(b))//小于
#define LQ(a,b) ((a)<=(b))//小于等于