/*
	函数声明
*/

Status InitGList(GList &L);//初始化广义表
int GListDepth(GList L);//采用头尾链表存储结构，求广义表深度
Status CopyGList(GList &T,GList L);//采用链表存储结构，有广义表复制得到广义表T
Status sever(SString &str,SString &hstr);//将非空串str分割成两部分:hsub为第一个','之前的子串，str为str之后的串
Status CreateGList(GList &L,SString S);//采用头尾链表存储结构，由广义表的书写形式S创建广义表

//串数据操作声明
void InitString(SString &S,char *str);//初始化
Status Concat(SString &T,SString S1,SString S2);//链接
Status SubString(SString &Sub,SString S,int pos,int len);//求子串pos 为起始位置,len 为长度
int StrLength(SString S);//计算串的长度
Status StrCopy(SString &T,SString M);//复制串
Status ClearString(SString &T);//清空串
int StrCompare(SString S,SString T);//比较S与 T的大小，如果S>T 返回 >0 相等为 0
Status StrEmpty(SString s);//判断是否为空串