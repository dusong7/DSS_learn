/*
	类的声明
*/

class QuickSort{
private:
	SqList * SL;
	int Partition(int low,int high);//划分
	void QSort(int low,int high);//对low...hight做快速排序
	bool ExchangeValue(RedType &a,RedType &b);//交换 a b 的值
public:
	void SetValue(SqList * data);//设置值
	void Sort();//进行排序
	void OutputData();//输出数据
};