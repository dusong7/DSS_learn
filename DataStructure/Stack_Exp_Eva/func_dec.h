/*
	��������
*/

//ջ��������
Status InitStack(SqStack &S);//������ջ
ElemType GetTop(SqStack S);//ջ��Ϊ�գ�����ջ��Ԫ��
Status Push(SqStack &S,ElemType e);//��e����ջ��
Status Pop(SqStack &S,ElemType &e);//ɾ��ջ��Ԫ�ز����ص�e
Status DestroyStack(SqStack &S);//��������
Status ClearStack(SqStack &S);//���ջ��������������
int StackLength(SqStack S);//�������ݳ���
Status StackTraverse(SqStack S,Status (* vist)(ElemType));//��ջ�׵�ջ�����ζ�ÿ��Ԫ�ص���visit()��һ������ʧ�ܺ�������
Status StackEmpty(SqStack S);//�ж��Ƿ�Ϊ��ջ

//��ֵ����
char Precede(char a,char b);//�ȽϷ��ŵ����ȼ�
Status In(char c);//�ж��ַ��Ƿ���s�ַ�������
int Operate(int a,char theta,int b);//����ֵ
ElemType OperaType(void);//���ú��� ȫ����Ϊ���Ͳ���