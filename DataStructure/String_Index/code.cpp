/*
���ݽṹ����Դ��
*/

#include "head.h"

void get_next(SString T, int next[]){
	//��ģʽ��T��next����ֵ����������next
	int i,j;
	i = 1; next[1] = 0; j = 0;
	while (i < T[0]){
		if(j ==0 || T[i] == T[j]){
			++i; ++j; next[i] = j;
		}else{
			j = next[j];
		}
	}
}

void get_nextval(SString T,int nextval[]){
	//��ģʽ��T��next����ֵ����������nextval��
	int i,j;
	i=1;
	j=0;
	nextval[1]=0;
	while(i<T[0]){
		if(j == 0 || T[i] == T[j]){
			++i;++j;
			if(T[i]  != T[j])nextval[i] = j;
			else nextval[i] = nextval[j];
		}else{
			j = nextval[j];
		}
	}
}