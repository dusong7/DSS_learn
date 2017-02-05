/*
	广义表数据操作

int GListDepth(GList L);//采用头尾链表存储结构，求广义表深度
Status CopyGList(GList &T,GList L);//采用链表存储结构，有广义表复制得到广义表T
Status sever(SString &str,SString &hstr);//将非空串str分割成两部分:hsub为第一个','之前的子串，str为str之后的串
Status CreateGList(GList &L,SString S);//采用头尾链表存储结构，由广义表的书写形式S创建广义表
Status InitGList(GList &L);//初始化广义表
*/

#include"head.h"

Status InitGList(GList &L){
	//初始化广义表
	if(!(L=(GList)malloc(sizeof(GLNode))))exit(OVERFLOW);
	L->tag=ATOM;
	return OK;
}
int GListDepth(GList L){
	//采用头尾链表存储结构，求广义表深度
	if(!L)return 1;//空表深度为1
	if(L->tag==ATOM)return 0;//原子深度为0
	int max,dep;
	GList pp;
	for(max=0;pp=L;pp=pp->ptr.tp){
		dep = GListDepth(pp->ptr.hp);
		if(dep>max)max=dep;
	}
	return max+1;
}

Status CopyGList(GList &T,GList L){
	//采用链表存储结构，有广义表复制得到广义表T
	if(!L)T=NULL;
	else{
		if(!(T=(GList)malloc(sizeof(GLNode))))exit(OVERFLOW);//建立表结点
		T->tag=L->tag;
		if(L->tag==ATOM)T->atom=L->atom;//复制单原子
		else{
			CopyGList(T->ptr.hp,L->ptr.hp);//复制广义表L->ptr.hp的一个副本T->ptr.hp
			CopyGList(T->ptr.tp,L->ptr.tp);//复制广义表L->ptr.tp的一个副本T->ptr.tp
		}
	}
	return OK;
}

Status CreateGList(GList &L,SString S){
	//采用头尾链表存储结构，由广义表的书写形式S创建广义表
	SString emp;
	InitString(emp,"()");
	if(StrCompare(S,emp))L=NULL;
	else{
		if(!(L=(GList)malloc(sizeof(GLNode))))exit(OVERFLOW);//建立结点
		if(StrLength(S)==1){//创建单原子结点
			L->tag=ATOM;
			StrCopy(L->atom.s,S);
		}else{
			GList p,q;
			L->tag=LIST;
			p=L;
			SString sub,hsub;
			sub[0]=0,hsub[0]=0;
			SubString(sub,S,2,StrLength(S)-2);
			do{
				sever(sub,hsub);//从sub中分离表头串hsub
				CreateGList(p->ptr.hp,hsub);
				q=p;
				if(!StrEmpty(sub)){//表尾不为空
					if(!(p=(GLNode *)malloc(sizeof(GLNode))))exit(OVERFLOW);
					p->tag=LIST;
					q->ptr.tp=p;
				}//if
			}while(!StrEmpty(sub));
			q->ptr.tp=NULL;
		}//else
	}//else
	return OK;
}


Status sever(SString &str,SString &hstr){
	//将非空串str分割成两部分:hsub为第一个','之前的子串，str为str之后的串
	int n;
	SString ch;
	n=StrLength(str);
	int i=0,k=0;//k记尚未匹配对的左括号数
	do{
		++i;
		SubString(ch,str,i,1);
		if(ch[1]=='(')++k;
		else if(ch[1]==')')--k;
	}while(i<n && (ch[1]!=','||k!=0));
	if(i<n){
		SubString(hstr,str,1,i-1);
		SubString(str,str,i+1,n-i);
	}else{
		StrCopy(hstr,str);
		ClearString(str);
	}
	return OK;
}