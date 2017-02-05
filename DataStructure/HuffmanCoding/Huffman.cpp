/*
	�շ�����
*/

#include"head.h"

void Select(HuffmanTree HT,int n, int &s1, int &s2){
	//�� HT[1...n]ѡ�� parent Ϊ 0 �� weight ��С�������ڵ�,�ֱ𸳸� s1,s2 
	//s1 ��С��s2 ��С
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
	//w ���n���ַ���Ȩֵ����>0��,����շ���HT�������n���ַ��ĺշ�������HC
	if(n<=1)return;
	int m=2*n-1;
	int i;
	HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for (i=1; i<=n; i++){ //��ʼ��
		HT[i].weight=w[i-1];
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for (i=n+1; i<=m; i++){ //��ʼ��
		HT[i].weight=0;
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
		
	for(i=n+1;i<=m;++i){
		//��HT[1..i-1]ѡ��parentΪ0��weight��С�������ڵ㣬����ŷֱ�Ϊs1��s2
		int s1=0,s2=0,j;
		Select(HT, i-1, s1, s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	//��Ҷ�ӵ���������ÿ���ַ��ĺշ�������
	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));//����n���ַ������ͷָ������
	char * cd = (char *)malloc(n*sizeof(char));//�������Ĺ����ռ�
	cd[n-1]='\0'; //���������
	int start;
	unsigned int c,f;
	for(i=1;i<=n;++i){//����ַ���շ�������
		start = n-1;
		for(c=(unsigned int)i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)//��Ҷ�ӵ������������
			if(HT[f].lchild==c)cd[--start]='0';
			else cd[--start]='1';
		HC[i] = (char *)malloc((n-start)*sizeof(char));//Ϊ��һ���ַ��������ռ�
		strcpy(HC[i],&cd[start]);//��cd���Ʊ��봮��HC
	}
	free(cd);
}//HuffmanCoding


void HuffmanCoding2(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
	//w ���n���ַ���Ȩֵ����>0��,����շ���HT�������n���ַ��ĺշ�������HC
	//����2 ��ջ�ǵݹ�
	if(n<=1)return;
	int m=2*n-1;
	int i;
	HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for (i=1; i<=n; i++){ //��ʼ��
		HT[i].weight=w[i-1];
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for (i=n+1; i<=m; i++){ //��ʼ��
		HT[i].weight=0;
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
		
	for(i=n+1;i<=m;++i){
		//��HT[1..i-1]ѡ��parentΪ0��weight��С�������ڵ㣬����ŷֱ�Ϊs1��s2
		int s1=0,s2=0,j;
		Select(HT, i-1, s1, s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	//��Ҷ�ӵ���������ÿ���ַ��ĺշ�������
	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));//����n���ַ������ͷָ������
	char * cd = (char *)malloc(n*sizeof(char));//�������Ĺ����ռ�
	int p=m,cdlen=0;
	for(i=1;i<=m;++i)HT[i].weight=0;//�����շ�����ʱ�������״̬��־
	while(p){
		if(HT[p].weight==0){
			HT[p].weight=1;
			if(HT[p].lchild!=0){
				p=HT[p].lchild;
				cd[cdlen++]='0';
			}else if(HT[p].rchild==0){//�Ǽ�Ҷ�ӽ����ַ��ı���
				HC[p]=(char *)malloc((cdlen+1)*sizeof(char));
				cd[cdlen]='\0';
				strcpy(HC[p],cd);//���ƴ�
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

