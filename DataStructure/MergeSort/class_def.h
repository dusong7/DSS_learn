/*
	�������
*/

class Merge{
private:
	SqList *SL;
	void merge(RedType SR[],RedType TR[],int i,int m,int n);//�������SR[i...m]��SR[m+1...n]�鲢ΪTR[i..n]
	void MSort(RedType SR[],RedType TR1[],int s,int t);//��SR[s..t]�鲢ΪTR1[s..t]
public:
	void SetValue(SqList * data);//����ֵ
	void Sort();//���й鲢����
	void OutputData();//�������
};