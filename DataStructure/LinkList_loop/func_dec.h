/*
	��������
*/

// ˫��ѭ������ ���ݽṹ��������

void CreatList_DuL(DuLinkList &L,int n,void (* InputData)(ElemType &));//�������� ������ͷ֮ǰ����
int ListLength(DuLinkList L);
	//�������ݳ���,�����ж�Ϊ��һ����ַ�ıȽϣ���ȱ��һ��ֵ����˴�1��ʼ����
	//L�����Ǿ�����ʼ��������
DuLinkList GetElemP_Dul(DuLinkList L,int i);//���ص�i�����
Status ListInsert_DuL(DuLinkList &L,int i,ElemType e);//�ڵ�i��λ��֮ǰ����Ԫ��e
Status ListDelete_Dul(DuLinkList &L,int i,ElemType &e);//ɾ��L������ͷ���ĵ�i ��Ԫ��
Status DestroyList_Dul(DuLinkList &L);//��������
Status Append(DuLinkList &La,DuLinkList &Lb);//������Lb���ӵ�La֮��

//������������
void input(ElemType &e);//��������