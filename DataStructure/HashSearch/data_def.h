/*
	���ݽṹ���Ͷ���
*/
typedef int KeyType;

#define EQ(a,b) ((a)==(b))//�ж����
#define LT(a,b) ((a) <(b))//С��
#define LQ(a,b) ((a)<=(b))//С�ڵ���

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
