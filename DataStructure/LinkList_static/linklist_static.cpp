/*
	���Ծ�̬���� ���ݺ���
*/

#include"head.h"

int LocateElem_SL(SLinkList S,ElemType e,int (* compare)(ElemType,ElemType)){
	//�������в��ҵ�һ��ֵΪ e ��Ԫ��
	//�ҵ�����λ�ã����򷵻� 0
	//compare Ϊ�ȽϺ���
	int i=S[0].cur;
	while(i && !compare(S[i].data,e))i=S[i].cur;
	return i;
}//LocateElem_SL
void InitSpace_SL(SLinkList &space){
	//��һά�����и�����������һ����������,space[0].curΪͷָ��
	// "0" ��ʾ��
	int i;
	for(i=0;i<MAXSIZE-1;++i)
		space[i].cur=i+1;
	space[MAXSIZE-1].cur=0;
}//InitSpace_SL

int Malloc_SL(SLinkList &space){
	//����������Ϊ�գ��򷵻ط���Ľ���±꣬���򷵻�0
	int i=space[0].cur;
	if(space[0].cur)space[0].cur=space[i].cur;
	return i;
}//Malloc_SL

void Free_SL(SLinkList &space,int i){
	//���±�Ϊi�Ŀռ���Ϊ���ÿռ�
	space[i].cur=space[0].cur;
	space[0].cur=i;
}//Free_SL

void difference(SLinkList &space, int &S,void (* InputData)(ElemType &),int (* compare)(ElemType,ElemType)){
	//�������뼯��A�ͼ���B��Ԫ�أ���һά����space�н�����ʾ���ϣ�A-B��U (B-A)�ľ�̬����,SΪ��ͷָ�룬���豸�ÿռ��㹻��,space[0].curΪ��ͷָ��
	//InputDataΪ���뺯��
	int m,n,i,j,r,p,k;
	ElemType b;
	InitSpace_SL(space);
	r=S=Malloc_SL(space);
	printf("Input m and n of A and B number:");
	scanf("%d%d",&m,&n);
	printf("\nA:\n");
	for(j=1;j<=m;++j){//���뼯��A
		i=Malloc_SL(space);//������
		InputData(space[i].data);
		space[r].cur=i;//��ĩβ����
		r=i;
	}//for
	space[r].cur=0;//����βָ�����Ϊ��

	printf("\nB:\n");
	for(j=1;j<=n;++j){//���뼯��B
		InputData(b);//����Ԫ��b
		p=S;
		k=space[S].cur;//Kָ��A�еĵ�һ�����
		while(k != space[r].cur && !compare(space[k].data,b)){//�ڵ�ǰ�����в���
			p=k;
			k=space[k].cur;
		}//while
		if(k==space[r].cur){//��Ԫ�ز�����ʱ����Ԫ�ز��뵽r��ָ���֮��,��rλ�ò��ı�
			i=Malloc_SL(space);
			space[i].data=b;
			space[i].cur=space[r].cur;
			space[r].cur=i;
		}else{//if ����Ԫ�ش���ʱ������ɾ��
			space[p].cur=space[k].cur;
			Free_SL(space,k);
			if(r==k)r=p;//����rɾ������ô��Ҫ�޸�βָ��
		}//else
	}//for
}//difference
