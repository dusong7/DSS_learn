#define VERTUX_MAX 26
#define MAXVALUE 32767
typedef struct
{
  char VERTEX[VERTUX_MAX];   //Weight value
  int  Edges[VERTUX_MAX][VERTUX_MAX]; //
  int  isTravel[VERTUX_MAX];  // 
  int  VertexNum;
  int  EdgeNum;  
  int  GraphType;   //0 is undirected, 1 is directed
}MatrixGraph;

void CreateMatrix(MatrixGraph *G);  //Generate adjacancy matrix
void OutMatrix(MatrixGraph *G);     //Out adjacency matrixint

int number[][]={1,2,3,4}
int (*num)[2]=(int(*)[2])malloc(sizeof(int)*2*2);
for(int i=0;i<2;i++)
{
  for(int j=0;j<2;j++)
  {
    num[i][j] = number[i][j];
  }
}
