/*
	数组判断函数
*/

#include "head.h"
#include <string.h>

int in_array(char ch,const char *str){
	/*判断一个字符是否在与一个字符串中，存在返回1，否则返回0*/

	int i,size;
	size=strlen(str);
	for(i=0;i<size;i++){
		if(ch==*(str+i))return 1;	
	}
	return 0;
}