/*
	��������
*/

Status InitGList(GList &L);//��ʼ�������
int GListDepth(GList L);//����ͷβ����洢�ṹ�����������
Status CopyGList(GList &T,GList L);//��������洢�ṹ���й�����Ƶõ������T
Status sever(SString &str,SString &hstr);//���ǿմ�str�ָ��������:hsubΪ��һ��','֮ǰ���Ӵ���strΪstr֮��Ĵ�
Status CreateGList(GList &L,SString S);//����ͷβ����洢�ṹ���ɹ�������д��ʽS���������

//�����ݲ�������
void InitString(SString &S,char *str);//��ʼ��
Status Concat(SString &T,SString S1,SString S2);//����
Status SubString(SString &Sub,SString S,int pos,int len);//���Ӵ�pos Ϊ��ʼλ��,len Ϊ����
int StrLength(SString S);//���㴮�ĳ���
Status StrCopy(SString &T,SString M);//���ƴ�
Status ClearString(SString &T);//��մ�
int StrCompare(SString S,SString T);//�Ƚ�S�� T�Ĵ�С�����S>T ���� >0 ���Ϊ 0
Status StrEmpty(SString s);//�ж��Ƿ�Ϊ�մ�