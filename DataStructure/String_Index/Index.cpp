/*
	匹配算法
*/

#include "head.h"

//返回T在S字符串中第pos个字符后的位置，不存在返回0

int Index_Classic(SString S,SString T,int pos){
	//BF算法
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
	//KMP算法
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