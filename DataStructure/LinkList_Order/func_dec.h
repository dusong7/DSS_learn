/*
	��������
*/

//˳��������������
Status InitList(SqList &L);//��ʼ��˳���Ϊ������
Status ListInsert(SqList &L,int i,ElemType e);//����Ԫ�� iΪ���,eΪ����Ԫ��
Status ListDelete(SqList &L,int i,ElemType &e);//ɾ������Ԫ�� iΪ���� eΪɾ���󷵻ص�����
int    LocateElem(SqList L,ElemType e,int (* compare)(ElemType,ElemType));//��˳����в��ҵ�һ��ֵ���� compare()Ԫ�ص�λ��
void   MergeList(SqList La,SqList Lb,SqList &Lc);//����֪�ǵݼ�����˳�����й鲢�ϲ�

//����������������������
int find(ElemType e,ElemType find);//����ƥ�亯������