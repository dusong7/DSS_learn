/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	int i=0;
	SString T1,T2;
	char s[225];
	int *next;
	printf("Input String T1:");
	scanf("%s",s);
	InitString(T1,s);
	printf("Input String T2:");
	scanf("%s",s);
	InitString(T2,s);
	next=(int *)calloc(T2[0]+1,sizeof(int));
	printf("The classic result is:%d\n\n",Index_Classic(T1,T2,1));

	printf("The next result is:");
	get_next(T2,next);
	for(i=1;i<=T2[0];i++)printf("%d ",next[i]);
	printf("\n");

	printf("The KMP [1] result is:%d\n\n",Index_KMP(T1,T2,1,next));

	printf("The nextval result is:");
	get_nextval(T2,next);
	for(i=1;i<=T2[0];i++)printf("%d ",next[i]);
	printf("\n");
	printf("The KMP [2] result is:%d\n\n",Index_KMP(T1,T2,1,next));

	printf("\nResult End!\n");
	system("pause");
	return 0;
}