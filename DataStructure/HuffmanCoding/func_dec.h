/*
	��������
*/

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n);
	//w ���n���ַ���Ȩֵ����>0��,����շ���HT�������n���ַ��ĺշ�������HC
void HuffmanCoding2(HuffmanTree &HT,HuffmanCode &HC,int *w,int n);//��ջ�޵ݹ�

void Select(HuffmanTree HT,int n, int &s1, int &s2);
	//�� HT[1...n]ѡ�� parent Ϊ 0 �� weight ��С�������ڵ�,�ֱ𸳸� s1,s2 