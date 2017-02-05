/*
	书籍基本操作

*/

#include"head.h"

Status InitIdxList(IdxListType &idxlist){
	//初始化操作
	IdxTermType term;
	InitString(term.Key);
	idxlist.item[0]=term;
	idxlist.last=0;
	return OK;
}

void GetLine(FILE *f,char *buf){
	//从文件中获取一行数据存到buf
	fgets(buf,MaxLineLen,f);
}

void ExtractKeyWord(ElemType &bno,char *buf){
	//从buf中提取书号及关键字到bno中
	int i=0,j=0,num=0;

	while(in_array(buf[i],"1234567890"))++i;
	for(--i; i >= 0 ; --i,++j ){
		num+=(buf[i]-48)*(int)pow((double)10,j);
	}
	bno=num;
}

Status InsIdxList(IdxListType &idxlist,ElemType bno,char *buf){
	//将书号为bno的书名关键字存储到idxlist中
	HString wd;
	WordListType wdlist;
	GetWordList(wdlist,buf);
	int i,j,b;
	for(i=0;i<wdlist.last;i++){
		GetWord(i,wd,wdlist);
		j=Locate(idxlist,wd,b);
		//printf("%d\n",j);
		if(!b)InsertNewKey(idxlist,j,wd);
		if(!(InsertBook(idxlist,j,bno)))return OVERFLOW;
	}
	FreeWordList(wdlist);
	return OK;
}
Status InsertBook(IdxListType idxlist,int i,ElemType bno){
	//插入新数据
	LinkList p;
	if(!MakeNode(p,bno))return ERROR;
	Append(idxlist.item[i].BnoList,p);
	return OK;
}
void InsertNewKey(IdxListType &idxlist,int i,HString wd){
	//插入新的关键字
	int j;
	for(j=idxlist.last-1;j>=i;--j)
		idxlist.item[j+1]=idxlist.item[j];
	StrCopy(idxlist.item[i].Key,wd);
	InitList(idxlist.item[i].BnoList);
	++idxlist.last;
}

int Locate(IdxListType &idxlist,HString wd,Boolean &b){
	//查看是否存在相同的索引，b为返回值
	//存在返回存在位置，否则返回插入位置
	int i,m;
	if(idxlist.last==0){
		b=FALSE;
		return 0;
	}
	for(i=idxlist.last-1;(m=StrCompare(idxlist.item[i].Key,wd))>0;--i);
	if(m==0){
		b=TRUE;
		return i;
	}else{
		b=FALSE;
		return i+1;
	}
}

int GetKeyNum(char *buf){
	//获取关键字数量
	int i=0,j=0;
	while(buf[i]!='\0' && buf[i]!='\n' && i<=MaxLineLen){
		if(buf[i]==' ')j++;
		i++;
	}
	if(j>0)j++;
	return j;
}

Status GetWordList(WordListType &wdlist,char *buf){
	//存储缓存中的关键字
	wdlist.last=GetKeyNum(buf);
	wdlist.item=(char **)calloc(wdlist.last,sizeof(char *));
	int i,j=0,k,l;
	char *s;
	while(buf[j++]!='\t' && j<=MaxLineLen);

	for(i=0;i<wdlist.last;i++){
		if(buf[j]=='\0' || buf[j]=='\n')return ERROR;
		k=j;
		while(buf[k]!=' ' && buf[k]!='\n')k++;
		s=(char *)calloc(k-j+1,sizeof(char));
		wdlist.item[i]=s;
		for(l=0;l<k-j;l++)s[l]=buf[j+l];
		j=k+1;
	}
	//for(i=0;i<wdlist.last;i++)
	//	printf("%s\n",wdlist.item[i]);
	return OK;
}

Status FreeWordList(WordListType &wdlist){
	//释放关键字空间
	for(int i=wdlist.last;i<=0;--i){
		free(wdlist.item[i]);
	}
	free(wdlist.item);
	return OK;
}

Status GetWord(int i,HString &wd,WordListType wdlist){
	//用wd返回wdlist中的第i个关键字
	wd.ch=wdlist.item[i];
	wd.length=0;
	while(wd.ch[wd.length++]!='\0');
	if(wd.length>0)wd.length--;
	//printf("%d\n",wd.length);
	return OK;
}

Status PutText(FILE *g,IdxListType idxlist){
	//输出数据
	int i;
	LinkList p;
	for(i=0;i<idxlist.last;i++){
		printf("key = %s\n",idxlist.item[i].Key.ch);
		fprintf(g,"%s\t",idxlist.item[i].Key.ch);

		printf("Book id :");
		p=idxlist.item[i].BnoList->next;
		while(p!=NULL){
			printf("%d ",p->data);
			fprintf(g,"%d ",p->data);
			p=p->next;
		}
		printf("\n");
		fprintf(g,"\n");
	}
	return OK;
}