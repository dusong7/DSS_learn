/*
	函数声明
*/


Status InitBiTree(BiTree &T);//构建空树
Status PreOrderTraverse(BiTree T,Status(* Visit)(TElemType e));//遍历递归算法
Status CreateBiTree(BiTree &T,Status (* input)(TElemType &));//构建二叉树
Status InOrderTraverse_Stack(BiTree T,Status (* Visit)(TElemType e));//中序遍历//使用栈 非递归
Status InOrderTraverse_Stack2(BiTree T,Status (* Visit)(TElemType e));//中序遍历//使用栈 非递归

//栈操作声明
Status InitStack(SqStack &S);//构建空栈
Status GetTop(SqStack S,ElemType &e);//栈不为空，返回栈顶元素给e
ElemType GetTop(SqStack S);//栈不为空，返回栈顶元素
Status Push(SqStack &S,ElemType e);//将e插入栈顶
Status Pop(SqStack &S,ElemType &e);//删除栈顶元素并返回到e
Status DestroyStack(SqStack &S);//销毁数据
Status ClearStack(SqStack &S);//清空栈，并不销毁数据
int StackLength(SqStack S);//返回数据长度
Status StackTraverse(SqStack S,Status (* vist)(ElemType));//从栈底到栈顶依次对每个元素调用visit()，一旦操作失败函数结束
Status StackEmpty(SqStack S);//判断是否为空栈


//辅助函数
Status input(TElemType &e);//输入
Status Visit(TElemType e);//遍历访问