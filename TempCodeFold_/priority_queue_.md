priority_queue 对于基本类型的使用方法相对简单。他的模板声明带有三个参数，priority_queue<Type, Container, Functional>
Type 为数据类型， Container 为保存数据的容器，Functional 为元素比较方式。
Container 必须是用数组实现的容器，比如 vector, deque 但不能用 list.
STL里面容器默认用的是 vector. 比较方式默认用 operator< , 所以如果你把后面俩个参数 缺省的话，优先队列就是大顶堆，队头元素最大。
看例子
[cpp] view plain copy
#include <iostream>  
#include <queue>  
using namespace std;  
int main(){  
    priority_queue<int,vector<int>,less<int> >q;//使用priority_queue<int> q1;一样  
    for(int i=0;i<10;i++)   
        q1.push(i);  
    while(!q1.empty()){  
        cout<<q1.top()<< endl;  
        q1.pop();  
    }  
    return 0;  
}  
如果要用到小顶堆，则一般要把模板的三个参数都带进去。
STL里面定义了一个仿函数 greater<>，对于基本类型可以用这个仿函数声明小顶堆
例子:
[cpp] view plain copy
#include <iostream>  
#include <queue>  
using namespace std;  
int main(){  
    priority_queue<int,vector<int>,greater<int> >q;  
    for(int i=0;i<10;i++)   
        q.push(i);  
    while(!q.empty()){  
        cout<<q.top()<< endl;  
        q.pop();  
    }  
    return 0;  
}  
对于自定义类型，则必须自己重载 operator< 或者自己写仿函数先看看例子:  //<> 结果不同，< 小的在顶，>大的在顶
[cpp] view plain copy
#include <iostream>  
#include <queue>  
using namespace std;  
struct Node{  
    int x, y;  
}node;  
 bool operator<( Node a, Node b){  
    if(a.x==b.x) return a.y>b.y;  
    return a.x>b.x;  
}  
 int main(){  
    priority_queue<Node>q;  
    for(int i=0;i<10;i++){  
        node.x=i;  
        node.y=10-i/2;  
        q.push(node);  
    }     
    while(!q.empty()){  
        cout<<q.top().x <<' '<<q.top().y<<endl;  
        q.pop();  
    }  
    return 0;  
}  


自定义类型重载 operator< 后，声明对象时就可以只带一个模板参数。
此时不能像基本类型这样声明priority_queue<Node, vector<Node>, greater<Node> >;
原因是 greater<Node> 没有定义，如果想用这种方法定义
则可以按如下方式
例子:（个人喜欢这种方法，因为set的自定义比较函数也可以写成这种形式）
[cpp] view plain copy
#include <iostream>  
#include <queue>  
using namespace std;  
struct Node{  
    int x, y;  
}node;  
struct cmp{  
    bool operator()(Node a,Node b){  
        if(a.x==b.x) return a.y>b.y;  
        return a.x>b.x;}  
};  
  
 int main(){  
    priority_queue<Node,vector<Node>,cmp>q;  
    for(int i=0;i<10;i++){  
        node.x=i;  
        node.y=10-i/2;  
        q.push(node);     
    }     
    while(!q.empty()){  
        cout<<q.top().x<<' '<<q.top().y<<endl;  
        q.pop();  
    }  
    return 0;  
}  
