/*
	函数声明
*/
//链表操作
Status InitList(polynomail &L);//构造空的线性链表
LinkList GetHead(LinkList L);//返回头结点
Status SetCurElem(LinkList &L,ElemType e);//设置L结点的数据值
Status LocateElem(LinkList L,ElemType e,Postion &q,int (* compare)(ElemType,ElemType));
	//L为链表,e为比较数据,q为返回的位置,compare为比较函数,如果不能找到与之匹配的第一个元素,p返回第一个满足compare大于0的位置

Status MakeNode(LinkList &p,ElemType e);//分配新的空间
Status InsFirst(LinkList &h,LinkList &p);//将p插入到h之后
LinkList NextPos(LinkList L,LinkList p);//返回L链表中p的下一个
ElemType GetCurElem(LinkList p);//返回数据元素
Status DelFirst(LinkList &L,LinkList &q);//删除L中的q结点
Status FreeNode(LinkList &p);//释放p的空间
Status ListEmpty(LinkList L);//链表是否为空
Status Append(LinkList &La,LinkList s);//链接s到La之后,s非头结点

//多项式函数
void CreatPolyn(polynomail &P,int n,void (* Input)(ElemType &));//创建数据
void PrintPolyn(polynomail P);//打印数据
void AddPoly(polynomail &Pa,polynomail &Pb,int (* compare)(ElemType,ElemType));//多项式加法
void SubPoly(polynomail &Pa,polynomail &Pb,int (* compare)(ElemType,ElemType));//多项式减法

//数据比较及输入
int com(ElemType e1,ElemType e2);//数据输入
void InputData(ElemType &e);//数据输入