/*
	数据结构类型定义
*/

#define MaxBookNum 1000  //定义书籍最大长度
#define MaxKeyNum  2500  //索引表的最大容量
#define MaxLineLen 500   //书目串的最大容量
#define MaxWordNum 10    //词表最大容量

//堆分配数据定义
typedef struct{
	char *ch;        //非空为NULL，否则为分配的空间
	int  length;      //串长度
}HString;	

typedef struct{
	char **item;     //字符串数组
	int  last;       //词表的长度
}WordListType;

typedef int ElemType;      //链表数据元素类型（书号类型）

typedef struct LNode{
	ElemType     data;    //存储空间基数地址
	struct LNode *next;   //下一个地址
}*LinkList;

typedef struct{
	HString  Key;        //关键字
	LinkList BnoList;    //存放书号的链表
}IdxTermType;            //索引项目类型

typedef struct{
	IdxTermType item[MaxKeyNum+1];
	int         last;
}IdxListType;           //索引表类型（有序表）

