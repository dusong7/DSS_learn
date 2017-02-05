/*
	��������
*/

//�������
Status InitList(LinkList &L);//����յ���������
LinkList GetHead(LinkList L);//����ͷ���
Status SetCurElem(LinkList &L,ElemType e);//����L��������ֵ
Status LocateElem(LinkList L,ElemType e,LinkList &q,int (* compare)(ElemType,ElemType));
	//LΪ����,eΪ�Ƚ�����,qΪ���ص�λ��,compareΪ�ȽϺ���,��������ҵ���֮ƥ��ĵ�һ��Ԫ��,p���ص�һ������compare����0��λ��

Status MakeNode(LinkList &p,ElemType e);//�����µĿռ�
Status InsFirst(LinkList &h,LinkList &p);//��p���뵽h֮��
LinkList NextPos(LinkList L,LinkList p);//����L������p����һ��
ElemType GetCurElem(LinkList p);//��������Ԫ��
Status DelFirst(LinkList &L,LinkList &q);//ɾ��L�е�q���
Status FreeNode(LinkList &p);//�ͷ�p�Ŀռ�
Status ListEmpty(LinkList L);//�����Ƿ�Ϊ��
Status Append(LinkList &La,LinkList s);//����s��La֮��,s��ͷ���

//���в���
Status InitQueue(LinkQueue &Q);//��ʼ��
Status DestroyQueue(LinkQueue &Q);//�����ж�
Status EnQueue(LinkQueue &Q,QElemType e);//����Ԫ��
Status DeQueue(LinkQueue &Q,QElemType &e);//ɾ��Ԫ��
int QueueLength(LinkQueue q);//���г���
Status QueueEmpty(LinkQueue q);//����Ϊ��
Status GetHead(LinkQueue Q,QElemType &e);//���ض���ͷ

//�¼�ģ��
Status OrderInsert(EvenList &ev,Event en,int (* cmp)(Event a,Event b));//��������¼�
int cmp(Event a,Event b);//�¼�����ȽϺ���
void OpenForDay(int &TotalTime,int &CustomerNum,Event &en,EvenList &ev,LinkQueue *q);//��ʼ��
int Minimum(LinkQueue *q);//������С�ж�ID
void CustomerArrived(int CloseTime,int &CustomerNum,Event &en,EvenList &ev,LinkQueue *q);//�������¼� en.NType=0
void CustomerDeparture(Event &en,EvenList &ev,LinkQueue *q,QElemType &customer,int &TotalTime);//�����뿪�¼�
void Bank_simulation(int CloseTime);//����ҵ��ģ�⣬ͳ��һ���ڿͻ������еĶ���ʱ��

//����
void Random(int &durtime,int &intertime);//���������