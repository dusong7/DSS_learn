/*
	顺序串操作
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