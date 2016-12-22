#include <iostream>   
using namespace std;   
   
#define INF 10000   
#define N 8   
   
typedef struct STRUCT_Edge_Type   
{   
    int start;   
    int end;   
    int excluded_cost;   
}EdgeType;   
   
typedef struct STRUCT_INFO_TYPE   
{   
    int C[N][N];   
    int Valid_Rows[N]; //有效行集合，初值1...n;当TSP取到一条边时，删除该边所在的行   
    int Valid_Cols[N]; //有列行集合，初值1...n;当TSP取到一条边时，删除该边所在的列   
    int valid_row_num; //有效行的个数   
    int valid_col_num; //有效列的个数，其实有效行的个数=有效列的个数，此处有点多余！可读性好一些吧   
    EdgeType edges[N]; //边集合，数组从1...N   
    int edge_num;      //已选边的个数   
    int current_bound; //当前下界   
}InfoType;   
   
EdgeType  best_solution[N];   
int best_bound = INF;   
   
void find_optimal_solution(InfoType & info);   
   
void main()   
{   
    int C[N][N] = { {0,0,0,0,0,0,0,0},   
                    {0,INF,3,93,13,33,9,57},   
                    {0,4,INF,77,42,21,16,34},   
                    {0,45,17,INF,36,16,28,25},   
                    {0,39,90,80,INF,56,7,91},   
                    {0,28,46,88,33,INF,25,57},   
                    {0,3,88,18,46,92,INF,7},   
                    {0,44,26,33,27,84,39,INF}   
                };   
    EdgeType best_solution[N];   
    InfoType init_info;   
    int i,j;   
       
       
       
    for(i=1;i<N;i++)   
        for(j=1;j<N;j++)   
            init_info.C[i][j] = C[i][j];   
    for(i=1;i<N;i++)   
    {   
        init_info.Valid_Rows[i] = i;   
        init_info.Valid_Cols[i] = i;   
    }   
    init_info.edge_num = 0;   
    init_info.valid_row_num = N-1;   
    init_info.valid_col_num = N-1;   
    init_info.current_bound = 0;   
       
    find_optimal_solution(init_info);   
    for(i=1;i<N;i++)   
        cout << best_solution[i].start << "->" << best_solution[i].end << " , ";   
    cout << endl;   
}   
   
int set_zeros(InfoType & the_info)   
{   
    int smallest;   
    int i,j,row ,col;   
    //寻找矩阵每一行的最小元素，若不为0，则增加下届current_bound的值   
    i=0;   
    for(i=1;i<=the_info.valid_row_num;i++)   
    {   
        smallest = INF;   
        row = the_info.Valid_Rows[i];   
        for(j=1;j<=the_info.valid_col_num;j++)   
        {   
              col = the_info.Valid_Cols[j];   
              if(the_info.C[row][col] < smallest)   
                 smallest = the_info.C[row][col];   
        }   
        if(smallest==INF)   
            return -1;   
        else    if(smallest!=0)   
        {   
                    for(j=1;j<=the_info.valid_col_num;j++)   
                    {   
                        col = the_info.Valid_Cols[j];   
                        if(the_info.C[row][col]!=INF)   
                            the_info.C[row][col] = the_info.C[row][col] - smallest;   
                    }   
                the_info.current_bound = the_info.current_bound + smallest;   
        }   
    }   
   
    for(j=1;j<=the_info.valid_col_num;j++)   
    {   
        smallest = INF;   
        col = the_info.Valid_Cols[j];   
        for(i=1;i<=the_info.valid_row_num;i++)   
        {   
              row = the_info.Valid_Rows[i];   
              if(the_info.C[row][col] < smallest)   
                 smallest = the_info.C[row][col];   
        }   
        if(smallest==INF)   
            return -1;   
        else if(smallest!=0)   
        {   
                for(i=1;i<=the_info.valid_row_num;i++)   
                {   
                    row = the_info.Valid_Rows[i];   
                    if(the_info.C[row][col]!=INF)   
                            the_info.C[row][col] = the_info.C[row][col] - smallest;   
                }   
                the_info.current_bound = the_info.current_bound + smallest;    
        }   
    }   
     return 1;   
   
}   
   
int find_new_edge(InfoType & the_info,EdgeType & new_edge)   
{   
    int row_smaller[N];   
    int col_smaller[N];   
    int i,j,smallest,row,col;   
    int biggest,current,counter;   
   
    //只剩下一条边，且这条边不可能为INF，因为若为INF，之前的set_zeros应该已经返回-1了   
    if(the_info.valid_row_num==1 && the_info.valid_col_num==1)   
    {   
        new_edge.start = the_info.Valid_Rows[1];   
        new_edge.end = the_info.Valid_Cols[1];   
        new_edge.excluded_cost = 0;   
        return 1;   
    }   
    //找到各有效行中第二小元素，若为INF，返回-1；否则记录在row_smaller的对应位置中   
    for(i=1;i<=the_info.valid_row_num;i++)   
    {   
           
        row = the_info.Valid_Rows[i];   
        smallest = INF;   
        counter = 0; //变量counter记录该行中0元素的个数   
        for(j=1;j<=the_info.valid_col_num;j++)   
        {   
                 
              col = the_info.Valid_Cols[j];   
              if(the_info.C[row][col] >0 && the_info.C[row][col] < smallest)   
                 smallest = the_info.C[row][col];   
              else if(the_info.C[row][col]==0)   
              {   
                    counter++;   
                    if(counter==2)   
                    {   
                        smallest = 0;   
                        break;   
                    }   
              }   
        }   
        //if(smallest=INF)   
        //  return -1;   
        row_smaller[row] = smallest;   
   
    }   
     //找到各有效列中第二小元素，若为INF，返回-1；否则记录在col_smaller的对应位置中   
    for(j=1;j<=the_info.valid_col_num;j++)   
    {   
           
        col = the_info.Valid_Cols[j];   
        smallest = INF;   
        counter = 0; // //变量counter记录该行中0元素的个数   
        for(i=1;i<=the_info.valid_row_num;i++)   
        {   
              row = the_info.Valid_Rows[i];   
              if(the_info.C[row][col] >0 && the_info.C[row][col] < smallest)   
                 smallest = the_info.C[row][col];   
              else if(the_info.C[row][col]==0)   
              {   
                    counter++;   
                    if(counter==2)   
                    {   
                        smallest = 0;   
                        break;   
                    }   
              }   
        }   
        //if(smallest=INF)   
        //  return -1;   
        col_smaller[col] = smallest;   
    }   
    //遍历有效数组C，对每一个0元素，求得对应行列的第二小元素之和，使之最大,这条边即为新选的边new_edge   
    biggest = -1;   
    for(i=1;i<=the_info.valid_row_num;i++)   
    {   
        row = the_info.Valid_Rows[i];   
        for(j=1;j<=the_info.valid_col_num;j++)   
        {   
             col = the_info.Valid_Cols[j];   
             if(the_info.C[row][col]==0)   
             {   
                 current = row_smaller[row] + col_smaller[col];   
                 if(current>biggest)   
                 {   
                     biggest = current;   
                     new_edge.start = row;   
                     new_edge.end = col;   
                     new_edge.excluded_cost = biggest;   
                 }   
             }   
        }   
    }   
    return 1;   
}   
   
void set_valid_row(InfoType & info,EdgeType new_edge)   
{   
    int row,col,i,j;   
    row = new_edge.start;   
    col = new_edge.end;   
    for(i=1;i<=info.valid_row_num;i++)   
        if(info.Valid_Rows[i] == row)   
        {   
            for(j=i+1;j<=info.valid_row_num;j++)   
                info.Valid_Rows[j-1] = info.Valid_Rows[j];   
            info.valid_row_num = info.valid_row_num - 1;   
        }   
    for(i=1;i<=info.valid_col_num;i++)   
        if(info.Valid_Cols[i] == col)   
        {   
            for(j=i+1;j<=info.valid_col_num;j++)   
                info.Valid_Cols[j-1] = info.Valid_Cols[j];   
            info.valid_col_num = info.valid_col_num - 1;   
        }   
 }   
   
   
int check_ok(InfoType & info)   
{   
    if(info.current_bound > best_bound)   
        return 0;   
    return 1;   
}   
   
   
   
void print(InfoType & info)   
{   
    int i,j,row,col;   
   
    cout << "矩阵C的内容如下：\n\t";   
    for(j=1;j<=info.valid_col_num;j++)   
        cout << info.Valid_Cols[j] << '\t';   
       
    cout << endl;   
   
    for(i=1;i<=info.valid_row_num;i++)   
    {   
           
        row = info.Valid_Rows[i];   
        cout << row << '\t';   
        for(j=1;j<=info.valid_col_num;j++)   
        {   
            col = info.Valid_Cols[j];   
            if(info.C[row][col]==INF)   
                cout << "INF\t";   
            else   
                cout << info.C[row][col] << '\t';   
        }   
        cout << endl;   
    }   
    if(info.edge_num>0)   
    {   
        cout << "已选边如下：" ;   
        for(i=1;i<=info.edge_num;i++)   
            cout << info.edges[i].start << "->" << info.edges[i].end << ",";   
    }   
    cout << "目前代价如下：" << info.current_bound << endl;   
   
}   
   
   
   
void find_optimal_solution(InfoType & info)   
{   
    int i,t;   
    EdgeType new_edge;   
    InfoType back_info;   
       
    t = set_zeros(info);   
    if(t==-1)   
    {   
        cout << "空集，停止扩展！\n";   
        return;   
    }   
    find_new_edge(info,new_edge);   
    back_info = info; //back_info目的为了不包括new_edge子树的扩展   
    back_info.current_bound = back_info.current_bound + new_edge.excluded_cost;   
   
   
    //包括new_edge边集合的处理   
    //将new_edge对应行和列从Valid_Row、Valid_Col集合中删除   
    set_valid_row(info,new_edge);   
    info.edges[info.edge_num+1] = new_edge;   
    info.edge_num = info.edge_num + 1;   
    info.C[new_edge.end][new_edge.start] = INF;   
    t = set_zeros(info);   
    if(t==-1)   
    {   
        cout << "已选边如下：" ;   
        for(i=1;i<=info.edge_num;i++)   
            cout << info.edges[i].start << "->" << info.edges[i].end << ",";   
        cout << new_edge.start << "->" << new_edge.end ;   
        cout << "=>这是一个空集，停止扩展！\n";   
        return;   
    }   
    print(info);   
    getchar();   
    if(!check_ok(info))   
    {   
        for(i=1;i<=info.edge_num;i++)   
            cout << info.edges[i].start << "->" << info.edges[i].end << ",";   
        cout << "info.current_bound=" << info.current_bound << "停止扩展！\n";   
        return;   
    }   
    else   
    {   
        if(info.edge_num==N-1)   
        {   
            best_bound = info.current_bound;   
            for(i=1;i<N;i++)   
                best_solution[i] = info.edges[i];   
        }   
        else   
            find_optimal_solution(info);  //递归调用，包括该边   
    }   
   
   
    //不包括new_edge边集合的处理   
    back_info.C[new_edge.start][new_edge.end] = INF;   
    if(back_info.current_bound>=INF )   
    {   
        cout << "已选边如下：" ;   
        for(i=1;i<=back_info.edge_num;i++)   
            cout << back_info.edges[i].start << "->" << back_info.edges[i].end << ",";   
        cout << "不包括" << new_edge.start << "->" << new_edge.end;   
        cout << "=>这是一个空集，停止扩展！\n";   
        return;   
    }   
    if(back_info.current_bound>best_bound)   
    {   
        print(back_info);   
        for(i=1;i<=back_info.edge_num;i++)   
            cout << back_info.edges[i].start << "->" << back_info.edges[i].end << ",";   
        cout << "back_info.current_bound=" << back_info.current_bound << "停止扩展！\n";   
        getchar();   
        return;   
   
    }   
    print(back_info);   
    getchar();   
    t = set_zeros(back_info);   
    if(t==-1)   
    {   
        cout << "已选边如下：" ;   
        for(i=1;i<=back_info.edge_num;i++)   
            cout << back_info.edges[i].start << "->" << back_info.edges[i].end << ",";   
        cout << "不包括" << new_edge.start << "->" << new_edge.end;   
        cout << "=>这是一个空集，停止扩展！\n";       
   
        getchar();   
    }   
    if(!check_ok(back_info))   
    {   
        for(i=1;i<=back_info.edge_num;i++)   
            cout << back_info.edges[i].start << "->" << back_info.edges[i].end << ",";   
        cout << "back_info.current_bound=" << back_info.current_bound << "停止扩展！\n";   
        getchar();   
        return;   
    }   
    else   
        find_optimal_solution(back_info); //递归调用，不包括该边   
}  
