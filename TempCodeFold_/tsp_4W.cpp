// liao.cpp : 定义控制台应用程序的入口点。   
//   
   
#include "stdafx.h"   
#include <iostream>   
#include <queue>   
#include <stack>   
using namespace std;   
#define L 3   //结点号码   
#define N 5   //结点个数   
/****************************分枝界线方法代码*************************************/   
class Node   //生成树节点类   
{   
private:   
    int site;//该节点在图中的点   
    int sign[2][N];//sign[0][i]和sign[1][i]分别表示i行及列零元素的个数判断是否规约该行和列   
    int sign1[2][N];//sign1[0][i]和sign1[1][i]如果为真表示i行和列已经被删除   
    int c[N][N];//规约后的矩阵   
public:   
    int path[N];//路径数组，从父结点继承而来。表示路径在第path[i]-1层走的路径为图中i点   
    int layer; //该节点属于树的第几层   
    int band;//界限值   
    Node(int k,int A[N][N],int n)//用于树第一节点的构造函数   
    {    
        for(int i=0;i<2;i++) //数组sign、sign1的初始化   
            for(int j=0;j<N;j++)   
            {   
                sign[i][j]=0;   
                sign1[i][j]=0;   
            }   
            layer=n;    
            band=0;   
            site=k;   
            for(i=0;i<N;i++) //路径初始化   
                path[i]=0;         
            path[site]=layer+1;//路径第一点   
            copy(c,A);    
            guiyue();//规约矩阵   
    }   
    Node(int k,Node A)//非根节点构造函数   
    {     
        copy(sign,A.sign);//从父结点继承   
        copy(sign1,A.sign1);//从父结点继承   
        layer=A.layer+1;//层次增加一层   
        site=k;   
        copy(c,A.c);   
        band=A.band+c[A.site][site];//修改界限   
        copy(path,A.path);   
            path[site]=layer+1;   
            //以下为删除当前行，并修改标志   
            for(int i=0;i<N;i++)   
            {     
                if(!c[A.site][i])   
                {   
                    sign[0][A.site]--;   
                    sign[1][i]--;   
                }   
                c[A.site][i]=1000;   
            }   
            sign1[0][A.site]=1;   
            //以下为删除当前列，并修改标志   
            for(i=0;i<N;i++)   
            {     
                if(!c[i][site])   
                {   
                    sign[0][i]--;   
                    sign[1][site]--;   
                }   
                c[i][site]=1000;   
            }   
            sign1[1][site]=1;   
            //没有达到最后一层修改[site][L-1]的值   
            if(layer!=4)   
            {   
                if(!c[site][L-1])   
                {   
                    sign[0][site]--;   
                    sign[1][L-1]--;   
                }   
                c[site][L-1]=1000;   
            }   
            guiyue();//规约矩阵   
    }   
    void guiyue()   
    {   
        //行规约，并修改相应标志   
        for(int i=0;i<N;i++)   
            if(!sign1[0][i]&&!sign[0][i])   
            {   
                int m=lmin(i,c);   
                band=band+m;   
                for(int j=0;j<N;j++)   
                {   
                    c[i][j]=c[i][j]-m;   
                    if(!c[i][j])   
                    {   
                        sign[0][i]++;   
                        sign[1][j]++;   
                    }   
                }   
            }   
            //列规约，并修改相应标志   
            for(int i=0;i<N;i++)   
                if(!sign1[1][i]&&!sign[1][i])   
                {   
                    int m=cmin(i,c);   
                    band=band+m;   
                    for(int j=0;j<N;j++)   
                    {   
                        c[j][i]=c[j][i]-m;   
                        if(!c[j][i])   
                        {   
                            sign[0][j]++;   
                            sign[1][i]++;   
                        }   
                    }   
                }   
    }   
    //拷贝数组函数   
    void copy(int A[N],int B[N])   
    {   
        for(int i=0;i<N;i++)   
            A[i]=B[i];   
    }   
    //拷贝二维数组函数   
    void copy(int A[N][N],int B[N][N])   
    {   
        for(int i=0;i<N;i++)   
            for(int j=0;j<N;j++)   
                A[i][j]=B[i][j];   
    }   
    //返回当前列最小值   
    int lmin(int i,int A[N][N])   
    {   
        int min=A[i][0];   
        for(int j=0;j<N;j++)   
            if(min>A[i][j])   
                min=A[i][j];   
        return min;   
    }   
    //返回当前行最小值   
    int cmin(int i,int A[N][N])   
    {   
        int min=A[0][i];   
        for(int j=0;j<N;j++)   
            if(min>A[j][i])   
                min=A[j][i];   
        return min;   
    }   
    //重载符号函数   
    bool operator < (const Node &B)const   
     {   
         return band>B.band;   
     }   
};   
//输出路径函数   
void Generate(int k,int A[N][N],int n)   
{   
    priority_queue <Node> Q;//优先队列   
    Q.push(Node(k,A,n));   
    while(!Q.empty())   
    {   
        Node p = Q.top();   
        if(p.layer==4)   
        {    
            cout<<"分枝界线方法结果："<<endl;   
            cout<<p.band<<endl;   
            int b[N];   
            for(int i=0;i<N;i++)   
                b[p.path[i]-1]=i;//映射路径   
            cout<<"The path is:"<<endl;   
            for(int i=0;i<N;i++)   
                cout<<b[i]+1<<"-->";   
            cout<<L<<endl;;   
            return;   
        }   
        Q.pop();   
        for(int i=0;i<N;i++)   
            if(!p.path[i])   
                Q.push(Node(i,p));   
    }   
}   
/****************************动态规划方法代码*************************************/   
struct node   
{   
    int a;   
    int b;   
    int layer;   
    node(int m,int n,int l)   
    {   
        a=m;   
        b=n;   
        layer=l;   
    }   
};   
class Trend   
{   
private:   
    stack<node> path;   
    int c[N][N];   
    int sign[N],sign2[N];   
public:   
    Trend(int b[N][N])   
    {    
        for(int i=0;i<N;i++)   
            for(int j=0;j<N;j++)   
            {   
                sign[i]=0;   
                c[i][j]=b[i][j];   
            }   
         sign[L-1]=1;   
    }   
    int optpath(int j,int n,int sign[N])   
    {      
        int min=0;   
        if(n==1)   
        {     
            path.push(node(j,L-1,1));   
            return c[j][L-1];   
        }   
        else    
           if(n<=0)   
               return 1000;   
        for(int k=0,i=0;i<N;i++)   
        {   
            int y=0;   
            if(!sign[i])   
            {    
                sign[i]=1;   
                y=1;   
                int sign3[N];    
                copy(sign3,sign);   
                int m=optpath(i,n-1,sign3);   
                if(!k&&c[j][i])   
                {     
                    path.push(node(j,i,n));   
                    min=c[j][i]+m;   
                    k=1;   
                }   
                else    
                    if(k&&c[j][i]&&min>=c[j][i]+m)   
                    {   
                         min=c[j][i]+m;   
                         path.push(node(j,i,n));   
                     }   
                    if(y)sign[i]=0;   
            }   
        }   
        return min;   
    }   
    void prin()   
    {     
        cout<<"动态规划方法结果："<<endl;   
        cout<<optpath(L-1,N,sign)<<endl;   
        cout<<"The  path  is :"<<endl;   
        int l=N,begin=L;   
        cout<<L;   
        while(!path.empty())   
        {     
            node k=path.top();   
            if(k.a+1==begin&&k.layer==l)   
            {     
                begin=k.b+1;   
                cout<<"-->"<<k.b+1;   
                l=l-1;   
            }   
            path.pop();   
        }   
        cout<<endl;   
    }   
    void copy(int a[N],int b[N])   
    {   
        for(int i=0;i<N;i++)   
            a[i]=b[i];   
   }   
};   
/****************************回溯方法代码*************************************/   
class Retrace   
{   
private:   
    int min;   
    int fpath[N],tpath[N];   
    int c[N][N];   
    int k;   
public:   
    Retrace(int b[N][N])   
    {       
        k=0;   
        for(int i=0;i<N;i++)   
        {     
            fpath[i]=-1;   
            for(int j=0;j<N;j++)   
                c[i][j]=b[i][j];   
        }   
        min=1000;   
    }   
    void  optpath(int n ,int lon)   
    {     
       if(n==N)   
       {     
           if(fpath[N-1]==L-1&& min>long1())   
           {      
               min=long1();   
               for(int i=0;i<N;i++)   
               tpath[i]=fpath[i];   
           }   
       }   
       else if(n==0)   
       {   
           for(int i=0;i<N;i++)   
           {    
               fpath[n]=i;   
               optpath(n+1,lon);   
               fpath[n]=-1;   
           }   
       }   
       else    
       for(int i=0;i<N;i++)   
       {     
           int lon1=lon+c[fpath[n-1]][i];   
           if(!uninclude(i)&&lon1<min)   
           {   
               fpath[n]=i;   
               optpath(n+1,lon1);   
               fpath[n]=-1;   
           }   
           lon=lon-c[fpath[n-1]][fpath[n]];   
       }   
    }   
    int long1()   
    {   
        for(int min1=0,j=L-1,i=0;i<N;i++)   
        {   
            min1=min1+c[j][fpath[i]];   
            j=fpath[i];   
        }   
        return min1;   
    }   
    void prin()   
    {   
       cout<<"回溯方法结果："<<endl;   
       cout<<min<<endl;   
       cout<<"The path is:"<<endl;;   
       cout<<L;   
       for(int i=0;i<N;i++)   
           cout<<"-->"<<tpath[i]+1;   
       cout<<endl;   
    }   
    int uninclude(int n)   
    {   
       for(int i=0;i<N&&fpath[i]>=0;i++ )   
           if(fpath[i]==n)   
               return 1;   
       return 0;   
    }   
};   
/****************************枚举方法代码*************************************/   
class Enumerate   
{   
private:   
    int min;   
    int fpath[N],tpath[N];   
    int c[N][N];   
    int k;   
public:   
    Enumerate(int b[N][N])   
    {      
        k=0;   
        for(int i=0;i<N;i++)   
        {      
            fpath[i]=-1;   
           for(int j=0;j<N;j++)   
           c[i][j]=b[i][j];   
        }   
    }   
    void  optpath(int n)   
    {     
        if(n==N)   
        {    
            if(!k&&fpath[N-1]==L-1)   
            {   
                k=1;   
                min=long1();   
                for(int i=0;i<N;i++)   
                    tpath[i]=fpath[i];   
            }   
            if(k&&fpath[N-1]==L-1&& min>long1())   
            {      
                min=long1();   
                for(int i=0;i<N;i++)   
                    tpath[i]=fpath[i];   
            }   
        }   
        for(int i=0;i<N;i++)   
        {    
            if(!uninclude(i))   
            {   
                fpath[n]=i;   
                optpath(n+1);   
                fpath[n]=-1;   
            }   
        }   
    }   
    int long1()   
    {   
        for(int min=0,j=L-1,i=0;i<N;i++)   
        {   
            min=min+c[j][fpath[i]];   
            j=fpath[i];   
        }   
        return min;   
    }   
   void prin()   
   {   
       cout<<"枚举方法结果："<<endl;   
       cout<<min<<endl;   
       cout<<"The path is:"<<endl;;   
       cout<<L;   
       for(int i=0;i<N;i++)   
           cout<<"-->"<<tpath[i]+1;   
   }   
   int uninclude(int n)   
   {   
       for(int i=0;i<N&&fpath[i]>=0;i++ )   
           if(fpath[i]==n) return 1;   
       return 0;   
   }   
};   
   
void main()   
{      
    int A[5][5]={{1000,20,30,10,11},{15,1000,16,4,2},{3,5,1000,2,4},{19,6,18,1000,3},{15,4,7,16,1000}};   
/****************************分枝界线方法代码*************************************/   
    Generate(L-1,A,0);   
/****************************动态规划方法代码*************************************/   
    Trend path1(A);   
    path1.prin();   
/****************************回溯方法代码*************************************/   
    Retrace Retrace1(A);   
    Retrace1.optpath(0,0);   
    Retrace1.prin();   
/****************************枚举方法代码*************************************/   
    Enumerate  Enum(A);   
    Enum.optpath(0);   
    Enum.prin();   
    cin.get();   
    return;   
}   
   
