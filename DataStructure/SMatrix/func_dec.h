/*
	��������
*/



void printSMatrix(TSMatrix T);//��������ʽ���ϡ�����
void printMultSMatrix(RLSMatrix T);//��������ʽ����߼�����ϡ�����

//ϡ�����
Status TransposeSMatrix(TSMatrix M,TSMatrix &T);//������Ԫ���ʾ����ϡ�����Mת��ΪT
Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T);//������Ԫ��˳����ʾ����ϡ�����Mת�þ���T
Status MultSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q);//�����˻�Q=M*N�������߼����Ӵ洢��ʾ
Status InitRLSMatrixRpos(RLSMatrix &M);//������е�һ������Ԫ�ص�λ��
