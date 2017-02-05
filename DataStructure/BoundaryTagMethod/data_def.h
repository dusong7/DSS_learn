/*
	数据结构类型定义
*/

typedef int OtherType;

typedef struct WORD{
	union {//head 和 foot分别是结点的第一个字和最后的字
		WORD *llink;//头部域，指向前驱结点
		WORD *uplink;//底部域，指向本结点头部
	};
	int tag;//块标志，0:空闲 1:占用，头部和尾部均有
	int size;//头部域，块大小
	WORD *rlink;//头部域，指向后继结点
	OtherType other;//字的其他部分
} WORD, head, foot, *Space;

#define FootLoc(p) p+p->size-1//指向p所指结点的底部