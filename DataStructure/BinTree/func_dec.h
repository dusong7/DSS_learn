/*
	��������
*/


Status InitBiTree(BiTree &T);//��������
Status PreOrderTraverse(BiTree T,Status(* Visit)(TElemType e));//�����ݹ��㷨
Status CreateBiTree(BiTree &T,Status (* input)(TElemType &));//����������
Status InOrderTraverse_Stack(BiTree T,Status (* Visit)(TElemType e));//�������//ʹ��ջ �ǵݹ�
Status InOrderTraverse_Stack2(BiTree T,Status (* Visit)(TElemType e));//�������//ʹ��ջ �ǵݹ�

//ջ��������
Status InitStack(SqStack &S);//������ջ
Status GetTop(SqStack S,ElemType &e);//ջ��Ϊ�գ�����ջ��Ԫ�ظ�e
ElemType GetTop(SqStack S);//ջ��Ϊ�գ�����ջ��Ԫ��
Status Push(SqStack &S,ElemType e);//��e����ջ��
Status Pop(SqStack &S,ElemType &e);//ɾ��ջ��Ԫ�ز����ص�e
Status DestroyStack(SqStack &S);//��������
Status ClearStack(SqStack &S);//���ջ��������������
int StackLength(SqStack S);//�������ݳ���
Status StackTraverse(SqStack S,Status (* vist)(ElemType));//��ջ�׵�ջ�����ζ�ÿ��Ԫ�ص���visit()��һ������ʧ�ܺ�������
Status StackEmpty(SqStack S);//�ж��Ƿ�Ϊ��ջ


//��������
Status input(TElemType &e);//����
Status Visit(TElemType e);//��������