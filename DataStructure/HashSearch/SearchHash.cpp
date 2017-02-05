/*
	
	哈希搜索

*/

#include"head.h"

int Hash(KeyType k){
	//求哈希值
	return k%50;

}

void colloision(int &p,int &c){
	//求哈希值冲突时的下一个地址
	p++;
	if(p>49)p-=49;
}

Status SearchHash(HashTable H,KeyType K,int &p,int &c){
	//在开放定址哈希表H中查找关键码为K的元素，若成功，以p指示待查数据在表中位置，并返回SUCCESS
	//否则，p指示插入位置，返回UNSUCCESS，c用来计数冲突次数，其初始值为零，供建表时插入参考
	p=Hash(K);
	while(H.elem[p].key!=NULLKEY && !EQ(K,H.elem[p].key) )
		colloision(p,++c);

	if(EQ(K,H.elem[p].key))return SUCCESS;//查找成功p返回带查数据元素位置
	else return UNSUCCESS;//不成功，返回插入位置 H.elem[p].key==NULLKEY
}

Status InsertHash(HashTable &H,ElemType e){
	//若查找不成功时插入数据元素e到开放地址哈希表H中，并返回OK；若冲突次数过大，则重建hash表
	int c=0,p=0;
	if(SearchHash(H,e.key,p,c))return DUPLICATE;
//	else if(c<25){
		H.elem[p]=e;
		++H.count;
		return OK;
//	}else return UNSUCCESS;
}