/*
	��������
*/
//�������
Status InitList(polynomail &L);//����յ���������
LinkList GetHead(LinkList L);//����ͷ���
Status SetCurElem(LinkList &L,ElemType e);//����L��������ֵ
Status LocateElem(LinkList L,ElemType e,Postion &q,int (* compare)(ElemType,ElemType));
	//LΪ����,eΪ�Ƚ�����,qΪ���ص�λ��,compareΪ�ȽϺ���,��������ҵ���֮ƥ��ĵ�һ��Ԫ��,p���ص�һ������compare����0��λ��

Status MakeNode(LinkList &p,ElemType e);//�����µĿռ�
Status InsFirst(LinkList &h,LinkList &p);//��p���뵽h֮��
LinkList NextPos(LinkList L,LinkList p);//����L������p����һ��
ElemType GetCurElem(LinkList p);//��������Ԫ��
Status DelFirst(LinkList &L,LinkList &q);//ɾ��L�е�q���
Status FreeNode(LinkList &p);//�ͷ�p�Ŀռ�
Status ListEmpty(LinkList L);//�����Ƿ�Ϊ��
Status Append(LinkList &La,LinkList s);//����s��La֮��,s��ͷ���

//����ʽ����
void CreatPolyn(polynomail &P,int n,void (* Input)(ElemType &));//��������
void PrintPolyn(polynomail P);//��ӡ����
void AddPoly(polynomail &Pa,polynomail &Pb,int (* compare)(ElemType,ElemType));//����ʽ�ӷ�
void SubPoly(polynomail &Pa,polynomail &Pb,int (* compare)(ElemType,ElemType));//����ʽ����

//���ݱȽϼ�����
int com(ElemType e1,ElemType e2);//��������
void InputData(ElemType &e);//��������