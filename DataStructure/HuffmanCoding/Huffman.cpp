/*
	赫夫曼树
*/

#include"head.h"

void Select(HuffmanTree HT,int n, int &s1, int &s2){
	//在 HT[1...n]选择 parent 为 0 且 weight 最小的两个节点,分别赋给 s1,s2 
	//s1 最小，s2 次小
	int min=0,mun=0;
	HT[0].weight = 30000;
	for(int i=1;i<=n;i++){
		if(HT[i].parent==0){
			if(HT[i].weight<HT[min].weight) {
				mun = min; min=i;
			} else if(HT[i].weight<HT[mun].weight)
				mun=i; 
		} 
	}
	s1=min;
	s2=mun;
} 

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
	//w 存放n个字符的权值（均>0）,构造赫夫曼HT，并求出n个字符的赫夫曼编码HC
	if(n<=1)return;
	int m=2*n-1;
	int i;
	HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for (i=1; i<=n; i++){ //初始化
		HT[i].weight=w[i-1];
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for (i=n+1; i<=m; i++){ //初始化
		HT[i].weight=0;
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
		
	for(i=n+1;i<=m;++i){
		//在HT[1..i-1]选择parent为0且weight最小的两个节点，其序号分别为s1和s2
		int s1=0,s2=0,j;
		Select(HT, i-1, s1, s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	//从叶子到根逆向求每个字符的赫夫曼编码
	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));//分配n个字符编码的头指针向量
	char * cd = (char *)malloc(n*sizeof(char));//分配编码的工作空间
	cd[n-1]='\0'; //编码结束符
	int start;
	unsigned int c,f;
	for(i=1;i<=n;++i){//逐个字符求赫夫曼编码
		start = n-1;
		for(c=(unsigned int)i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)//从叶子到根的逆向操作
			if(HT[f].lchild==c)cd[--start]='0';
			else cd[--start]='1';
		HC[i] = (char *)malloc((n-start)*sizeof(char));//为第一个字符编码分配空间
		strcpy(HC[i],&cd[start]);//从cd复制编码串到HC
	}
	free(cd);
}//HuffmanCoding


void HuffmanCoding2(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
	//w 存放n个字符的权值（均>0）,构造赫夫曼HT，并求出n个字符的赫夫曼编码HC
	//函数2 无栈非递归
	if(n<=1)return;
	int m=2*n-1;
	int i;
	HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for (i=1; i<=n; i++){ //初始化
		HT[i].weight=w[i-1];
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for (i=n+1; i<=m; i++){ //初始化
		HT[i].weight=0;
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
		
	for(i=n+1;i<=m;++i){
		//在HT[1..i-1]选择parent为0且weight最小的两个节点，其序号分别为s1和s2
		int s1=0,s2=0,j;
		Select(HT, i-1, s1, s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	//从叶子到根逆向求每个字符的赫夫曼编码
	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));//分配n个字符编码的头指针向量
	char * cd = (char *)malloc(n*sizeof(char));//分配编码的工作空间
	int p=m,cdlen=0;
	for(i=1;i<=m;++i)HT[i].weight=0;//遍历赫夫曼树时用作结点状态标志
	while(p){
		if(HT[p].weight==0){
			HT[p].weight=1;
			if(HT[p].lchild!=0){
				p=HT[p].lchild;
				cd[cdlen++]='0';
			}else if(HT[p].rchild==0){//登记叶子结点的字符的编码
				HC[p]=(char *)malloc((cdlen+1)*sizeof(char));
				cd[cdlen]='\0';
				strcpy(HC[p],cd);//复制串
			}
		}else if(HT[p].weight==1){
			HT[p].weight=2;
			if(HT[p].rchild!=0){
				p=HT[p].rchild;
				cd[cdlen++]='1';
			}
		}else{
			HT[p].weight=0;
			p=HT[p].parent;
			--cdlen;
		}

	}//while

}//HuffmanCoding

