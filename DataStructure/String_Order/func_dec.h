/*
	��������
*/


void Print_String(SString S);//��ӡ

//���ݲ�������
void InitString(SString &S,char *str);//��ʼ��
Status Concat(SString &T,SString S1,SString S2);//����
Status SubString(SString &Sub,SString S,int pos,int len);//���Ӵ�pos Ϊ��ʼλ��,len Ϊ����