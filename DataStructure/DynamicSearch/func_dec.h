/*
	函数声明
*/

BiTree SearchBST(BiTree T,KeyType key);//查找指针T所指二叉排序树中递归查找某个关键字等于Key的元素数据
Status SearchBST(BiTree T,KeyType key,BiTree f,BiTree &p);//在T中查找key，查找成功P指向该元素节点，返回TURE
Status InsertBST(BiTree &T,ElemType e);//当二叉树T中不存在关键字等于e.key的数据元素时，插入e返回TRUE
Status CreatBST(BiTree &T,int num,Status(* input)(ElemType &));//创建一个树
Status PreOrderTraverse(BiTree T,Status(* Visit)(ElemType e));//中序遍历树
Status Delete(BiTree &p);//再树中删除p并重新连接它的左右子树
Status DeleteBST(BiTree &T, KeyType key);//若存在key，删除该元素，返回TRUE 否则返回FALSE

Status InputElemType(ElemType &e);//输入元素
Status VisitElemType(ElemType e);//输出数