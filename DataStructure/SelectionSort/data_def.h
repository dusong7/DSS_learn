/*
	���ݽṹ���Ͷ���
*/

#define MAXSIZE 10000
typedef int KeyType;//�ؼ�������
typedef int InfoType;
typedef struct{
	KeyType key;
	InfoType otherInfo;
}RedType;

typedef struct{
	RedType r[MAXSIZE+1];//r[0]����
	int length;//���ݳ���
}SqList;


#define EQ(a,b) ((a)==(b))//�ж����
#define LT(a,b) ((a) <(b))//С��
#define LQ(a,b) ((a)<=(b))//С�ڵ���