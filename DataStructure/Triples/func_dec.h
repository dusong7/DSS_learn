/*
	��������
*/

Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3);//������Ԫ��T��Ԫ��e1 e2 e3�ֱ�ֵ��v1 v2 v3
Status DestroyTriplet(Triplet &T);//������Ԫ�� T
Status Get(Triplet T,int i,ElemType &e);//��Ԫ�����ʱ����e����T�ĵ�i��Ԫ��
Status Put(Triplet &T,int i,ElemType e);//�ı�T�ĵ�i��Ԫ��
Status IsAsceding(Triplet T);//���T������Ԫ�����������з���1���򷵻�0
Status IsDsceding(Triplet T);//���T������Ԫ���Խ������з���1���򷵻�0
Status Max(Triplet T,ElemType &e);//��e����T�����Ԫ��
Status Min(Triplet T,ElemType &e);//��e����T����СԪ��