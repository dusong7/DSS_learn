/*
	函数声明
*/

Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3);//构造三元组T，元素e1 e2 e3分别赋值给v1 v2 v3
Status DestroyTriplet(Triplet &T);//销毁三元组 T
Status Get(Triplet T,int i,ElemType &e);//三元组存在时，用e返回T的第i个元素
Status Put(Triplet &T,int i,ElemType e);//改变T的第i个元素
Status IsAsceding(Triplet T);//如果T的三个元素以升序排列返回1否则返回0
Status IsDsceding(Triplet T);//如果T的三个元素以降序排列返回1否则返回0
Status Max(Triplet T,ElemType &e);//用e返回T的最大元素
Status Min(Triplet T,ElemType &e);//用e返回T的最小元素