/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	Space pav,p;
	InitSpace(pav,1000);
	PrintSpaceInfo(pav);

	int newsize;
	
	while(1){
		newsize=rand()%100+1;
		p=AllocBoundTag(pav,newsize,10);
		printf("\nnew address -> %d ,size -> %d\n",p,newsize);
		if(!p)break;
		PrintSpaceInfo(pav);
		if(newsize%2){
			FreeSpace(p,pav);
			printf("\nFree Space %d ,size:%d\n",p,p->size);
		}
	}

	printf("\nResult End!\n");
	system("pause");
	return 0;
}