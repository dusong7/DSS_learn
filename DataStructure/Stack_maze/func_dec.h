/*
	��������
*/

//ջ��������
Status InitStack(SqStack &S);//������ջ
Status GetTop(SqStack S,ElemType &e);//ջ��Ϊ�գ�����ջ��Ԫ�ظ�e��������ջ��ָ��
Status Push(SqStack &S,ElemType e);//��e����ջ��
Status Pop(SqStack &S,ElemType &e);//ɾ��ջ��Ԫ�ز����ص�e
Status DestroyStack(SqStack &S);//��������
Status ClearStack(SqStack &S);//���ջ��������������
int StackLength(SqStack S);//�������ݳ���
Status StackTraverse(SqStack S,Status (* vist)(ElemType));//��ջ�׵�ջ�����ζ�ÿ��Ԫ�ص���visit()��һ������ʧ�ܺ�������
Status StackEmpty(SqStack S);//�ж��Ƿ�Ϊ��ջ

//�Թ�����
Status Pass(MazeType maze,PosType cur);//�жϸõ��Ƿ��߹�
Status Footprint(MazeType &maze,PosType cur);//�����㼣
Status MarkPrint(MazeType &maze,PosType cur);//���Ϊ�޷�ͨ��
PosType NextPos(PosType &cur,int i);//��һ������
Status MazePath(MazeType &maze,PosType start,PosType end,SqStack &S);//���Թ�