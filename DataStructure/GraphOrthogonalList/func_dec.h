/*
	��������
*/

Status CreatDG(OLGraph &G);//����ʮ������洢����������ͼG
Status InputIncINFO(InfoType *info);//���뻡��������Ϣ
int LocateVex(OLGraph G,int u);//�ж�λ����Ϣ
void printDG(OLGraph G);//���ͼ��Ϣ
void DFSTraverse(OLGraph G,Status (* Visit)(OLGraph G,int v),int visited[MAX_VERTEX_NUM]);//��ͼ����������ȱ���
void DFS(OLGraph G,int v,int visited[MAX_VERTEX_NUM],Status (* Visit)(OLGraph G,int v));//�ӵ�V����������ݹ�ؽ�����ȱ���
int GetAdhVex(OLGraph G,int v,int list[MAX_VERTEX_NUM]);//��ȡv�����Χ�Ľ�������
int FirstAdjVex(OLGraph G,int v);//��ȡv�����Χ�ĵ�һ�����
int NextAdjVex(OLGraph G,int v,int w);//��ȡv�����Χw���֮��Ľ��
void BFSTraverse(OLGraph G,Status (* Visit)(OLGraph G,int v),int visited[MAX_VERTEX_NUM]);//��������ȷǵݹ����ͼ��ʹ�ö���Q

Status VisitG(OLGraph G,int v);//��������
void PrintList(int list[MAX_VERTEX_NUM],int n);//����б�

//���в���
Status InitQueue(LinkQueue &Q);//��ʼ��
Status DestroyQueue(LinkQueue &Q);//�����ж�
Status EnQueue(LinkQueue &Q,QElemType e);//����Ԫ��
Status DeQueue(LinkQueue &Q,QElemType &e);//ɾ��Ԫ��
int QueueLength(LinkQueue q);//���г���
Status QueueEmpty(LinkQueue q);//����Ϊ��
Status GetHead(LinkQueue Q,QElemType &e);//���ض���ͷ