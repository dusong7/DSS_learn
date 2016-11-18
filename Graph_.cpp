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
void OutMatrix(MatrixGraph *G);     //Out adjacency matrix
