/*
	
	��ϣ����

*/

#include"head.h"

int Hash(KeyType k){
	//���ϣֵ
	return k%50;

}

void colloision(int &p,int &c){
	//���ϣֵ��ͻʱ����һ����ַ
	p++;
	if(p>49)p-=49;
}

Status SearchHash(HashTable H,KeyType K,int &p,int &c){
	//�ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK��Ԫ�أ����ɹ�����pָʾ���������ڱ���λ�ã�������SUCCESS
	//����pָʾ����λ�ã�����UNSUCCESS��c����������ͻ���������ʼֵΪ�㣬������ʱ����ο�
	p=Hash(K);
	while(H.elem[p].key!=NULLKEY && !EQ(K,H.elem[p].key) )
		colloision(p,++c);

	if(EQ(K,H.elem[p].key))return SUCCESS;//���ҳɹ�p���ش�������Ԫ��λ��
	else return UNSUCCESS;//���ɹ������ز���λ�� H.elem[p].key==NULLKEY
}

Status InsertHash(HashTable &H,ElemType e){
	//�����Ҳ��ɹ�ʱ��������Ԫ��e�����ŵ�ַ��ϣ��H�У�������OK������ͻ�����������ؽ�hash��
	int c=0,p=0;
	if(SearchHash(H,e.key,p,c))return DUPLICATE;
//	else if(c<25){
		H.elem[p]=e;
		++H.count;
		return OK;
//	}else return UNSUCCESS;
}