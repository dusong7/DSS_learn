/*
	��������
*/

Status InitBiTree(BiThrTree &T);//��������
Status InitThrBiTree(BiThrTree &T);//������������
Status CreateBiTree(BiThrTree &T,Status (* input)(TElemType &));//���Ⱥ�˳����������������еĽڵ�
Status InOrderTraverse_Thr(BiThrTree T,Status (* Visit)(TElemType e));//�������������T�ķǵݹ��㷨
Status InOrderThreading(BiThrTree &Thrt,BiThrTree T);//�������������������������
void InThreading(BiThrTree p,BiThrTree &pre);//��������������

//��������
Status input(TElemType &e);//����
Status Visit(TElemType e);//��������