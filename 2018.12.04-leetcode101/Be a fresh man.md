## 101_(对称二叉树)Symmetric Tree
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个二叉树，检查它是否是镜像对称的。
### 1.2 输入与输出
输入：
* TreeNode* root：二叉树的根节点指针

输出：
* bool：是否是对称二叉树

### 1.3 样例
#### 1.3.1 样例1
输入: 给定二叉树: [1,2,2,3,4,4,3] ,

        1
       / \
      2   2
     / \ / \
    3  4 4  3
输出: true

#### 1.3.2 样例2
输入:给定二叉树: [1,2,2,null,3,null,3] ,

      1
     / \
    2   2
     \   \
     3    3
输出: false<br>
## 2 思路描述与代码    
### 2.1 思路描述（队列法）
利用队列做判断
```cpp
根节点左右孩子入队;
while( 队列非空 ){
    取出队列两个元素 tmp1, tmp2;
    //如果当前节点都是空节点，结束本次循环，即不需要检查后续节点
    if(tmp1 == null && tmp2 == null) continue;
    //如果不对称，则返回false
    if((tmp1 == nullptr && tmp2) || (tmp2 == nullptr && tmp1) || (tmp1->val != tmp2->val))
        return false;
    //剩下的可能情况就是左右非空且当前节点的值相等，即对称
    //然后对这两个节点的左右孩子节点对称入队，保持对称性
    //对称入队
    tmp1 左孩子入队;
    tmp2 右孩子入队;
    tmp1 右孩子入队;
    tmp2 左孩子入队;
}
return true;
```

### 2.2 代码
```cpp
bool isSymmetric(TreeNode* root) {
    if(root == nullptr)
        return true;
    //使用队列做遍历，这是也可以使用堆栈
    queue<TreeNode*> q;
    //根节点就不用判断了，直接加入左右孩子节点
    q.push(root->left);
    q.push(root->right);
    while( !q.empty() ){
        //从队列弹出两个节点
        TreeNode* tmp1 = q.front();
        q.pop();
        TreeNode* tmp2 = q.front();
        q.pop();
        //如果都是根节点，则结束本次循环
        if(tmp1 == nullptr && tmp2 == nullptr)
            continue;
        //如果不对称，则返回false
        if((tmp1 == nullptr && tmp2) || (tmp2 == nullptr && tmp1) || (tmp1->val != tmp2->val))
            return false;
        //对称入队
        q.push(tmp1->left);
        q.push(tmp2->right);
        q.push(tmp1->right);
        q.push(tmp2->left);
    }
    //都是对称的，返回真
    return true;
}

```
## 3 思考与拓展
### 3.1 思考
本题，利用队列和堆栈做遍历都可以解决这个问题。 
#### 3.1.1 其他方法
#### 3.1.1.1 递归法
一棵对称的二叉树必然是左右孩子相等且左右孩子也都是一棵对称的二叉树，利用该思路做递归就行了，这里就不继续写代码了。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
队列法|O(2^h),h是树的高度|O(n)
递归法|O(n)|O(n)
#### 3.1.3 难点分析
1. 对称与非对称的判断

### 3.2 拓展
如果让你判断是不是同构的呢？
