/*
	数据结构操作源码
*/

#include "head.h"

void Random(int &durtime,int &intertime){
	//生成随机数
	durtime=rand()%31;
	intertime=rand()%6;
}