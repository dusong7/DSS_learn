/*
	函数声明
*/

//链表操作
Status InitList(LinkList &L);//构造空的线性链表
LinkList GetHead(LinkList L);//返回头结点
Status SetCurElem(LinkList &L,ElemType e);//设置L结点的数据值
Status LocateElem(LinkList L,ElemType e,LinkList &q,int (* compare)(ElemType,ElemType));
	//L为链表,e为比较数据,q为返回的位置,compare为比较函数,如果不能找到与之匹配的第一个元素,p返回第一个满足compare大于0的位置

Status MakeNode(LinkList &p,ElemType e);//分配新的空间
Status InsFirst(LinkList &h,LinkList &p);//将p插入到h之后
LinkList NextPos(LinkList L,LinkList p);//返回L链表中p的下一个
ElemType GetCurElem(LinkList p);//返回数据元素
Status DelFirst(LinkList &L,LinkList &q);//删除L中的q结点
Status FreeNode(LinkList &p);//释放p的空间
Status ListEmpty(LinkList L);//链表是否为空
Status Append(LinkList &La,LinkList s);//链接s到La之后,s非头结点

//队列操作
Status InitQueue(LinkQueue &Q);//初始化
Status DestroyQueue(LinkQueue &Q);//销毁列队
Status EnQueue(LinkQueue &Q,QElemType e);//增加元素
Status DeQueue(LinkQueue &Q,QElemType &e);//删除元素
int QueueLength(LinkQueue q);//队列长度
Status QueueEmpty(LinkQueue q);//队列为空
Status GetHead(LinkQueue Q,QElemType &e);//返回队列头

//事件模拟
Status OrderInsert(EvenList &ev,Event en,int (* cmp)(Event a,Event b));//有序插入事件
int cmp(Event a,Event b);//事件插入比较函数
void OpenForDay(int &TotalTime,int &CustomerNum,Event &en,EvenList &ev,LinkQueue *q);//初始化
int Minimum(LinkQueue *q);//返回最小列队ID
void CustomerArrived(int CloseTime,int &CustomerNum,Event &en,EvenList &ev,LinkQueue *q);//处理到达事件 en.NType=0
void CustomerDeparture(Event &en,EvenList &ev,LinkQueue *q,QElemType &customer,int &TotalTime);//处理离开事件
void Bank_simulation(int CloseTime);//银行业务模拟，统计一天内客户在银行的逗留时间

//其他
void Random(int &durtime,int &intertime);//生成随机数