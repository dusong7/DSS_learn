/*
	函数声明
*/

Status InitBiTree(BiThrTree &T);//构建空树
Status InitThrBiTree(BiThrTree &T);//构建空线索树
Status CreateBiTree(BiThrTree &T,Status (* input)(TElemType &));//按先后顺序依次输入二叉树中的节点
Status InOrderTraverse_Thr(BiThrTree T,Status (* Visit)(TElemType e));//中序遍历二叉树T的非递归算法
Status InOrderThreading(BiThrTree &Thrt,BiThrTree T);//中序遍历二叉树，将其线索化
void InThreading(BiThrTree p,BiThrTree &pre);//线索化遍历方法

//辅助函数
Status input(TElemType &e);//输入
Status Visit(TElemType e);//遍历访问