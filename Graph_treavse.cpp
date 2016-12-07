
登录 | 注册
登录 | 注册
TODD911的专栏
夯实基础，循序渐进

目录视图摘要视图订阅
聚焦行业最佳实践，BDTC 2016完整议程公布        Java 编程入门（系列）        程序员11月书讯，评论得书啦        Get IT技能知识库，50个领域一键直达
关闭
 图之图的深度优先遍历
2016-11-25 23:15 38518人阅读 评论(15) 收藏 举报
 分类： 算法（22）  
版权声明：本文为博主原创文章，未经博主允许不得转载。
深度优先遍历是连通图的一种遍历策略。其基本思想如下：
设x是当前被访问顶点，在对x做过访问标记后，选择一条从x出发的未检测过的边(x，y)。若发现顶点y已访问过，则重新选择另一条从x出发的未检测过的边，否则沿边(x，y)到达未曾访问过的y，对y访问并将其标记为已访问过；然后从y开始搜索，直到搜索完从y出发的所有路径，即访问完所有从y出发可达的顶点之后，才回溯到顶点x，并且再选择一条从x出发的未检测过的边。上述过程直至从x出发的所有边都已检测过为止。
例如下图中：

1.从0开始，首先找到0的关联顶点3
2.由3出发，找到1；由1出发，没有关联的顶点。
3.回到3，从3出发，找到2；由2出发，没有关联的顶点。
4.回到4，出4出发，找到1，因为1已经被访问过了，所以不访问。
所以最后顺序是0,3,1,2,4
c语言实现如下：（使用邻接矩阵存储）
[cpp] view plain copy
#include <stdio.h>  
#include <malloc.h>  
#define VERTEXNUM 5  
  
void createGraph(int (*edge)[VERTEXNUM], int start, int end);  
void displayGraph(int (*edge)[VERTEXNUM]);  
void DFT(int (*edge)[VERTEXNUM],int* vertexStatusArr);  
void DFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr);  
  
int main(void){  
        //动态创建存放边的二维数组  
        int (*edge)[VERTEXNUM] = (int (*)[VERTEXNUM])malloc(sizeof(int)*VERTEXNUM*VERTEXNUM);  
        int i,j;  
        for(i=0;i<VERTEXNUM;i++){  
                for(j=0;j<VERTEXNUM;j++){  
                        edge[i][j] = 0;  
                }  
        }  
        //存放顶点的遍历状态，0：未遍历，1：已遍历    
        int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);  
        for(i=0;i<VERTEXNUM;i++){  
                vertexStatusArr[i] = 0;  
        }  
          
        printf("after init:\n");  
        displayGraph(edge);  
        //创建图  
        createGraph(edge,0,3);  
        createGraph(edge,0,4);  
        createGraph(edge,3,1);  
        createGraph(edge,3,2);  
        createGraph(edge,4,1);  
  
        printf("after create:\n");  
        displayGraph(edge);  
        //深度优先遍历  
        DFT(edge,vertexStatusArr);  
  
        free(edge);  
        return 0;  
}  
//创建图   
void createGraph(int (*edge)[VERTEXNUM], int start, int end){  
        edge[start][end] = 1;  
}  
//打印存储的图  
void displayGraph(int (*edge)[VERTEXNUM]){  
        int i,j;  
        for(i=0;i<VERTEXNUM;i++){  
                for(j=0;j<VERTEXNUM;j++){  
                        printf("%d ",edge[i][j]);  
                }  
                printf("\n");  
        }  
}  
//深度优先遍历  
void DFT(int (*edge)[VERTEXNUM], int* vertexStatusArr){  
        printf("start BFT graph:\n");  
        int i;  
        for(i=0;i<VERTEXNUM;i++){  
                DFTcore(edge,i,vertexStatusArr);  
        }  
        printf("\n");  
}  
void DFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr){  
        if(vertexStatusArr[i] == 1){  
                return;  
        }  
        printf("%d ",i);  
        vertexStatusArr[i] = 1;  
  
        int j;  
        for(j=0;j<VERTEXNUM;j++){  
                if(edge[i][j] == 1){  
                        DFTcore(edge, j, vertexStatusArr);  
                }  
        }  
}  
[cpp] view plain copy
#include <stdio.h>  
#include <malloc.h>  
#define VERTEXNUM 5  
  
void createGraph(int (*edge)[VERTEXNUM], int start, int end);  
void displayGraph(int (*edge)[VERTEXNUM]);  
void DFT(int (*edge)[VERTEXNUM],int* vertexStatusArr);  
void DFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr);  
  
int main(void){  
        //动态创建存放边的二维数组  
        int (*edge)[VERTEXNUM] = (int (*)[VERTEXNUM])malloc(sizeof(int)*VERTEXNUM*VERTEXNUM);  
        int i,j;  
        for(i=0;i<VERTEXNUM;i++){  
                for(j=0;j<VERTEXNUM;j++){  
                        edge[i][j] = 0;  
                }  
        }  
        //存放顶点的遍历状态，0：未遍历，1：已遍历    
        int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);  
        for(i=0;i<VERTEXNUM;i++){  
                vertexStatusArr[i] = 0;  
        }  
          
        printf("after init:\n");  
        displayGraph(edge);  
        //创建图  
        createGraph(edge,0,3);  
        createGraph(edge,0,4);  
        createGraph(edge,3,1);  
        createGraph(edge,3,2);  
        createGraph(edge,4,1);  
  
        printf("after create:\n");  
        displayGraph(edge);  
        //深度优先遍历  
        DFT(edge,vertexStatusArr);  
  
        free(edge);  
        return 0;  
}  
//创建图   
void createGraph(int (*edge)[VERTEXNUM], int start, int end){  
        edge[start][end] = 1;  
}  
//打印存储的图  
void displayGraph(int (*edge)[VERTEXNUM]){  
        int i,j;  
        for(i=0;i<VERTEXNUM;i++){  
                for(j=0;j<VERTEXNUM;j++){  
                        printf("%d ",edge[i][j]);  
                }  
                printf("\n");  
        }  
}  
//深度优先遍历  
void DFT(int (*edge)[VERTEXNUM], int* vertexStatusArr){  
        printf("start BFT graph:\n");  
        int i;  
        for(i=0;i<VERTEXNUM;i++){  
                DFTcore(edge,i,vertexStatusArr);  
        }  
        printf("\n");  
}  
void DFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr){  
        if(vertexStatusArr[i] == 1){  
                return;  
        }  
        printf("%d ",i);  
        vertexStatusArr[i] = 1;  
  
        int j;  
        for(j=0;j<VERTEXNUM;j++){  
                if(edge[i][j] == 1){  
                        DFTcore(edge, j, vertexStatusArr);  
                }  
        }  
}  


C语言实现如下：（使用邻接表存储）
[cpp] view plain copy
#include <stdio.h>  
#include <malloc.h>  
#define VERTEXNUM 5  
//存放顶点的邻接表元素    
typedef struct edge{  
        int vertex;  
        struct edge* next;  
}st_edge;  
  
void createGraph(st_edge** edge, int start, int end);  
void displayGraph(st_edge** edge);  
void delGraph(st_edge** edge);  
void DFT(st_edge** edge,int* vertexStatusArr);  
void DFTcore(st_edge** edge,int i,int* vertexStatusArr);  
  
int main(void){  
        //动态创建存放边的指针数组     
        st_edge** edge = (st_edge**)malloc(sizeof(st_edge*)*VERTEXNUM);  
        int i;  
        for(i=0;i<VERTEXNUM;i++){  
                edge[i] = NULL;  
        }  
        //存放顶点的遍历状态，0：未遍历，1：已遍历    
        int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);  
        for(i=0;i<VERTEXNUM;i++){  
                vertexStatusArr[i] = 0;  
        }  
  
        printf("after init:\n");  
        displayGraph(edge);  
        //创建图    
        createGraph(edge,0,3);  
        createGraph(edge,0,4);  
        createGraph(edge,3,1);  
        createGraph(edge,3,2);  
        createGraph(edge,4,1);  
  
        printf("after create:\n");  
        displayGraph(edge);  
        //深度优先遍历   
        DFT(edge,vertexStatusArr);  
        //释放邻接表占用的内存    
        delGraph(edge);  
        edge = NULL;  
        free(vertexStatusArr);  
        vertexStatusArr = NULL;  
        return 0;  
}  
//创建图   
void createGraph(st_edge** edge, int start, int end){  
        st_edge* newedge = (st_edge*)malloc(sizeof(st_edge));  
        newedge->vertex = end;  
        newedge->next = NULL;  
        edge = edge + start;  
        while(*edge != NULL){  
                edge = &((*edge)->next);  
        }  
        *edge = newedge;  
}  
//打印存储的图   
void displayGraph(st_edge** edge){  
        int i;  
        st_edge* p;  
        for(i=0;i<VERTEXNUM;i++){  
                printf("%d:",i);  
                p = *(edge+i);  
                while(p != NULL){  
                        printf("%d ",p->vertex);  
                        p = p->next;  
                }  
                printf("\n");  
        }  
}  
//释放邻接表占用的内存   
void delGraph(st_edge** edge){  
        int i;  
        st_edge* p;  
        st_edge* del;  
        for(i=0;i<VERTEXNUM;i++){  
                p = *(edge+i);  
                while(p != NULL){  
                        del = p;  
                        p = p->next;  
                        free(del);  
                }  
                edge[i] = NULL;  
        }  
        free(edge);  
}  
//深度优先遍历   
void DFT(st_edge** edge,int* vertexStatusArr){  
        printf("start BFT graph:\n");  
        int i;  
        for(i=0;i<VERTEXNUM;i++){  
                DFTcore(edge,i,vertexStatusArr);  
        }  
        printf("\n");  
}  
  
void DFTcore(st_edge** edge,int i,int* vertexStatusArr){  
        if(vertexStatusArr[i] == 1){  
                return;  
        }  
        printf("%d ",i);  
        vertexStatusArr[i] = 1;  
        st_edge* p = *(edge+i);  
        while(p != NULL){  
                DFTcore(edge, p->vertex, vertexStatusArr);  
                p = p->next;  
        }  
}  
[cpp] view plain copy
#include <stdio.h>  
#include <malloc.h>  
#define VERTEXNUM 5  
//存放顶点的邻接表元素    
typedef struct edge{  
        int vertex;  
        struct edge* next;  
}st_edge;  
  
void createGraph(st_edge** edge, int start, int end);  
void displayGraph(st_edge** edge);  
void delGraph(st_edge** edge);  
void DFT(st_edge** edge,int* vertexStatusArr);  
void DFTcore(st_edge** edge,int i,int* vertexStatusArr);  
  
int main(void){  
        //动态创建存放边的指针数组     
        st_edge** edge = (st_edge**)malloc(sizeof(st_edge*)*VERTEXNUM);  
        int i;  
        for(i=0;i<VERTEXNUM;i++){  
                edge[i] = NULL;  
        }  
        //存放顶点的遍历状态，0：未遍历，1：已遍历    
        int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);  
        for(i=0;i<VERTEXNUM;i++){  
                vertexStatusArr[i] = 0;  
        }  
  
        printf("after init:\n");  
        displayGraph(edge);  
        //创建图    
        createGraph(edge,0,3);  
        createGraph(edge,0,4);  
        createGraph(edge,3,1);  
        createGraph(edge,3,2);  
        createGraph(edge,4,1);  
  
        printf("after create:\n");  
        displayGraph(edge);  
        //深度优先遍历   
        DFT(edge,vertexStatusArr);  
        //释放邻接表占用的内存    
        delGraph(edge);  
        edge = NULL;  
        free(vertexStatusArr);  
        vertexStatusArr = NULL;  
        return 0;  
}  
//创建图   
void createGraph(st_edge** edge, int start, int end){  
        st_edge* newedge = (st_edge*)malloc(sizeof(st_edge));  
        newedge->vertex = end;  
        newedge->next = NULL;  
        edge = edge + start;  
        while(*edge != NULL){  
                edge = &((*edge)->next);  
        }  
        *edge = newedge;  
}  
//打印存储的图   
void displayGraph(st_edge** edge){  
        int i;  
        st_edge* p;  
        for(i=0;i<VERTEXNUM;i++){  
                printf("%d:",i);  
                p = *(edge+i);  
                while(p != NULL){  
                        printf("%d ",p->vertex);  
                        p = p->next;  
                }  
                printf("\n");  
        }  
}  
//释放邻接表占用的内存   
void delGraph(st_edge** edge){  
        int i;  
        st_edge* p;  
        st_edge* del;  
        for(i=0;i<VERTEXNUM;i++){  
                p = *(edge+i);  
                while(p != NULL){  
                        del = p;  
                        p = p->next;  
                        free(del);  
                }  
                edge[i] = NULL;  
        }  
        free(edge);  
}  
//深度优先遍历   
void DFT(st_edge** edge,int* vertexStatusArr){  
        printf("start BFT graph:\n");  
        int i;  
        for(i=0;i<VERTEXNUM;i++){  
                DFTcore(edge,i,vertexStatusArr);  
        }  
        printf("\n");  
}  
  
void DFTcore(st_edge** edge,int i,int* vertexStatusArr){  
        if(vertexStatusArr[i] == 1){  
                return;  
        }  
        printf("%d ",i);  
        vertexStatusArr[i] = 1;  
        st_edge* p = *(edge+i);  
        while(p != NULL){  
                DFTcore(edge, p->vertex, vertexStatusArr);  
                p = p->next;  
        }  
}  







顶
16
踩
2
 
 
下一篇Eclipse配置Tomcat5.5步骤
我的同类文章

算法（22）
•图之Dijkstra算法2013-07-21阅读10265
•图之prim算法2013-07-03阅读6927
•图之图的存储2013-06-25阅读1334
•排序之bitmap排序2013-01-06阅读3087
•查找之hash查找2013-01-04阅读930
•图之kruskal算法2013-07-07阅读5559
•图之图的广度优先遍历2013-06-26阅读19159
•基于霍夫曼编码的任意文件压缩程序2013-03-27阅读2192
•查找之二叉树查找2013-01-06阅读15284
•查找之折半查找2012-12-28阅读963
更多文章
参考知识库

img
C语言知识库
5885关注|3439收录
猜你在找
4.7.存储类&作用域&生命周期&链接属性-C语言高级专题第7部分顾荣：开源大数据存储系统Alluxio（原Tachyon）的原理分析与案例简介C语言指针与汇编内存地址内存这个大话题-4.1.C语言高级专题第一部分C语言指针与汇编内存地址（二）
4.7.存储类&作用域&生命周期&链接属性-C语言高级专题第7部分顾荣：开源大数据存储系统Alluxio（原Tachyon）的原理分析与案例简介C语言指针与汇编内存地址内存这个大话题-4.1.C语言高级专题第一部分C语言指针与汇编内存地址（二）

 
查看评论
10楼 qq_33636637 2016-01-05 16:21发表 [回复]

请问楼主 如何邻接链表的深度优先遍历的方式来求无向图的连通分量
9楼 fwk084 2015-11-19 17:59发表 [回复]

邻接表那一个为啥在VC++6.0下运行不了啊？
8楼 liuhmmjj 2015-04-12 18:07发表 [回复]

楼主，请问深度优先搜索结果唯一吗
7楼 fengjiehua1991 2014-09-02 13:33发表 [回复]

请问一下，在用邻接表写的那段程序里面，在createGraph函数里面是用edge = edge + start; 
while(*edge != NULL){ 
edge = &((*edge)->next); 
} 
*edge = newedge;
这里的话，每次创建完了，edge数组的指针不就指向一个链表的结尾部分了吗？
Re: TODD911 2014-09-07 10:23发表 [回复]

回复fengjiehua1991：不是的，edge在该函数中是一个局部变量，我对edge的操作都是在执行edge = edge + start;之后进行的，不会影响edge数组的指针内容。如果我在函数一开始增加以下语句：
st_edge** point = edge;
在以后的语句中都使用point来代替edge，估计你会更容易理解。
Re: fengjiehua1991 2014-09-16 21:33发表 [回复]

回复TODD911：好的，我再看看，谢谢～！
6楼 Abren追忆 2014-07-17 16:37发表 [回复]

edge = edge + start; 
while(*edge != NULL){ 
edge = &((*edge)->next); 
} 
*edge = newedge;
其实还是有点不知道怎么理解
Re: TODD911 2014-07-21 13:16发表 [回复]

回复Abren追忆：要理解这个函数，你先要理解邻接表的构成，edge是一个数组，数组的元素是edge指针，这个指针可能会指向一个链表。不好意思，没有贴图，我找了一个帖子，上面有图，有一点区别是，我的是有向的，他的是无向的：http://blog.csdn.net/linxinyuluo/article/details/6847851
5楼 不想飞的天鹅 2014-05-25 10:48发表 [回复]

最后节点4 不相通的话 也可以写上去？还是有什么规律呢
Re: TODD911 2014-05-25 12:00发表 [回复]

回复不想飞的天鹅：不相通的话是连不上的。
4楼 Crystal74 2014-04-17 21:25发表 [回复]

自己琢磨出来了！呵呵
3楼 Crystal74 2014-04-17 20:36发表 [回复]

程序运行没有错误，很棒！可是怎样修改能从其他源点出发遍历呢？？急求解！！！
2楼 读读代码 2014-04-17 17:46发表 [回复]

邻接矩阵的好看。邻接表 那个不好看。
Re: TODD911 2014-04-17 19:41发表 [回复]

回复读读代码：好看是好看，但是浪费空间，:-)
1楼 读读代码 2014-04-17 14:37发表 [回复]

不错， 代码清晰。思路也清晰。谢谢。
您还没有登录,请[登录]或[注册]
* 以上用户言论只代表其个人观点，不代表CSDN网站的观点或立场
核心技术类目
全部主题 Hadoop AWS 移动游戏 Java Android iOS Swift 智能硬件 Docker OpenStack VPN Spark ERP IE10 Eclipse CRM JavaScript 数据库 Ubuntu NFC WAP jQuery BI HTML5 Spring Apache .NET API HTML SDK IIS Fedora XML LBS Unity Splashtop UML components Windows Mobile Rails QEMU KDE Cassandra CloudStack FTC coremail OPhone CouchBase 云计算 iOS6 Rackspace Web App SpringSide Maemo Compuware 大数据 aptech Perl Tornado Ruby Hibernate ThinkPHP HBase Pure Solr Angular Cloud Foundry Redis Scala Django Bootstrap
个人资料
 访问我的空间 
TODD911
 6  1
访问：728050次
积分：9612
等级： 
排名：第1386名
原创：256篇转载：106篇译文：4篇评论：161条
文章搜索

搜索
博客专栏
	GNU Make项目管理
文章：6篇
阅读：4470
	学习bash
文章：9篇
阅读：6788
	TCP/IP详解卷2：实现
文章：31篇
阅读：44662
	你必须知道的495个C语言问题
文章：8篇
阅读：9160
	TCP/IP详解卷1：协议
文章：6篇
阅读：14373
	UNIX环境高级编程
文章：78篇
阅读：131787
	数据通信与网络
文章：25篇
阅读：40347
	算法系列
文章：20篇
阅读：122057
文章分类
opendaylight(5)
openstack(1)
《GNU make项目管理》笔记(6)
《学习bash》笔记(9)
《软件调试的艺术》笔记(5)
《TCP/IP详解卷2：实现》笔记(31)
《你必须知道的495个C语言问题》笔记(8)
《TCP/IP详解卷1：协议》笔记(6)
《UNIX环境高级编程》笔记(78)
《数据通信与网络》笔记(25)
《c专家编程》笔记(12)
《c陷阱与缺陷》笔记(8)
《c和指针》笔记(20)
glibc manual(2)
linux管理(69)
网络(2)
linux安全(1)
C语言相关(45)
那些变态的面试题(2)
算法(23)
shell脚本(5)
android(2)
java语言相关(6)
EXCEL(1)
文章存档
2016年04月(1)
2016年03月(2)
2016年02月(2)
2016年01月(3)
2015年12月(1)
展开
阅读排行
图之图的深度优先遍历(38473)
Unix/Linux 脚本中 “set -e” 的作用(21882)
获取java byte的无符号数值(20821)
图之图的广度优先遍历(19251)
查找之二叉树查找(15307)
svn diff 与 patch(11631)
od命令(10512)
图之Dijkstra算法(10281)
centos-6.2安装完后没有eth0网卡，无法设置ip的解决方法(8456)
VMware Network Adapter VMnet1和VMnet8 未识别的网络的解决方法(8421)
评论排行
《c专家编程》笔记--如何使用赋值语句拷贝整个数组的值(17)
图之图的深度优先遍历(15)
获取java byte的无符号数值(8)
《c和指针》笔记--a++和++a不是变量(8)
排序之bitmap排序(7)
GCC编译提示显示乱码(7)
《UNIX环境高级编程》笔记--孤儿进程组(7)
查找之二叉树查找(6)
排序之冒泡排序(5)
centos6.3搭建iscsitarget存储服务器(5)
推荐文章
* 区块链的跨链技术介绍完整版
* Android插件化开发之Hook StartActivity方法
* 2016年11月前端面试题整理汇总
* 深入探讨Android异步精髓Handler
* 死磕 Fragment 的生命周期
最新评论
《数据通信与网络》笔记--数据链路层的差错控制协议
eiai115115: 讲的非常清楚，博主请问一下你这些图是自己做的吗，用的什么工具啊？
不要再被误导了，64位X86 CPU是没有64位寻址能力的！
csdnice: 原来是这样,看了很多教材总觉得有些不对劲一个是王爽的《汇编语言》
查找之二叉树查找
SidneyH: @SidneyH:哦，不好意思，最后free(node)和node = NULL连用是正确的。
查找之二叉树查找
SidneyH: createTree函数里的循环应该是i=0，i<size，不然运行结果是错的然后deleteTre...
图之Dijkstra算法
ldl897729862: .000
c实现输出二维蛇形矩阵
rhx_qiuzhi: error C2057: 应输入常量表达式1>d:\visual stdio 2010\visual...
排序之冒泡排序
LowKeyer: 参考你的代码我也写了冒泡排序的博客，http://www.weidublog.com/index.p...
查找之二叉树查找
疯丫头疯丫头: 代码有些错，运行不了
typedef定义函数类型
小比丘: 好文，顶上去
Unix/Linux 脚本中 “set -e” 的作用
baidu_34586346: 不添加点自己的理解又有什么意义呢

公司简介|招贤纳士|广告服务|联系方式|版权声明|法律顾问|问题报告|合作伙伴|论坛反馈
网站客服杂志客服微博客服webmaster@csdn.net400-600-2320|北京创新乐知信息技术有限公司 版权所有|江苏知之为计算机有限公司|江苏乐知网络技术有限公司
京 ICP 证 09002463 号|Copyright © 1999-2016, CSDN.NET, All Rights Reserved GongshangLogo
公司简介|招贤纳士|广告服务|联系方式|版权声明|法律顾问|问题报告|合作伙伴|论坛反馈
网站客服杂志客服微博客服webmaster@csdn.net400-600-2320|北京创新乐知信息技术有限公司 版权所有|江苏知之为计算机有限公司|江苏乐知网络技术有限公司
京 ICP 证 09002463 号|Copyright © 1999-2016, CSDN.NET, All Rights Reserved GongshangLogo

