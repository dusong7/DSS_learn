/*
	函数声明
*/

int Init_Seq(SSTable &ST,int length,Status (* input)(SSTable &ST));//初始化
int Search_Seq(SSTable ST,KeyType key);//在ST中顺序查找等于key的元素 找到返回元素在表中的位置 否则返回0
int Search_Bin(SSTable ST,KeyType key);//在有序表ST中查找其关键字等于Key的数据元素。找到返回位置，否则返回0
Status SecondOptimal(BiTree &T,ElemType R[],float sw[],int low,int high);//由有序表R[low high]及其累计的权值表sw(sw[0]==0)递归构造次优先查找树
Status CreateSOSTree(SOSTree &T,SSTable ST);//由有序表ST创建一个次优先查找树
Status FindSW(float sw[],SSTable ST);//根据ST的权域weight 计算 sw
int Search_SOSTree(SOSTree T,KeyType key);//在次优先树中查找key 未找到返回0

Status RandNumber(SSTable &ST);//随机输入一些数字到数组中
void OutArray(SSTable ST);//输出ST的数组
Status RandOrderNumber(SSTable &ST);//随机生成有序数字到数组中
