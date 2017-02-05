/*
	顺序串操作

//串数据操作声明
void InitString(SString &S,char *str);//初始化
Status Concat(SString &T,SString S1,SString S2);//链接
Status SubString(SString &Sub,SString S,int pos,int len);//求子串pos 为起始位置,len 为长度
int StrLength(SString S);//计算串的长度
Status StrCopy(SString &T,SString M);//复制串
Status ClearString(SString &T);//清空串
int StrCompare(SString S,SString T);//比较S与 T的大小，如果S>T 返回 >0 相等为 0
Status StrEmpty(SString s);//判断是否为空串
*/

#include "head.h"

void  InitString(SString &S,char *str){
	int i=0;char f='1';
	while(f!='\0'){
		f=str[i++];
		S[0]=i;
		S[i]=f;
		if(i>MAXSTRLEN)break;
	}
	S[MAXSTRLEN]='\0';
	--S[0];
}

Status Concat(SString &T,SString S1,SString S2){
	int i=0,j=0,l;
	int uncut;
	if(S1[0]+S2[0]<=MAXSTRLEN){//无需截断字符串
		for(i=1;i<=S1[0];i++)T[i]=S1[i];
		j=i-1;
		for(i=1;i<=S2[0];i++)T[j+i]=S2[i];
		T[0]=S1[0]+S2[0];
		uncut=TRUE;
	}else if(S1[0]<MAXSTRLEN){//截断第二条
		for(i=1;i<=S1[0];i++)T[i]=S1[i];
		l=MAXSTRLEN-S1[0];
		j=i-1;
		for(i=1;i<=l;i++)T[j+i]=S2[i];
		T[0]=MAXSTRLEN;
		uncut=FALSE;
	}else{
		for(i=1;i<=MAXSTRLEN;i++)T[i]=S1[i];
		T[0]=MAXSTRLEN;
		uncut=FALSE;
	}
	T[T[0]+1]='\0';
	return uncut;
}

Status SubString(SString &Sub,SString S,int pos,int len){
	//求子串pos 为起始位置,len 为长度
	if(pos<1 || pos>S[0] || len<0 || len>S[0]-pos+1)return ERROR;
	for(int i=1;i<pos+len-1;i++)Sub[i]=S[pos+i-1];
	Sub[0]=len;
	Sub[len+1]='\0';
	return OK;
}

int StrLength(SString S){
	//计算串的长度
	return S[0];
}

Status StrCopy(SString &T,SString M){
	//复制串
	T[0]=M[0];
	for(int i=1;i<=M[0];i++)T[i]=M[i];
	return OK;
}

Status ClearString(SString &T){
	//清空串
	T[0]=0;
	return OK;
}

int StrCompare(SString S,SString T){
	//比较S与 T的大小，如果S>T 返回 >0 相等为 0
	for(int i=1;i<=S[0] && i<=T[0];++i)
		if(S[i]!=T[i])return S[i]-T[i];
	return S[0]-T[0];
}

Status StrEmpty(SString s){
	//判断是否为空串
	if(s[0]==0)return ERROR;
	else return OK;
}