## 102_(二叉树的层次遍历)Binary Tree Level Order Traversal
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。<br>
### 1.2 输入与输出
输入：<br>
* TreeNode* root：二叉树的根节点指针<br>
输出：<br>
* vector<vector<int>>：层次遍历的结果，是一个二维矢量的形式
### 1.3 样例
#### 1.3.1 样例1
输入: 给定二叉树: [3,9,20,null,null,15,7],
    
        3
       / \
      9  20
        /  \
       15   7

输出: 

    [
      [3],
      [9,20],
      [15,7]
    ]

## 2 思路描述与代码    
### 2.1 思路描述（基于队列的二叉树层次遍历）
二叉树的层次遍历可以利用队列来做，其思路也很简单。<br>
这里为了把每层的结果记录下来，对BFS的代码结构稍微改动了下，即里面用了个 for 循环做当前层遍历。<br>
```cpp
初始化二叉树层次遍历的二维矢量 res ;
头结点入队;
while( 队列不空 ){
    初始化当前层的遍历结果 level;
    获取当前层的数目数 len;
    for( int i = 0; i < len; i++ ){
        取出当前层的节点tmp并保存至 level;
        左右孩子非空则入队;
    }
    将 level 保存至 res ;
}
返回 res ;
```
比如给定二叉树: [3,9,20,null,null,15,7];<br>
首先根节点3入队，然后进入 while 循环;<br>
此时队列不空，有1个元素3，for 循环后有 res = {[3]}, 队列里面有元素[9, 20];<br>
此时队列不空，有元素[9, 20]，for 循环后有 res = {[3],[9,20]}, 队列里面有元素[15, 7];<br>
此时队列不空，有元素[15, 7]，for 循环后有 res = {[3],[9,20], [15,7]}, 队列里面没有元素;<br>
此时队列空后，返回 res = {[3],[9,20], [15,7]} 。

### 2.2 代码
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    //如果输入为空
    if (root == NULL) {
        return res;
    }
    //队列做BFS
    queue<TreeNode*> q;
    q.push(root);
    while( !q.empty() ){
        //获取当前层的数目
        int len = q.size();
        vector<int> level;
        TreeNode* tmp;
        for( int i = 0; i < len; i++ ){
            //取一节点放入当前层的结果矢量里
            tmp = q.front();
            q.pop();
            level.push_back(tmp->val);
            //当前层所有的节点如果有孩子节点则压入队列
            if(tmp->left){
                q.push(tmp->left);
            }
            if(tmp->right){
                q.push(tmp->right);
            }
        }
        res.push_back(level);
    }
    return res;
}
```
## 3 思考与拓展
### 3.1 思考
本题，利用队列做二叉树的层次遍历并保存结果。当然你可以利用堆栈做，但是保存结果的方式不一样而已。     
#### 3.1.1 其他方法
#### 3.1.1.1 基于堆栈的二叉树层次遍历
思路还是一致的，只是数据结构换了而已。在每层遍历的时候，需要改动的地方有:
1. 入堆栈要右子树(如果有的话)先入，左子树(如果有的话)后入;
2. 当前层遍历结果 level 要反序再 push_back 至 res。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
基于队列的二叉树层次遍历|O(2^h),h是树的高度|O(n)
基于堆栈的二叉树层次遍历|O(2^h),h是树的高度|O(n)，由于多了一步反序，所以会比基于队列的慢一点
#### 3.1.3 难点分析
1. 采用什么数据结果做层次遍历
2. 如何保存每层的遍历结果
### 3.2 拓展
如果让你[锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)呢？
