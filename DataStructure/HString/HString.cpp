/*
	串 堆分配

//堆分配数据定义
typedef struct{
	char *ch;//非空为NULL，否则为分配的空间
	int length;//串长度
}HString;	
	
//串 堆分配声明
void InitString(HString &H);//初始化
Status StrAssigne(HString &T,char *chars);//生成一个数据的值为chars
int StrLength(HString S);//计算长度
int StrCompare(HString S,HString T);//字符串按字典顺序比较
Status ClearString(HString &S);//清空串
Status Concat(HString &T,HString S1,HString S2);//连接串
Status SubString(HString &Sub,HString S,int pos,int len);//求子串
*/

#include "head.h"

void InitString(HString &H){
	H.ch=NULL;
	H.length=0;
}

Status StrAssigne(HString &T,char *chars){
	//生成一个数据的值为chars
	if(T.ch)free(T.ch);//释放原有数据
	int i;char *c;
	for(i=0,c=chars;*c;++i,++c);//求chars的长度
	printf("%d\n",i);
	if(!i){
		T.ch=NULL;
		T.length=0;
	}else{
		if(!(T.ch=(char *)malloc((i+1)*sizeof(char))))exit(OVERFLOW);
		int j;
		for(j=0;j<i;j++)T.ch[j]=chars[j];
		T.length=i;
		T.ch[i]='\0';
	}
	return OK;
}

int StrLength(HString S){
	return S.length;
}

int StrCompare(HString S,HString T){
	//比较S与 T的大小，如果S>T 返回 >0 相等为 0
	printf("%d,%d\n",S.length,T.length);
	for(int i=0;i<S.length && i<T.length;++i)
		if(S.ch[i]!=T.ch[i])return S.ch[i]-T.ch[i];
	return S.length-T.length;
}

Status ClearString(HString &S){
	if(S.ch){free(S.ch);S.ch=NULL;}
	S.length=0;
	return OK;
}

Status Concat(HString &T,HString S1,HString S2){
	if(T.ch)free(T.ch);
	if(!(T.ch=(char *)malloc((S1.length+S2.length+1)*sizeof(char))))exit(OVERFLOW);
	int i,j;
	for(i=0;i<S1.length;i++)T.ch[i]=S1.ch[i];
	for(j=0;j<S2.length;j++)T.ch[i+j]=S2.ch[j];
	T.ch[i+j]='\0';
	T.length=i+j;
	return OK;
}

Status SubString(HString &Sub,HString S,int pos,int len){
	if(pos<1 || pos>S.length || len<0 || len>S.length-pos+1)return ERROR;
	if(Sub.ch)free(Sub.ch);
	if(!len){
		Sub.ch=NULL;
		Sub.length=0;
	}else{
		if(!(Sub.ch=(char *)malloc((len+1)*sizeof(char))))exit(OVERFLOW);
		for(int i=0;i<len;i++)Sub.ch[i]=S.ch[pos-1+i];
		Sub.length=len;
		Sub.ch[len]='\0';
	}
	return OK;
}