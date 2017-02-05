/*
	函数声明
*/

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n);
	//w 存放n个字符的权值（均>0）,构造赫夫曼HT，并求出n个字符的赫夫曼编码HC
void HuffmanCoding2(HuffmanTree &HT,HuffmanCode &HC,int *w,int n);//非栈无递归

void Select(HuffmanTree HT,int n, int &s1, int &s2);
	//在 HT[1...n]选择 parent 为 0 且 weight 最小的两个节点,分别赋给 s1,s2 