/*
	���ݽṹ���Ͷ���
	
	����洢����Ԫ�أ����㣩����Ϣ������Ԫ��֮��Ĺ�ϵ���߻򻡣�����Ϣ

*/

#define INFINIY INT_MAX //int ���ֵ
#define MAX_VERTEX_NUM 20//��󶥵����

typedef int VRType;
typedef enum{
	DG,//����ͼ
	DN,//������
	UDG,//����ͼ
	UDN//������
}GraphKind;
typedef struct{
	int length;//����
	float angle;//����
}InfoType;
typedef struct ArcCell{
	VRType adj;//VRType�Ƕ����ϵ���ͣ�����Ȩͼ����1��0��ʾ���ڷ���Ȩͼ��ʾ��Ȩֵ����
	InfoType *info;//�û������Ϣ
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef int VertexType;
typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];//��������
	AdjMatrix arcs;//�ڽӾ���
	int vexnum;//������
	int arcnum;//����
	GraphKind kind;//ͼ������
}MGraph;