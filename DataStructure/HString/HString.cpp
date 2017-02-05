/*
	�� �ѷ���

//�ѷ������ݶ���
typedef struct{
	char *ch;//�ǿ�ΪNULL������Ϊ����Ŀռ�
	int length;//������
}HString;	
	
//�� �ѷ�������
void InitString(HString &H);//��ʼ��
Status StrAssigne(HString &T,char *chars);//����һ�����ݵ�ֵΪchars
int StrLength(HString S);//���㳤��
int StrCompare(HString S,HString T);//�ַ������ֵ�˳��Ƚ�
Status ClearString(HString &S);//��մ�
Status Concat(HString &T,HString S1,HString S2);//���Ӵ�
Status SubString(HString &Sub,HString S,int pos,int len);//���Ӵ�
*/

#include "head.h"

void InitString(HString &H){
	H.ch=NULL;
	H.length=0;
}

Status StrAssigne(HString &T,char *chars){
	//����һ�����ݵ�ֵΪchars
	if(T.ch)free(T.ch);//�ͷ�ԭ������
	int i;char *c;
	for(i=0,c=chars;*c;++i,++c);//��chars�ĳ���
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
	//�Ƚ�S�� T�Ĵ�С�����S>T ���� >0 ���Ϊ 0
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