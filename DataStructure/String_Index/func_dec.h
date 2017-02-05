/*
	函数声明
*/
void InitString(SString &S,char *str);//初始化
Status Concat(SString &T,SString S1,SString S2);//链接
Status SubString(SString &Sub,SString S,int pos,int len);//求子串pos 为起始位置,len 为长度

int Index_Classic(SString S,SString T,int pos);//BF算法
int Index_KMP(SString S,SString T,int pos,int next[]);//KMP算法

void get_next(SString T, int next[]);//求模式串T的next函数值并存入数组next
void get_nextval(SString T,int nextval[]);//求模式串T的next函数值修正并存入nextval中