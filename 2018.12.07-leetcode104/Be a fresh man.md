## 104_Maximum Depth of Binary Tree(二叉树的最大深度)
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个二叉树，找出其最大深度。<br>
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。<br>
__说明__: 叶子节点是指没有子节点的节点。
### 1.2 输入与输出
输入：
* TreeNode* root：二叉树的根节点

输出：
* int：最远叶子节点的最长路径上的节点数
### 1.3 样例
#### 1.3.1 样例1
输入: 给定二叉树:[3,9,20,null,null,15,7]

        3
	   / \
	  9  20
	    /  \
	   15   7
	  
输出: 3

## 2 思路描述与代码    
### 2.1 思路描述（基于队列的层次遍历方法）
利用队列做层次遍历，遍历的时候用 depth 记录当前层遍历的深度，遍历结束后返回其深度。
```cpp
初始化深度 depth 为0;
将二叉树根节点压入队列;
while( 队列不空 ){
    深度 depth 加1
    获取当前层的深度 layer_len
    
    for( int i = 0; i < layer_len; i++ ){
        弹出一个节点;
        如果该节点有孩子节点，则入队;
    }
}
返回 depth;
```
### 2.2 代码
```cpp
int maxDepth(TreeNode* root) {
    queue<TreeNode*> q;
    //初始化深度为0
    int depth = 0;
    //将头结点压入队列
    if(root) 
        q.push(root);
    //利用队列做二叉树的层次遍历
    while( !q.empty() ){
        //深度加1
        depth += 1;
        //获取当前层的深度
        int layer_len = q.size();
        //层次遍历的所有节点
        //如果该节点有孩子节点，则入队
        for( int i = 0; i < layer_len; i++ ){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left)
                q.push(tmp->left);
            
            if(tmp->right)
                q.push(tmp->right);
        }
    }
    return depth;
}
```
## 3 思考与拓展
### 3.1 思考
有了101、102、103题的练手，本题就是易如反掌。本方法可以看做BFS，那当然还有一种DFS的做法了。
#### 3.1.1 其他方法
#### 3.1.1.1 递归法
根节点的深度就是其左子树和右子树的深度的最大值加1。
```cpp
int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    else return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
```
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
基于队列的层次遍历方法|O(2^h),h是树的高度|O(n)
递归法|O(n)|O(n)
#### 3.1.3 难点分析
1. 使用递归方法时要得到递归的公式
2. 使用队列方法时需要注意深度加1的条件必须是当前层所有节点遍历结束。
### 3.2 拓展
如果让你求最远叶子节点的最长路径呢？
