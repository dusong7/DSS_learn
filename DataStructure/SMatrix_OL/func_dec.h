/*
	��������
*/

void inputNum(int &m,int &n,int &tu);      //������ֵ mΪ�� nΪ�� tuΪ����
Status InputData(OLNode &e,CrossList M);   //����e��ϡ����ֵ


Status InitSMatrix_OL(CrossList &M);       //��ʼ��ϡ�����
Status CreatSMatrix_OL(CrossList &M,void (* inputNum)(int &,int &,int &),Status(* InputData)(OLNode &,CrossList));
                                           //inputNum Ϊ�������� ���� ���� InputData Ϊ�������ݣ����ݳɹ��򷵻�OK ���򷵻�ERROR
void PrintSMatrix_OL(CrossList M);         //��������ʽ���ϡ�����M
