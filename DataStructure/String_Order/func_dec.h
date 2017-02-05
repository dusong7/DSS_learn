/*
	函数声明
*/


void Print_String(SString S);//打印

//数据操作声明
void InitString(SString &S,char *str);//初始化
Status Concat(SString &T,SString S1,SString S2);//链接
Status SubString(SString &Sub,SString S,int pos,int len);//求子串pos 为起始位置,len 为长度