/*
	��������
*/

int Init_Seq(SSTable &ST,int length,Status (* input)(SSTable &ST));//��ʼ��
int Search_Seq(SSTable ST,KeyType key);//��ST��˳����ҵ���key��Ԫ�� �ҵ�����Ԫ���ڱ��е�λ�� ���򷵻�0
int Search_Bin(SSTable ST,KeyType key);//�������ST�в�����ؼ��ֵ���Key������Ԫ�ء��ҵ�����λ�ã����򷵻�0
Status SecondOptimal(BiTree &T,ElemType R[],float sw[],int low,int high);//�������R[low high]�����ۼƵ�Ȩֵ��sw(sw[0]==0)�ݹ鹹������Ȳ�����
Status CreateSOSTree(SOSTree &T,SSTable ST);//�������ST����һ�������Ȳ�����
Status FindSW(float sw[],SSTable ST);//����ST��Ȩ��weight ���� sw
int Search_SOSTree(SOSTree T,KeyType key);//�ڴ��������в���key δ�ҵ�����0

Status RandNumber(SSTable &ST);//�������һЩ���ֵ�������
void OutArray(SSTable ST);//���ST������
Status RandOrderNumber(SSTable &ST);//��������������ֵ�������
