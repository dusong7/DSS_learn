/*
	�������
*/

class RadixSort{
private:
	SLList * L;
	SLList * RandData();
	void Distribute(int i,ArrType &f,ArrType &e);
	void Collect(int i,ArrType f,ArrType e);
	int ord(KeysType key);//���ַ�ӳ��Ļ�����
	int succ(int i);//�ҵ�һ���ǿ��ӱ�ĺ��
	void OutputNext();
public:
	void SetValue(SLList *data);
	void Output();
	void Sort();
	void OutputResult();
};