/*

基数排序

结果一塌糊涂，唉，失败

*/
#include"head.h"

SLList * RadixSort::RandData(){
	SLList *SL=new SLList();
	int i,j;
	SL->keynum=2;//(rand()%7+2);
	SL->recnum=MAX_SPACE-1;
	for(i=1;i<=SL->recnum;++i){
		for(j=0;j<SL->keynum;++j){
			SL->r[i].keys[j]=rand()%10;
		}
	}
	return SL;
}
void RadixSort::SetValue(SLList *data){
	if(data==NULL)L=RandData();
	else L=data;
}
void RadixSort::Output(){
	int i,j;
	for(i=1;i<=L->recnum;++i){
		for(j=0;j<L->keynum;++j){
			cout << L->r[i].keys[j] ;
		}
		cout << " ";
	}
	cout << endl;
}
int RadixSort::ord(KeysType key){
	//将字符映射的基数上
	return key;
}
int RadixSort::succ(int i){
	return i+1;
}
void RadixSort::OutputNext(){
	for(int i=0; i<L->recnum; ++i)
		cout << L->r[i].next << " ";
	cout << endl;

	for(int i=L->r[0].next;i>0;i=L->r[i].next)
	{
		for(int j=0;j<L->keynum;++j)
			cout << L->r[i].keys[j];
		cout << " ";
	}
	cout << endl;
}
void RadixSort::OutputResult(){
	for(int i=L->r[0].next;i>0;i=L->r[i].next)
	{
		for(int j=0;j<L->keynum;++j)
			cout << L->r[i].keys[j];
		cout << " ";
	}
	cout << endl;
}
void RadixSort::Distribute(int i,ArrType &f,ArrType &e){
	int j,p;
	for(j=0; j<RADIX; ++j) f[j]=0;
	for(p=L->r[0].next; p; p=L->r[p].next){
		j = ord(L->r[p].keys[i]);
		if( !f[j] ) f[j] = p;
		else L->r[e[j]].next = p;
		e[j] = p;
	}
}

void RadixSort::Collect(int i,ArrType f,ArrType e){
	int j,t;
	for( j = 0; !f[j]; j = succ(j));////求后继
	L->r[0].next = f[j];
	t = e[j];
	while(j<RADIX-1){
		for(j = succ(j); j<RADIX-1 && !f[j]; j=succ(j));//找到下一个非空子表
		if( f[j] ){
			L->r[t].next = f[j];
			t = e[j];
		}
	}
	L->r[t].next = 0;
}
void RadixSort::Sort(){
	int i;
	ArrType f, e;
	for(i=0; i<L->recnum; ++i) L->r[i].next=i+1;
	L->r[L->recnum].next=0;
	for(i=0;i<L->keynum;++i){
		Distribute(i,f,e);
		Collect(i,f,e);
		OutputNext();
	}
}