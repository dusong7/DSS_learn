/*
	函数声明
*/



void printSMatrix(TSMatrix T);//以数组形式输出稀疏矩阵
void printMultSMatrix(RLSMatrix T);//以数组形式输出逻辑链接稀疏矩阵

//稀疏矩阵
Status TransposeSMatrix(TSMatrix M,TSMatrix &T);//采用三元组表示，将稀疏矩阵M转置为T
Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T);//采用三元组顺序表表示，求稀疏矩阵M转置矩阵T
Status MultSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q);//求矩阵乘积Q=M*N，采用逻辑链接存储表示
Status InitRLSMatrixRpos(RLSMatrix &M);//计算各行第一个非零元素的位置
