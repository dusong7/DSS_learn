/*
	��������
*/

Status InitArray(Array &A,int dim,...);    //��ʼ��һ������
Status DestoryArray(Array &A);             //��������
Status Locate(Array A,va_list ap,int &off);//��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A�����Ӧ��ַoff
Status Value(ElemType &e,Array A,...);     //A�����飬e�Ƿ���ֵ��������±�
Status Assign(Array &A,ElemType e,...);    //AΪ����,eΪԪ�ر���,�����n���±��ֵ