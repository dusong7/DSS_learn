/*

	表插入排序

	//未完成的排序

*/

#include"head.h"

void Arrange(SLinkListType &SL){
	//根据静态表中各个节点的指针值调整记录位置，使得SL中记录按关键字非递减有序排列
	int p,i,q;
	SLNode tmp;
	p=SL.r[0].next;//p指向记录的第一个位置
	for(i=1;i<SL.length;++i){
		while(p<i)p=SL.r[p].next;
		q=SL.r[p].next;
		if(p!=i){
			//交换值
			tmp=SL.r[p];
			SL.r[p]=SL.r[i];
			SL.r[i]=tmp;

			SL.r[i].next=p;//指向被移走的值，使得让while循环找到
		}
		p=q;//p指示尚未调整表尾，为找到第i+1个记录做准备
	}
}

void CountNextValue(SLinkListType &SL){
	printf("ERROR");
}