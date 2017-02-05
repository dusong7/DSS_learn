/*
	数据结构操作源码
*/

#include "head.h"

void printSMatrix(TSMatrix T){
	//以数组形式输出稀疏矩阵
	int flag=0;
	for(int i=1;i<=T.mu;i++){
		for(int j=1;j<=T.nu;j++){
			flag=0;
			for(int l=1;l<=T.tu;l++){
				if(T.data[l].i==i && T.data[l].j==j){
					printf("%2d ",T.data[l].e);
					flag=1;
				}
			}
			if(flag==0)printf("%2d ",0);
		}
		printf("\n");
	}
}
void printMultSMatrix(RLSMatrix T){
	//以数组形式输出逻辑链接稀疏矩阵
	int flag=0;
	for(int i=1;i<=T.mu;i++){
		for(int j=1;j<=T.nu;j++){
			flag=0;
			for(int l=1;l<=T.tu;l++){
				if(T.data[l].i==i && T.data[l].j==j){
					printf("%2d ",T.data[l].e);
					flag=1;
				}
			}
			if(flag==0)printf("%2d ",0);
		}
		printf("\n");
	}
}