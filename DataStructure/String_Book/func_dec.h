/*
	函数声明
*/

//链表操作
Status InitList(LinkList &L);                                 //构造空的线性链表
LinkList GetHead(LinkList L);                                 //返回头结点
Status SetCurElem(LinkList &L,ElemType e);                    //设置L结点的数据值
Status LocateElem(LinkList L,ElemType e,LinkList &q,int (* compare)(ElemType,ElemType));
	//L为链表,e为比较数据,q为返回的位置,compare为比较函数,如果不能找到与之匹配的第一个元素,p返回第一个满足compare大于0的位置

Status MakeNode(LinkList &p,ElemType e);                      //分配新的空间
Status InsFirst(LinkList &h,LinkList &p);                     //将p插入到h之后
LinkList NextPos(LinkList L,LinkList p);                      //返回L链表中p的下一个
ElemType GetCurElem(LinkList p);                              //返回数据元素
Status DelFirst(LinkList &L,LinkList &q);                     //删除L中的q结点
Status FreeNode(LinkList &p);                                 //释放p的空间
Status ListEmpty(LinkList L);                                 //链表是否为空
Status Append(LinkList &La,LinkList s);                       //链接s到La之后,s非头结点

//串 堆分配声明
void InitString(HString &H);                                  //初始化
Status StrAssigne(HString &T,char *chars);                    //生成一个数据的值为chars
int StrLength(HString S);                                     //计算长度
int StrCompare(HString S,HString T);                          //字符串按字典顺序比较
Status ClearString(HString &S);                               //清空串
Status Concat(HString &T,HString S1,HString S2);              //连接串
Status SubString(HString &Sub,HString S,int pos,int len);     //求子串
Status StrCopy(HString &T,HString s);                          //复制s到T

//索引操作
Status InitIdxList(IdxListType &idxlist);                      //初始化操作
void GetLine(FILE *f,char *buf);                               //从文件中获取一行数据存到buf
void ExtractKeyWord(ElemType &bno,char *buf);                  //从buf中提取书号及关键字到bno中
Status InsIdxList(IdxListType &idxlist,ElemType bno,char *buf);//将书号为bno的书名关键字存储到idxlist中
Status GetWord(int i,HString &wd,WordListType wdlist);         //用wd返回wdlist中的第i个关键字
int GetKeyNum(char *buf);                                      //获取关键字数量
Status GetWordList(WordListType &wdlist,char *buf);            //存储缓存中的关键字
int Locate(IdxListType &idxlist,HString wd,Boolean &b);        //查看是否存在相同的索引，b为返回状态//存在返回存在位置，否则返回插入位置
Status InsertBook(IdxListType idxlist,int i,ElemType bno);     //插入新数据
void InsertNewKey(IdxListType &idxlist,int i,HString wd);      //插入新的关键字
Status PutText(FILE *g,IdxListType idxlist);                   //输出数据
Status FreeWordList(WordListType &wdlist);                     //释放关键字空间

//数组函数
int in_array(char ch,const char *str);/*判断一个字符是否在与一个字符串中，存在返回1，否则返回0*/
