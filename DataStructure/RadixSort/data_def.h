/*
	���ݽṹ���Ͷ���
*/

#define MAX_NUM_OF_KEY 8 //�ؼ����������ֵ
#define RADIX 10 //�ؼ��ֻ��� ��ʱΪ10��������
#define MAX_SPACE 10

typedef int KeysType;
typedef int InfoType;
typedef struct {
	KeysType keys[MAX_NUM_OF_KEY];
	InfoType otheritems;
	int next;
}SLCell;
typedef struct {
	SLCell r[MAX_SPACE];//0Ϊͷ���
	int keynum;//�ؼ��ָ���
	int recnum;//��̬������
}SLList;
typedef int ArrType[RADIX];//ָ����������