/*
	函数声明
*/

Status CreateGraph(MGraph &G);//采用数组法构造图G
Status CreateUDN(MGraph &G);//构造无向网G
int LocateVex(MGraph G,int u);//返回图的位置信息
Status InputIncINFO(InfoType *info);//输入弧的其他信息
void PrintGraphArray(MGraph G);//打印图的数组
