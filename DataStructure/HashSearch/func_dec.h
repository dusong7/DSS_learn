/*
	函数声明
*/

int Hash(KeyType k);//求哈希值
void colloision(int &p,int &c);//求哈希值冲突时的下一个地址
Status SearchHash(HashTable H,KeyType K,int &p,int &c);//在开放定址哈希表H中查找关键码为K的元素
Status InsertHash(HashTable &H,ElemType e);//若查找不成功时插入数据元素e到开放地址哈希表H中
