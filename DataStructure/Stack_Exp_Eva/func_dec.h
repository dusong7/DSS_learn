/*
	函数声明
*/

//栈操作声明
Status InitStack(SqStack &S);//构建空栈
ElemType GetTop(SqStack S);//栈不为空，返回栈顶元素
Status Push(SqStack &S,ElemType e);//将e插入栈顶
Status Pop(SqStack &S,ElemType &e);//删除栈顶元素并返回到e
Status DestroyStack(SqStack &S);//销毁数据
Status ClearStack(SqStack &S);//清空栈，并不销毁数据
int StackLength(SqStack S);//返回数据长度
Status StackTraverse(SqStack S,Status (* vist)(ElemType));//从栈底到栈顶依次对每个元素调用visit()，一旦操作失败函数结束
Status StackEmpty(SqStack S);//判断是否为空栈

//求值函数
char Precede(char a,char b);//比较符号的优先级
Status In(char c);//判断字符是否在s字符数组中
int Operate(int a,char theta,int b);//计算值
ElemType OperaType(void);//调用函数 全数据为整型操作