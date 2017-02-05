/*
	函数声明
*/

//串声明
void InitString(HString &H);//初始化
Status StrAssigne(HString &T,char *chars);//生成一个数据的值为chars
int StrLength(HString S);//计算长度
int StrCompare(HString S,HString T);//字符串按字典顺序比较
Status ClearString(HString &S);//清空串
Status Concat(HString &T,HString S1,HString S2);//连接串
Status SubString(HString &Sub,HString S,int pos,int len);//求子串