/*
	��������ݲ���

int GListDepth(GList L);//����ͷβ����洢�ṹ�����������
Status CopyGList(GList &T,GList L);//��������洢�ṹ���й�����Ƶõ������T
Status sever(SString &str,SString &hstr);//���ǿմ�str�ָ��������:hsubΪ��һ��','֮ǰ���Ӵ���strΪstr֮��Ĵ�
Status CreateGList(GList &L,SString S);//����ͷβ����洢�ṹ���ɹ�������д��ʽS���������
Status InitGList(GList &L);//��ʼ�������
*/

#include"head.h"

Status InitGList(GList &L){
	//��ʼ�������
	if(!(L=(GList)malloc(sizeof(GLNode))))exit(OVERFLOW);
	L->tag=ATOM;
	return OK;
}
int GListDepth(GList L){
	//����ͷβ����洢�ṹ�����������
	if(!L)return 1;//�ձ����Ϊ1
	if(L->tag==ATOM)return 0;//ԭ�����Ϊ0
	int max,dep;
	GList pp;
	for(max=0;pp=L;pp=pp->ptr.tp){
		dep = GListDepth(pp->ptr.hp);
		if(dep>max)max=dep;
	}
	return max+1;
}

Status CopyGList(GList &T,GList L){
	//��������洢�ṹ���й�����Ƶõ������T
	if(!L)T=NULL;
	else{
		if(!(T=(GList)malloc(sizeof(GLNode))))exit(OVERFLOW);//��������
		T->tag=L->tag;
		if(L->tag==ATOM)T->atom=L->atom;//���Ƶ�ԭ��
		else{
			CopyGList(T->ptr.hp,L->ptr.hp);//���ƹ����L->ptr.hp��һ������T->ptr.hp
			CopyGList(T->ptr.tp,L->ptr.tp);//���ƹ����L->ptr.tp��һ������T->ptr.tp
		}
	}
	return OK;
}

Status CreateGList(GList &L,SString S){
	//����ͷβ����洢�ṹ���ɹ�������д��ʽS���������
	SString emp;
	InitString(emp,"()");
	if(StrCompare(S,emp))L=NULL;
	else{
		if(!(L=(GList)malloc(sizeof(GLNode))))exit(OVERFLOW);//�������
		if(StrLength(S)==1){//������ԭ�ӽ��
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
				sever(sub,hsub);//��sub�з����ͷ��hsub
				CreateGList(p->ptr.hp,hsub);
				q=p;
				if(!StrEmpty(sub)){//��β��Ϊ��
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
	//���ǿմ�str�ָ��������:hsubΪ��һ��','֮ǰ���Ӵ���strΪstr֮��Ĵ�
	int n;
	SString ch;
	n=StrLength(str);
	int i=0,k=0;//k����δƥ��Ե���������
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