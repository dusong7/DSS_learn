/*
	函数声明
*/

void inputNum(int &m,int &n,int &tu);      //输入数值 m为行 n为列 tu为总数
Status InputData(OLNode &e,CrossList M);   //输入e的稀疏数值


Status InitSMatrix_OL(CrossList &M);       //初始化稀疏矩阵
Status CreatSMatrix_OL(CrossList &M,void (* inputNum)(int &,int &,int &),Status(* InputData)(OLNode &,CrossList));
                                           //inputNum 为输入行数 列数 总数 InputData 为输入数据，数据成功则返回OK 否则返回ERROR
void PrintSMatrix_OL(CrossList M);         //以数组形式输出稀疏矩阵M
