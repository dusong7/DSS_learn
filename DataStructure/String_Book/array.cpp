/*
	�����жϺ���
*/

#include "head.h"
#include <string.h>

int in_array(char ch,const char *str){
	/*�ж�һ���ַ��Ƿ�����һ���ַ����У����ڷ���1�����򷵻�0*/

	int i,size;
	size=strlen(str);
	for(i=0;i<size;i++){
		if(ch==*(str+i))return 1;	
	}
	return 0;
}