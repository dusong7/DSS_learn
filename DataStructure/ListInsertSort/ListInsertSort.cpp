/*

	���������

	//δ��ɵ�����

*/

#include"head.h"

void Arrange(SLinkListType &SL){
	//���ݾ�̬���и����ڵ��ָ��ֵ������¼λ�ã�ʹ��SL�м�¼���ؼ��ַǵݼ���������
	int p,i,q;
	SLNode tmp;
	p=SL.r[0].next;//pָ���¼�ĵ�һ��λ��
	for(i=1;i<SL.length;++i){
		while(p<i)p=SL.r[p].next;
		q=SL.r[p].next;
		if(p!=i){
			//����ֵ
			tmp=SL.r[p];
			SL.r[p]=SL.r[i];
			SL.r[i]=tmp;

			SL.r[i].next=p;//ָ�����ߵ�ֵ��ʹ����whileѭ���ҵ�
		}
		p=q;//pָʾ��δ������β��Ϊ�ҵ���i+1����¼��׼��
	}
}

void CountNextValue(SLinkListType &SL){
	printf("ERROR");
}