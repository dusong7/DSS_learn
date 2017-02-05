/*
	函数声明
*/

//顺序表操作函数声明
Status InitList(SqList &L);//初始化顺序表为单链表
Status ListInsert(SqList &L,int i,ElemType e);//插入元素 i为序号,e为数据元素
Status ListDelete(SqList &L,int i,ElemType &e);//删除数据元素 i为个数 e为删除后返回的数据
int    LocateElem(SqList L,ElemType e,int (* compare)(ElemType,ElemType));//在顺序表中查找第一个值满足 compare()元素的位置
void   MergeList(SqList La,SqList Lb,SqList &Lc);//将已知非递减线性顺序表进行归并合并

//主函数所需其他函数声明
int find(ElemType e,ElemType find);//查找匹配函数声明