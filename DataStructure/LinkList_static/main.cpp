/*
	������
*/

#include "head.h"

int main(void){
	SLinkList space;
	int s;
	difference(space,s,input,com);
	printf("\nThe result is:\n\n");
	while(s=space[s].cur){//��sΪ�α��ƶ������ж�����
		printf("%s => %d\n",space[s].data.name,space[s].data.age);
	}

	printf("\nResult End!\n");
	system("pause");
	return 0;
}