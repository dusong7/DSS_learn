/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	HuffmanTree HT;
	HuffmanCode HC;
	
	int n,i;
	printf("input num:");
	scanf("%d",&n);
	int *w=(int *)malloc(n*sizeof(int));
	for(i=1;i<=n;i++){
		printf("%d:",i);
		scanf("%d",w+i-1);
	}
	HuffmanCoding2(HT,HC,w,n);
	printf("\n");
	for(i=1;i<=n;i++)
		printf("%d:%s\n",i,HC[i]);
	
	printf("\nResult End!\n");
	system("pause");
	return 0;
}