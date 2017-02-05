/*
	数据结构类型定义
*/

#define m 16 //可利用空间总容量64K字的2的幂次，字表的个数为m+1

typedef int OtherType;

typedef struct WORD_b{
	WORD_b *llink;//指向前驱
	int tag;//0空闲 1占用
	int kval;//块大小 值为2的幂次 k
	WORD_b *rlink;//指向后继
	OtherType other;//结点其他信息
}WORD_b,head;

typedef struct HeadNode{
	int nodesize;//该链表空闲块的大小
	WORD_b *first;//链表头指针
}FreeList[m+1];//表头向量类型