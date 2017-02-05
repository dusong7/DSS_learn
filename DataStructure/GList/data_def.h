/*
	��������Ͷ���
	���ݽṹ���Ͷ���
*/


//�����ݶ���
#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN+1];//0�����ݳ���


typedef enum {
	ATOM,//ԭ��
	LIST//�ӱ�
}ElemTag;

typedef struct{SString s;}AtomType;

typedef struct GLNode{
	ElemTag tag;//�������֣���������ԭ�ӽ��ͱ���
	union{
		AtomType atom;//ԭ�ӽ��ֵ��
		struct{
			struct GLNode *hp;//ָ���ͷ
			struct GLNode *tp;//ָ���β
		}ptr;//����ָ����
	};
}*GList;//���������

//��һ�ֶ���
typedef struct GLNode2{
	ElemTag tag;//�������֣���������ԭ�ӽ��ͱ���
	union{
		AtomType atom;//ԭ�ӽ��ֵ��
		struct GLNode2 *hp;//����ı�ͷָ��
	};
	struct GLNode2 *tp;//ָ����һ��Ԫ�صĽ�㣬�൱�������������һ��
}*GList2;//���������GList��һ�ֿ���չ����������

//mԪ����ʽ�����
typedef struct MPNode{
	ElemTag tag;//����ԭ�ӽ�㻹�Ǳ���
	int exp;//ָ������
	union {
		float coef;//ϵ����
		struct MPNode *hp;//����
	};
	struct MPNode *tp;//ָ����һ��Ԫ�صĽ��
}*MPList;//mԪ����ʽ���������

