/*
	��������
*/

//���ݲ�����������
void   CreatList(LinkList &L,int n,void (* InputData)(ElemType &));//�������� ������ͷ֮����� ��ĩβ����
Status GetElem(LinkList L,int i,ElemType &e);//��ȡ�� i ��Ԫ��
Status ListInsert(LinkList &L,int i,ElemType e);//�ڵ� i ��Ԫ��֮ǰ����e
Status ListDelete(LinkList &L,int i,ElemType &e);//ɾ���ڵ��еĵ�i ��Ԫ�أ��������� e��
void   MerageList(LinkList &La,LinkList &Lb,LinkList &Lc,int (* compare)(ElemType,ElemType));//�ϲ�����a b ��c compareΪ�ȽϺ���

//��������
void Input(ElemType &e);//���뺯��
int Compare(ElemType e1,ElemType e2);//�ȽϺ���