/*
	类的声明
*/

class Merge{
private:
	SqList *SL;
	void merge(RedType SR[],RedType TR[],int i,int m,int n);//将有序表SR[i...m]和SR[m+1...n]归并为TR[i..n]
	void MSort(RedType SR[],RedType TR1[],int s,int t);//将SR[s..t]归并为TR1[s..t]
public:
	void SetValue(SqList * data);//设置值
	void Sort();//进行归并排序
	void OutputData();//输出数据
};