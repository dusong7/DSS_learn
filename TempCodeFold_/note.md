codeblocks _解决多个文件编译，新建文件后，需要再添加到project、

深度为k的完全二叉树至少有 ( ) 个结点,至多有 ( ) 个结点
数学坏少63032014-10-29
优质解答
至少有2的（k-1）次方个节点
最多有（2的k次方）-1个节点；

中序遍历 可以使用 投影法来表示。。

http://student.zjzk.cn/course_ware/data_structure/web/shu/shu6.2.2.htm

 回到顶部
		
网站工具

管 理
flash插件下载
下午好，生命在于学习！	
首页	概论	线性表	栈和队列	串	多维数组	广义表	树	图	排序	查找	文件

网警工作室树的概念
 概念
网警工作室二叉树
 二叉树的定义
二叉树的性质
 二叉树的存储结构
网警工作室二叉树的遍历
 二叉树的遍历
网警工作室线索二叉树
 线索二叉树
网警工作室树和森林
 树、森林和二叉树的转换
 树的存储结构
 树和森林的遍历
网警工作室哈夫曼树及其应用
 最优二叉树
 哈夫曼编码
二叉树具有以下重要性质：
性质1 二叉树第i层上的结点数目最多为2i-1(i≥1)。
证明：用数学归纳法证明：
　    归纳基础：i=1时，有2i-1=20=1。因为第1层上只有一个根结点，所以命题成立。
    　归纳假设：假设对所有的j(1≤j<i)命题成立，即第j层上至多有2j-1个结点，证明j=i时命题亦成立。
    　归纳步骤：根据归纳假设，第i-1层上至多有2i-2个结点。由于二叉树的每个结点至多有两个孩子，故第i层上的结点数至多是第i-1层上的最大结点数的2倍。即j=i时，该层上至多有2×2i-2=2i-1个结点，故命题成立。

性质2 深度为k的二叉树至多有2k-1个结点(k≥1)。
证明：在具有相同深度的二叉树中，仅当每一层都含有最大结点数时，其树中结点数最多。因此利用性质1可得，深度为k的二叉树的结点数至多为：
                20+21+…+2k-1=2k-1
    故命题正确。

性质3 在任意-棵二叉树中，若终端结点的个数为n0，度为2的结点数为n2，则no=n2+1。
证明：因为二叉树中所有结点的度数均不大于2，所以结点总数(记为n)应等于0度结点数、1度结点(记为n1)和2度结点数之和：
                     n=no+n1+n2 (式子1)
　    另一方面，1度结点有一个孩子，2度结点有两个孩子，故二叉树中孩子结点总数是：
                      nl+2n2
　　树中只有根结点不是任何结点的孩子，故二叉树中的结点总数又可表示为：
                      n=n1+2n2+1 (式子2)
　　由式子1和式子2得到：
                      no=n2+1

满二叉树和完全二叉树是二叉树的两种特殊情形。
1、满二叉树(FullBinaryTree) 
    　一棵深度为k且有2k-1个结点的二又树称为满二叉树。
    　满二叉树的特点：
　　（1）	每一层上的结点数都达到最大值。即对给定的高度，它是具有最多结点数的二叉树。
　　（2）	满二叉树中不存在度数为1的结点，每个分支结点均有两棵高度相同的子树，且树叶都在最下一层上。
　　【例】图(a)是一个深度为4的满二叉树。
         
  

2、完全二叉树(Complete BinaryTree) 
    若一棵二叉树至多只有最下面的两层上结点的度数可以小于2，并且最下一层上的结点都集中在该层最左边的若干位置上，则此二叉树称为完全二叉树。
  特点：
  （1）	满二叉树是完全二叉树，完全二叉树不一定是满二叉树。
  （2）	在满二叉树的最下一层上，从最右边开始连续删去若干结点后得到的二叉树仍然是一棵完全二叉树。
  （3）	在完全二叉树中，若某个结点没有左孩子，则它一定没有右孩子，即该结点必是叶结点。
【例】如图(c)中，结点F没有左孩子而有右孩子L，故它不是一棵完全二叉树。
【例】图(b)是一棵完全二叉树。
  
性质4  具有n个结点的完全二叉树的深度为
                            
证明：设所求完全二叉树的深度为k。由完全二叉树定义可得：
　　深度为k得完全二叉树的前k-1层是深度为k-1的满二叉树，一共有2k-1-1个结点。
由于完全二叉树深度为k，故第k层上还有若干个结点，因此该完全二叉树的结点个数：
                  n>2k-1-1。
    　另一方面，由性质2可得：
                  n≤2k-1，
       即：2k-1-l<n≤2k-1
    　由此可推出：2k-1≤n<2k，取对数后有：
                  k-1≤lgn<k
    　又因k-1和k是相邻的两个整数，故有
                                      ,
    　由此即得：
                   
注意：
           的证明【参见参考书目】

     A1
   B2   C3;
 D4  5E F6  G7;
 
 n = 7
 i   = 1; par i= n/2
 2*i <= n left = 2*i  ..2*i >n no Left;
 
 2*i+1 <=n right = 2*i + 1 ..  2*i+1 >n no right;
 
 
 
 最里层为4，括号内有两个的前一阶有3个，4 = 3 + 1;
 
 (A(B(DE)C(FG)))  4 = 3+1;
 
 
 (A(B(DE)C(F))) 3 = 2+1;