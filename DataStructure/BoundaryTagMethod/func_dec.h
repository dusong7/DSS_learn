/*
	��������
*/

Status InitSpace(Space &pav,int size);//��ʼ��
void PrintSpaceInfo(Space pav);//����ռ���Ϣ
Space AllocBoundTag(Space &pav,int n,int e);//���в�С��n�Ŀ飬�������Ӧ�Ŀ飬���������׵�ַ
void FreeSpace(Space &p,Space &pav);//���տռ�p
void FreeSpaceOnly(Space &p,Space &pav);//���տռ�pǰ���Ϊ��Ϊ����
void FreeSpaceMergerLeft(Space p);//�ϲ���ߵ�
void FreeSpaceMergerRight(Space &p);//�ϲ��ұߵ�
void FreeSpaceMergerLeftRight(Space p);//����ͬʱ�ϲ�

