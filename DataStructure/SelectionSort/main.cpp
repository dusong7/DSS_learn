/*
	Ö÷º¯Êý
*/

#include "head.h"

int main(void){
	SelectionSort sort;
	sort.SetValue(RandomData());
	sort.OutputData();
	sort.Sort();
	sort.OutputData();
	cout << "\nResult End!\n";
	system("pause");
	return 0;
}