/*
	��������
*/

int Hash(KeyType k);//���ϣֵ
void colloision(int &p,int &c);//���ϣֵ��ͻʱ����һ����ַ
Status SearchHash(HashTable H,KeyType K,int &p,int &c);//�ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK��Ԫ��
Status InsertHash(HashTable &H,ElemType e);//�����Ҳ��ɹ�ʱ��������Ԫ��e�����ŵ�ַ��ϣ��H��
