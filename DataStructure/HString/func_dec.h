/*
	��������
*/

//������
void InitString(HString &H);//��ʼ��
Status StrAssigne(HString &T,char *chars);//����һ�����ݵ�ֵΪchars
int StrLength(HString S);//���㳤��
int StrCompare(HString S,HString T);//�ַ������ֵ�˳��Ƚ�
Status ClearString(HString &S);//��մ�
Status Concat(HString &T,HString S1,HString S2);//���Ӵ�
Status SubString(HString &Sub,HString S,int pos,int len);//���Ӵ�