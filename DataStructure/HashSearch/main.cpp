/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	int i,j,p,c;
	HashTable H;
	ElemType e;
	H.elem=(ElemType *)malloc(50*sizeof(ElemType));
	for(i=0;i<50;i++){
		H.elem[i].key=NULLKEY;
	}
	for(i=0;i<50;i++){
		e.key=rand()%500;
		if(i==41){
			e.key=e.key;
		}
		j=InsertHash(H,e);
		if(j==OK)printf("Insert %3d V , ",e.key);
		else printf("Insert %3d X , ",e.key);
		if(!((i+1)%4))printf("\n");
	}
	printf("\n\n");
	for(i=0;i<50;i++){
		printf("%3d ",H.elem[i]);
	}
	printf("\n\n");
	for(i=0;i<50;i++){
		j=rand()%500;
		if(SearchHash(H,j,p,c))printf("Search %3d V , ",j);
		else printf("Search %3d X , ",j);
		if(!((i+1)%4))printf("\n");
	}
	printf("\nResult End!\n");
	system("pause");
	return 0;
}
