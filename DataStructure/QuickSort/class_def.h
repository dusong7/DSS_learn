/*
	�������
*/

class QuickSort{
private:
	SqList * SL;
	int Partition(int low,int high);//����
	void QSort(int low,int high);//��low...hight����������
	bool ExchangeValue(RedType &a,RedType &b);//���� a b ��ֵ
public:
	void SetValue(SqList * data);//����ֵ
	void Sort();//��������
	void OutputData();//�������
};