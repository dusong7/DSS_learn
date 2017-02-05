/*
	函数声明
*/

//数据操作函数说明

int LocateElem_SL(SLinkList S,ElemType e,int (* compare)(ElemType,ElemType));//在链表中查找第一个值为 e 的元素 找到返回位置，否则返回 0 ,compare 为比较函数
void InitSpace_SL(SLinkList &space);//将一维数组中各各分量链成一个备用链表,space[0].cur为头指针// "0" 表示空
int Malloc_SL(SLinkList &space);//若备用链表不为空，则返回分配的结点下标，否则返回0
void Free_SL(SLinkList &space,int i);void difference(SLinkList &space, int &S,void (* InputData)(ElemType &),int (* compare)(ElemType,ElemType));
	//依次输入集合A和集合B的元素，在一维数组space中建立表示集合（A-B）U (B-A)的静态链表,S为其头指针，假设备用空间足够大,space[0].cur为其头指针
	//InputData为输入函数//将下标为i的空间作为备用空间


//其他函数定义
void input(ElemType &e);//输入函数
int com(ElemType e1,ElemType e2);//比较函数
