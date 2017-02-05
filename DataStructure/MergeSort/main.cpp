/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	Merge sort;
	sort.SetValue(RandomData());
	sort.OutputData();
	sort.Sort();
	cout << endl;
	sort.OutputData();
	cout << "\nResult End!\n";
	system("pause");
	return 0;
}