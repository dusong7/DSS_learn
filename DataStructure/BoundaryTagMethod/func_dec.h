/*
	函数声明
*/

Status InitSpace(Space &pav,int size);//初始化
void PrintSpaceInfo(Space pav);//输出空间信息
Space AllocBoundTag(Space &pav,int n,int e);//若有不小于n的块，则分配相应的块，并返回其首地址
void FreeSpace(Space &p,Space &pav);//回收空间p
void FreeSpaceOnly(Space &p,Space &pav);//回收空间p前后均为不为空闲
void FreeSpaceMergerLeft(Space p);//合并左边的
void FreeSpaceMergerRight(Space &p);//合并右边的
void FreeSpaceMergerLeftRight(Space p);//左右同时合并

