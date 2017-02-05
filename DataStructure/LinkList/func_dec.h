/*
	函数声明
*/

//数据操作函数定义
void   CreatList(LinkList &L,int n,void (* InputData)(ElemType &));//创建链表 向链表头之后插入 非末尾插入
Status GetElem(LinkList L,int i,ElemType &e);//获取第 i 个元素
Status ListInsert(LinkList &L,int i,ElemType e);//在第 i 个元素之前插入e
Status ListDelete(LinkList &L,int i,ElemType &e);//删除节点中的第i 个元素，并保存在 e中
void   MerageList(LinkList &La,LinkList &Lb,LinkList &Lc,int (* compare)(ElemType,ElemType));//合并链表a b 到c compare为比较函数

//其他函数
void Input(ElemType &e);//输入函数
int Compare(ElemType e1,ElemType e2);//比较函数