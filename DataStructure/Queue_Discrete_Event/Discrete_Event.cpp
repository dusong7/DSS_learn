/*
	��ɢ�¼�����
*/

#include"head.h"

Status OrderInsert(EvenList &ev,Event en,int (* cmp)(Event a,Event b)){
	EvenList p=ev,NEvent;
	NEvent=(LinkList)malloc(sizeof(LNode));
	if(!NEvent)exit(OVERFLOW);
	NEvent->data=en;
	while(p->next){
		if(cmp(p->next->data,en)>=0)break;
		p=p->next;
	}
	NEvent->next=p->next;
	p->next=NEvent;
	return OK;
}

int cmp(Event a,Event b){
	if(a.OccurTime==b.OccurTime)return 0;
	if(a.OccurTime>b.OccurTime)return 1;
	return -1;
}

void OpenForDay(int &TotalTime,int &CustomerNum,Event &en,EvenList &ev,LinkQueue *q){
	//��ʼ��
	TotalTime=0;CustomerNum=0;
	InitList(ev);
	en.OccurTime=0;
	en.NType=0;
	OrderInsert(ev,en,cmp);
	for(int i=1;i<=4;++i)InitQueue(q[i]);
}

int Minimum(LinkQueue *q){
	//������С�ж�ID
	int n[5],k,l,i;
	for(i=1;i<=4;i++)n[i]=QueueLength(q[i]);
	k=1;l=n[1];
	for(i=2;i<=4;i++){
		if(n[i]<l){
			k=i;
			l=n[i];
		}
	}
	return k;
}
void CustomerArrived(int CloseTime,int &CustomerNum,Event &en,EvenList &ev,LinkQueue *q){
	//�������¼� en.NType=0
	++CustomerNum;
	Event t;
	int durtime,intertime;
	Random(durtime,intertime);
	t.OccurTime=en.OccurTime+intertime;
	t.NType=0;
	if(t.OccurTime<CloseTime)//�����¼���
		OrderInsert(ev,t,cmp);
	int i=Minimum(q);
	
	QElemType t2;
	t2.ArrivaTime=en.OccurTime;
	t2.Duration=durtime;

	EnQueue(q[i],t2);
	t.OccurTime=en.OccurTime+durtime;
	t.NType=i;
	if(QueueLength(q[i])==1)//�趨�жӵ��뿪�¼�
		OrderInsert(ev,t,cmp);
}
void CustomerDeparture(Event &en,EvenList &ev,LinkQueue *q,QElemType &customer,int &TotalTime){
	//�����뿪�¼�
	int i=en.NType;
	DeQueue(q[i],customer);//ɾ����ͷ�Ŀͻ�
	TotalTime+=en.OccurTime-customer.ArrivaTime;//�ۼƿͻ�����ʱ��
	if(!QueueEmpty(q[i])){//�趨��i�жӵ�һ���뿪�¼������¼���
		GetHead(q[i],customer);
		
		Event t;
		t.OccurTime=en.OccurTime+customer.ArrivaTime;
		t.NType=i;

		OrderInsert(ev,t,cmp);
	}
}

void Bank_simulation(int CloseTime){
	//����ҵ��ģ�⣬ͳ��һ���ڿͻ������еĶ���ʱ��
	//ȫ�ֱ���
	static Event en;//�¼���
	static EvenList ev;//�¼�
	static LinkQueue q[5];//4���ͻ��ж�
	static QElemType customer;//�ͻ���¼
	static int TotalTime,CustomerNum;//�ۼƶ���ʱ�䣬�ͻ���
	//��������
	EvenList p,e;
	OpenForDay(TotalTime,CustomerNum,en,ev,q);
	while(!ListEmpty(ev)){
		e=GetHead(ev);
		DelFirst(e,p);
		
		en=GetCurElem(p);

		if(en.NType==0)
			CustomerArrived(CloseTime,CustomerNum,en,ev,q);
		else CustomerDeparture(en,ev,q,customer,TotalTime);

		if(TotalTime>CloseTime)break;
	}
	printf("%0.2f\n",(float)TotalTime/CustomerNum);
}