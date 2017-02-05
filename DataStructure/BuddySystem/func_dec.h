/*
	函数声明
*/

void InitBuddy(FreeList &avail);//初始化
WORD_b* ALLocBuddy (FreeList &avail,int n);//avail[0.....m]为可利用空间表，n为申请分配量
void PrintBuddyInfo(FreeList avail);//输出空间分配信息


void RecordAddress(WORD_b **AddList,WORD_b *p,int n);//记录分配的地址