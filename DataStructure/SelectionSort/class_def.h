/*
	类的声明
*/

class SelectionSort{
private:
	SqList DataList;//存储的数组
	void Adjust(int s,int m);//调整记录
public:
	bool SetValue(SqList data);//设置要排序的数组
	void OutputData();//输出数据
	bool Sort();//排序
};