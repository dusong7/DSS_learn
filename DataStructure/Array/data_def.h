/*
	���ݽṹ���Ͷ���
*/

#define MAX_ARRAY_DIM 8//�䳤���� ���ֵ

typedef int ElemType;

typedef struct{
	ElemType *base;
	int	     dim;//���鳤��
	int      *bounds;//������ַ
	int	     *constans;//����ӳ����������ַ
}Array;

