/*
	主函数
*/

#include "head.h"

int main(void){
	FILE *f,*g;
	char         * buf=NULL; //书目录缓存
	
	if((f = fopen("BookInfo.txt","r")) && (g = fopen("BookIdx.txt","w"))){
		IdxListType idxlist;
		InitIdxList(idxlist);//初始化
		ElemType BookNo;

		if(!(buf=(char *)malloc(MaxLineLen*sizeof(char))))exit(OVERFLOW);

		while(!feof(f)){
			GetLine(f,buf);
			//printf("%s",buf);
			ExtractKeyWord(BookNo,buf);
			InsIdxList(idxlist,BookNo,buf);
		}

		PutText(g,idxlist);
		fclose(f);
		fclose(g);
	}else{
		printf("File open err!\n");
	}
	printf("\nResult End!\n");
	system("pause");
	return 0;
}