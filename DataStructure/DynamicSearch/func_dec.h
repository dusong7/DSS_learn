/*
	��������
*/

BiTree SearchBST(BiTree T,KeyType key);//����ָ��T��ָ�����������еݹ����ĳ���ؼ��ֵ���Key��Ԫ������
Status SearchBST(BiTree T,KeyType key,BiTree f,BiTree &p);//��T�в���key�����ҳɹ�Pָ���Ԫ�ؽڵ㣬����TURE
Status InsertBST(BiTree &T,ElemType e);//��������T�в����ڹؼ��ֵ���e.key������Ԫ��ʱ������e����TRUE
Status CreatBST(BiTree &T,int num,Status(* input)(ElemType &));//����һ����
Status PreOrderTraverse(BiTree T,Status(* Visit)(ElemType e));//���������
Status Delete(BiTree &p);//������ɾ��p����������������������
Status DeleteBST(BiTree &T, KeyType key);//������key��ɾ����Ԫ�أ�����TRUE ���򷵻�FALSE

Status InputElemType(ElemType &e);//����Ԫ��
Status VisitElemType(ElemType e);//�����