/*
	ƥ���㷨
*/

#include "head.h"

//����T��S�ַ����е�pos���ַ����λ�ã������ڷ���0

int Index_Classic(SString S,SString T,int pos){
	//BF�㷨
	int i=pos,j=1;
	while(i <= S[0] && j <= T[0]){
		if(S[i] == T[j]){
			++i;
			++j;
		}else{
			i = i-j+2;
			j=1;
		}
	}
	if(j > T[0])return i-T[0];
	else return 0;
}

int Index_KMP(SString S,SString T,int pos,int next[]){
	//KMP�㷨
	int i=pos,j=1;
	while(i <= S[0] && j <= T[0]){
		if(j == 0 || S[i] == T[j]){
			++i;
			++j;
		}else{
			j=next[j];
		}
	}
	if(j > T[0])return i-T[0];
	else return 0;	
}