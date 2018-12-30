## 108_(将有序数组转换为二叉搜索树)Convert Sorted Array to Binary Search Tree
## 1 问题描述、输入输出与样例
### 1.1 问题描述
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。<br>
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
### 1.2 输入与输出
输入：
* vector< int>& nums：按照升序排列的有序数组的引用<br>
输出：<br>
* TreeNode*：高度平衡二叉搜索树的根节点指针

### 1.3 样例
#### 1.3.1 样例1<br>
输入: <br>
有序数组：[-10,-3,0,5,9]<br>
输出: <br>
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：<br>

          0
         / \
       -3   9
       /   /
     -10  5

## 2 思路描述与代码    
### 2.1 思路描述（递归）
1. 以数组的中间节点为二叉搜索树的根节点，中间节点的左部分为左二叉搜索子树，中间节点的右部分为右二叉搜索子树。
2. 以根节点左右递归即可。

比如给定有序数组：[-10,-3,0,5,9]<br>
先获取根节点 *root 的值0<br>
递归左子树root->left = sortedArrayToBST([-10, -3]), root->right = sortedArrayToBST([5, 9]])<br>
根据同样的方法可以获取 root 左右二叉搜索子树，结果分别是:

        -3      9
       /       /
     -10      5

于是构造出的二叉搜索树是:

          0
         / \
       -3   9
       /   /
     -10  5

### 2.2 代码
```cpp
//涉及的概念
//vector<int> 可以理解为一个长度可变的 int 数组 
//vector<int>::iterator 可以理解为长度可变的 int 数组的指针
//TreeNode* root = new TreeNode(val) root 是从堆中生成一个值为 val 的链表节点的指针
//root->left 是 root 所指向节点的左子树根节点的指针, root->right 同理

typedef vector<int>::iterator iter;
public:
//采用递归的思路
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST_recurse(nums.begin(), nums.size());
}
//采用递归的思路
TreeNode* sortedArrayToBST_recurse(iter begin, int len){
    //边界情况
    if(len == 0) return nullptr;
    if(len == 1) return new TreeNode(*begin);
    //找到根节点，然后左右递归
    //左子树长度为 len / 2 
    //右子树长度是 len - len / 2 - 1
    TreeNode* root = new TreeNode(*(begin + len / 2));
    root->left = sortedArrayToBST_recurse(begin, len / 2);
    root->right = sortedArrayToBST_recurse(begin + len / 2 + 1, len - len / 2 - 1);
    return root;
}
```
## 3 思考与拓展
### 3.1 思考
本题数据是基于数组的结构，array[len / 2]即是根节点，然后左右递归即可。
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
递归|O(n)|O(n)
#### 3.1.3 难点分析
1. 边界的判断

### 3.2 拓展
如果给定的数据是链表呢？会影响时间复杂度吗？
