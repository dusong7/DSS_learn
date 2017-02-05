/*
	函数声明
*/

// 双向循环链表 数据结构操作函数

void CreatList_DuL(DuLinkList &L,int n,void (* InputData)(ElemType &));//创建链表 向链表头之前插入
int ListLength(DuLinkList L);
	//返回数据长度,由于判断为下一个地址的比较，故缺少一个值，因此从1开始计数
	//L必须是经过初始化的数据
DuLinkList GetElemP_Dul(DuLinkList L,int i);//返回第i个结点
Status ListInsert_DuL(DuLinkList &L,int i,ElemType e);//在第i个位置之前插入元素e
Status ListDelete_Dul(DuLinkList &L,int i,ElemType &e);//删除L链表中头结点的第i 个元素
Status DestroyList_Dul(DuLinkList &L);//销毁链表
Status Append(DuLinkList &La,DuLinkList &Lb);//将链表Lb链接到La之后

//其他操作函数
void input(ElemType &e);//输入数据