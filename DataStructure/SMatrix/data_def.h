/*
	���ݽṹ���Ͷ���
*/

typedef int ElemType;

#define MAXSIZE 12500 //���÷���Ԫ�ص����ֵ
typedef struct{
	int i,j;//����Ԫ�ص��±�
	ElemType e;
}Trilpe;

typedef struct{
	Trilpe data[MAXSIZE + 1];//����Ԫ��Ԫ��� Data[0]δʹ��
	int mu;//��������
	int nu;//��������
	int tu;//�������Ԫ�ظ���
}TSMatrix;

#define MAXRC 1000

typedef struct{
	Trilpe data[MAXSIZE+1];//����Ԫ����
	int rpos[MAXRC+1];//���е�һ������Ԫ��λ�ñ�
	int mu;//��������
	int nu;//��������
	int tu;//�������Ԫ�ظ���
}RLSMatrix;


