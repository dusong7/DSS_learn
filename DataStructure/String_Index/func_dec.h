/*
	��������
*/
void InitString(SString &S,char *str);//��ʼ��
Status Concat(SString &T,SString S1,SString S2);//����
Status SubString(SString &Sub,SString S,int pos,int len);//���Ӵ�pos Ϊ��ʼλ��,len Ϊ����

int Index_Classic(SString S,SString T,int pos);//BF�㷨
int Index_KMP(SString S,SString T,int pos,int next[]);//KMP�㷨

void get_next(SString T, int next[]);//��ģʽ��T��next����ֵ����������next
void get_nextval(SString T,int nextval[]);//��ģʽ��T��next����ֵ����������nextval��