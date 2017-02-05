/*
	数据结构类型定义
*/

typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode, *HuffmanTree;//动态分配数组存储赫夫曼树

typedef char * *HuffmanCode;//动态分配数组存储赫夫曼编码表