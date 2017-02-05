/*
	���ݽṹ���Ͷ���
*/

#define MaxBookNum 1000  //�����鼮��󳤶�
#define MaxKeyNum  2500  //��������������
#define MaxLineLen 500   //��Ŀ�����������
#define MaxWordNum 10    //�ʱ��������

//�ѷ������ݶ���
typedef struct{
	char *ch;        //�ǿ�ΪNULL������Ϊ����Ŀռ�
	int  length;      //������
}HString;	

typedef struct{
	char **item;     //�ַ�������
	int  last;       //�ʱ�ĳ���
}WordListType;

typedef int ElemType;      //��������Ԫ�����ͣ�������ͣ�

typedef struct LNode{
	ElemType     data;    //�洢�ռ������ַ
	struct LNode *next;   //��һ����ַ
}*LinkList;

typedef struct{
	HString  Key;        //�ؼ���
	LinkList BnoList;    //�����ŵ�����
}IdxTermType;            //������Ŀ����

typedef struct{
	IdxTermType item[MaxKeyNum+1];
	int         last;
}IdxListType;           //���������ͣ������

