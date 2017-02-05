   
#include <tchar.h>   
#include"queue"   
#include"vector"   
#include"iostream"   
   
template<class T>   
class AdjacencyWDigraph   
{   
    #define NoEdge 99999999     //定义最大数   
    public:   
    int BBTSP(int v[]);   
    int n;   
    T **a;   
 AdjacencyWDigraph(T*b,int num);   
~AdjacencyWDigraph()   
{   
    for(int i=0;i<n+1;i++)   
        delete a[i];   
    delete []a;   
}   
   
private:   
        class MinHeapNode   
        {   
        public:   
            int *x;   
            int s;   
            T cc;   
            T lcost;   
            T rcost;   
        };   
        class CompareMin   
        {   
        public :   
            bool operator()(const MinHeapNode& x,const MinHeapNode &y)const   
            {   
                return (x.lcost>y.lcost);   
            }   
        };   
};   
template<class T>   
AdjacencyWDigraph<T>::AdjacencyWDigraph(T*b,int num)   
    {   
    n=num;   
       
        a=new T*[n+1];   
        for(int i=0;i<n+1;i++)   
            a[i]=new T[n+1];   
           
        for(int i=1;i<=n;i++)   
        {   
            for(int j=1;j<=n;j++)   
            {   
                a[i][j]=b[(i-1)*n+j-1];   
            }   
        }   
    }   
template<class T>   
int AdjacencyWDigraph<T>::BBTSP(int v[])//结果放在v[1]--------v[n]   
{// 旅行商问题的最小耗费分枝定界算法   
   using namespace std;   
   
    std::priority_queue <MinHeapNode,std::vector<MinHeapNode>,CompareMin> H;   
    T * MinOut = new T [n+1];   
   
// 计算MinOut[i] = 离开顶点i的最小耗费边的耗费   
T MinSum = 0; // 离开顶点i的最小耗费边的数目   
for (int i = 1; i <= n; i++)   
{   
     T Min = NoEdge;   
for (int j = 1; j <= n; j++)   
if (a[i][j] != NoEdge &&(a[i][j] < Min || Min == NoEdge))   
               Min = a[i][j];   
if (Min == NoEdge) return NoEdge; // 此路不通   
MinOut[i] = Min;   
MinSum += Min;   
}   
// 把E-节点初始化为树根   
MinHeapNode E;   
E.x = new int [n];   
for (i = 0; i < n; i++)   
E.x[i] = i + 1;   
E.s = 0; // 局部旅行路径为x [ 1 : 0 ]   
E.cc = 0; // 其耗费为0   
E.rcost = MinSum;   
T bestc = NoEdge; // 目前没有找到旅行路径   
// 搜索排列树   
while (E.s < n - 1)    
{       // 不是叶子   
    if (E.s == n - 2)    
   {  // 叶子的父节点   
     // 通过添加两条边来完成旅行   
     // 检查新的旅行路径是不是更好   
         if (a[E.x[n-2]][E.x[n-1]] != NoEdge && a[E.x[n-1]][1] != NoEdge && (E.cc +   
             a[E.x[n-2]][E.x[n-1]] + a[E.x[n-1]][1] < bestc || bestc == NoEdge))    
         {   
               // 找到更优的旅行路径   
           bestc = E.cc + a[E.x[n-2]][E.x[n-1]] + a[E.x[n-1]][1];   
              E.cc = bestc;   
            E.lcost = bestc;   
            E.s++ ;   
           H.push(E);   
         }   
          else    
          {   
              delete [] E.x;    
          }   
    }   
    else    
    {           // 产生孩子   
           for (int i = E.s + 1; i < n; i++)   
          if (a[E.x[E.s]][E.x[i]] != NoEdge)   
          {   
              // 可行的孩子, 限定了路径的耗费   
               T cc = E.cc + a[E.x[E.s]][E.x[i]];   
               T rcost = E.rcost - MinOut[E.x[E.s]];   
               T b = cc + rcost; //下限   
               if (b < bestc || bestc == NoEdge)    
               {   
                   // 子树可能有更好的叶子   
                   // 把根保存到最xiao堆中   
                     MinHeapNode N;   
                     N.x = new int [n];   
                   for (int j = 0; j < n; j++)   
                        N.x[j] = E.x[j];   
                   N.x[E.s+1] = E.x[i];   
                   N.x[i] = E.x[E.s+1];   
                     N.cc = cc;   
                     N.s = E.s + 1;   
                   N.lcost = b;   
                   N.rcost = rcost;   
                     H.push(N) ;   
               }   
   
          } // 结束可行的孩子   
   
             delete [] E.x;   
      } // 对本节点的处理结束   
   
        if(!H.empty())   
         {   
             E=H.top();   
             H.pop();   
         }   
          else    
                break;   
}   
      if (bestc == NoEdge) return NoEdge; // 没有旅行路径   
          // 将最优路径复制到v[1:n] 中   
            for (i = 0; i < n; i++)   
                v[i+1] = E.x[i];   
           while (true)    
          {   
                // 释放最小堆中的所有节点   
               delete [] E.x;   
               if(!H.empty())   
              {    
                       E=H.top();   
                       H.pop();   
               }   
                   else   
                    break;   
           }   
         delete []MinOut;   
           return bestc;   
}   
   
int _tmain(int argc, _TCHAR* argv[])   
{   
int b[8][8]=   
        {   
    0,  8   ,5  ,9  ,12,    13  ,12,17  ,   
    8,  0   ,8  ,15 ,17 ,7  ,11 ,14 ,   
    5,  8   ,0, 7,  9   ,10 ,7  ,12 ,   
    9   ,15,    7   ,0, 3,  17, 11  ,16 ,   
    12, 17  ,9, 3,  0,  18  ,11,    15  ,   
    13  ,7  ,10 ,17 ,18 ,0  ,8, 8   ,   
    12, 11, 7,  11  ,11,    8,  0,  5   ,   
    17, 14  ,12 ,16 ,15 ,8  ,5, 0      
        };   
      AdjacencyWDigraph <int>t(&b[0][0],8);   
        int v[10];   
        std::cout<<t.BBTSP(v)<<std::endl;   
        for(int i=1;i<8+1;i++)   
            std::cout<<v[i]<<" ";   
    return 0;   
}   
