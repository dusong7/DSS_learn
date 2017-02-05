/*
	函数声明
*/

Status CreatDG(OLGraph &G);//采用十字链表存储，构造有向图G
Status InputIncINFO(InfoType *info);//输入弧的其他信息
int LocateVex(OLGraph G,int u);//判断位置信息
void printDG(OLGraph G);//输出图信息
void DFSTraverse(OLGraph G,Status (* Visit)(OLGraph G,int v),int visited[MAX_VERTEX_NUM]);//对图进行深度优先遍历
void DFS(OLGraph G,int v,int visited[MAX_VERTEX_NUM],Status (* Visit)(OLGraph G,int v));//从第V个顶点出发递归地进行深度遍历
int GetAdhVex(OLGraph G,int v,int list[MAX_VERTEX_NUM]);//获取v结点周围的结点的数组
int FirstAdjVex(OLGraph G,int v);//获取v结点周围的第一个结点
int NextAdjVex(OLGraph G,int v,int w);//获取v结点周围w结点之后的结点
void BFSTraverse(OLGraph G,Status (* Visit)(OLGraph G,int v),int visited[MAX_VERTEX_NUM]);//按广度优先非递归遍历图，使用队列Q

Status VisitG(OLGraph G,int v);//遍历函数
void PrintList(int list[MAX_VERTEX_NUM],int n);//输出列表

//队列操作
Status InitQueue(LinkQueue &Q);//初始化
Status DestroyQueue(LinkQueue &Q);//销毁列队
Status EnQueue(LinkQueue &Q,QElemType e);//增加元素
Status DeQueue(LinkQueue &Q,QElemType &e);//删除元素
int QueueLength(LinkQueue q);//队列长度
Status QueueEmpty(LinkQueue q);//队列为空
Status GetHead(LinkQueue Q,QElemType &e);//返回队列头