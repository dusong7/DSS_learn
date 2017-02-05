/*
	函数声明
*/

Status InitArray(Array &A,int dim,...);    //初始化一个数组
Status DestoryArray(Array &A);             //销毁数据
Status Locate(Array A,va_list ap,int &off);//若ap指示的各下标值合法，则求出该元素在A中相对应地址off
Status Value(ElemType &e,Array A,...);     //A是数组，e是返回值，随后是下标
Status Assign(Array &A,ElemType e,...);    //A为数组,e为元素变量,随后是n个下标的值