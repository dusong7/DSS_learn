/*
	��������
*/

//�������
Status InitList(LinkList &L);                                 //����յ���������
LinkList GetHead(LinkList L);                                 //����ͷ���
Status SetCurElem(LinkList &L,ElemType e);                    //����L��������ֵ
Status LocateElem(LinkList L,ElemType e,LinkList &q,int (* compare)(ElemType,ElemType));
	//LΪ����,eΪ�Ƚ�����,qΪ���ص�λ��,compareΪ�ȽϺ���,��������ҵ���֮ƥ��ĵ�һ��Ԫ��,p���ص�һ������compare����0��λ��

Status MakeNode(LinkList &p,ElemType e);                      //�����µĿռ�
Status InsFirst(LinkList &h,LinkList &p);                     //��p���뵽h֮��
LinkList NextPos(LinkList L,LinkList p);                      //����L������p����һ��
ElemType GetCurElem(LinkList p);                              //��������Ԫ��
Status DelFirst(LinkList &L,LinkList &q);                     //ɾ��L�е�q���
Status FreeNode(LinkList &p);                                 //�ͷ�p�Ŀռ�
Status ListEmpty(LinkList L);                                 //�����Ƿ�Ϊ��
Status Append(LinkList &La,LinkList s);                       //����s��La֮��,s��ͷ���

//�� �ѷ�������
void InitString(HString &H);                                  //��ʼ��
Status StrAssigne(HString &T,char *chars);                    //����һ�����ݵ�ֵΪchars
int StrLength(HString S);                                     //���㳤��
int StrCompare(HString S,HString T);                          //�ַ������ֵ�˳��Ƚ�
Status ClearString(HString &S);                               //��մ�
Status Concat(HString &T,HString S1,HString S2);              //���Ӵ�
Status SubString(HString &Sub,HString S,int pos,int len);     //���Ӵ�
Status StrCopy(HString &T,HString s);                          //����s��T

//��������
Status InitIdxList(IdxListType &idxlist);                      //��ʼ������
void GetLine(FILE *f,char *buf);                               //���ļ��л�ȡһ�����ݴ浽buf
void ExtractKeyWord(ElemType &bno,char *buf);                  //��buf����ȡ��ż��ؼ��ֵ�bno��
Status InsIdxList(IdxListType &idxlist,ElemType bno,char *buf);//�����Ϊbno�������ؼ��ִ洢��idxlist��
Status GetWord(int i,HString &wd,WordListType wdlist);         //��wd����wdlist�еĵ�i���ؼ���
int GetKeyNum(char *buf);                                      //��ȡ�ؼ�������
Status GetWordList(WordListType &wdlist,char *buf);            //�洢�����еĹؼ���
int Locate(IdxListType &idxlist,HString wd,Boolean &b);        //�鿴�Ƿ������ͬ��������bΪ����״̬//���ڷ��ش���λ�ã����򷵻ز���λ��
Status InsertBook(IdxListType idxlist,int i,ElemType bno);     //����������
void InsertNewKey(IdxListType &idxlist,int i,HString wd);      //�����µĹؼ���
Status PutText(FILE *g,IdxListType idxlist);                   //�������
Status FreeWordList(WordListType &wdlist);                     //�ͷŹؼ��ֿռ�

//���麯��
int in_array(char ch,const char *str);/*�ж�һ���ַ��Ƿ�����һ���ַ����У����ڷ���1�����򷵻�0*/
