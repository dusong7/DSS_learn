/*
	离散事件函数
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
	//初始化
	TotalTime=0;CustomerNum=0;
	InitList(ev);
	en.OccurTime=0;
	en.NType=0;
	OrderInsert(ev,en,cmp);
	for(int i=1;i<=4;++i)InitQueue(q[i]);
}

int Minimum(LinkQueue *q){
	//返回最小列队ID
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
	//处理到达事件 en.NType=0
	++CustomerNum;
	Event t;
	int durtime,intertime;
	Random(durtime,intertime);
	t.OccurTime=en.OccurTime+intertime;
	t.NType=0;
	if(t.OccurTime<CloseTime)//插入事件表
		OrderInsert(ev,t,cmp);
	int i=Minimum(q);
	
	QElemType t2;
	t2.ArrivaTime=en.OccurTime;
	t2.Duration=durtime;

	EnQueue(q[i],t2);
	t.OccurTime=en.OccurTime+durtime;
	t.NType=i;
	if(QueueLength(q[i])==1)//设定列队的离开事件
		OrderInsert(ev,t,cmp);
}
void CustomerDeparture(Event &en,EvenList &ev,LinkQueue *q,QElemType &customer,int &TotalTime){
	//处理离开事件
	int i=en.NType;
	DeQueue(q[i],customer);//删除排头的客户
	TotalTime+=en.OccurTime-customer.ArrivaTime;//累计客户逗留时间
	if(!QueueEmpty(q[i])){//设定第i列队的一个离开事件插入事件表
		GetHead(q[i],customer);
		
		Event t;
		t.OccurTime=en.OccurTime+customer.ArrivaTime;
		t.NType=i;

		OrderInsert(ev,t,cmp);
	}
}

void Bank_simulation(int CloseTime){
	//银行业务模拟，统计一天内客户在银行的逗留时间
	//全局变量
	static Event en;//事件表
	static EvenList ev;//事件
	static LinkQueue q[5];//4个客户列队
	static QElemType customer;//客户记录
	static int TotalTime,CustomerNum;//累计逗留时间，客户数
	//变量结束
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