/*
	��������
*/

//���ݲ�������˵��

int LocateElem_SL(SLinkList S,ElemType e,int (* compare)(ElemType,ElemType));//�������в��ҵ�һ��ֵΪ e ��Ԫ�� �ҵ�����λ�ã����򷵻� 0 ,compare Ϊ�ȽϺ���
void InitSpace_SL(SLinkList &space);//��һά�����и�����������һ����������,space[0].curΪͷָ��// "0" ��ʾ��
int Malloc_SL(SLinkList &space);//����������Ϊ�գ��򷵻ط���Ľ���±꣬���򷵻�0
void Free_SL(SLinkList &space,int i);void difference(SLinkList &space, int &S,void (* InputData)(ElemType &),int (* compare)(ElemType,ElemType));
	//�������뼯��A�ͼ���B��Ԫ�أ���һά����space�н�����ʾ���ϣ�A-B��U (B-A)�ľ�̬����,SΪ��ͷָ�룬���豸�ÿռ��㹻��,space[0].curΪ��ͷָ��
	//InputDataΪ���뺯��//���±�Ϊi�Ŀռ���Ϊ���ÿռ�


//������������
void input(ElemType &e);//���뺯��
int com(ElemType e1,ElemType e2);//�ȽϺ���
