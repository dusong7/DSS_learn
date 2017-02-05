/*
	类的声明
*/

class RadixSort{
private:
	SLList * L;
	SLList * RandData();
	void Distribute(int i,ArrType &f,ArrType &e);
	void Collect(int i,ArrType f,ArrType e);
	int ord(KeysType key);//将字符映射的基数上
	int succ(int i);//找第一个非空子表的后继
	void OutputNext();
public:
	void SetValue(SLList *data);
	void Output();
	void Sort();
	void OutputResult();
};