/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	FreeList list;
	WORD_b *p,**AddList;
	int size;
	InitBuddy(list);
	PrintBuddyInfo(list);
	size=rand()%100+1;
	p=ALLocBuddy(list,size);
	while(p){
		printf("\n ALLocBuddy size=%d adderrs:%d\n",size,p);
		PrintBuddyInfo(list);
		system("pause");
		size=rand()%1000+1;
		p=ALLocBuddy(list,size);
	}
	printf("\nResult End!\n");
	system("pause");
	return 0;
}