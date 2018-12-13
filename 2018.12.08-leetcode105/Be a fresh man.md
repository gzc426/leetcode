## 105_(从前序与后序遍历序列构造二叉树)Construct Binary Tree from Preorder and Inorder Traversal
## 1 问题描述、输入输出与样例
### 1.1 问题描述
根据一棵树的前序遍历与中序遍历构造二叉树。<br>
__注意__:
你可以假设树中没有重复的元素。
### 1.2 输入与输出
输入：
* vector<int>& preorder：前序遍历的序列的引用
* vector<int>& inorder：中序遍历的序列的引用

输出：
* TreeNode*：构造的二叉树的根节点
### 1.3 样例
#### 1.3.1 样例1
输入：前序遍历 preorder = [3,9,20,15,7]，中序遍历 inorder = [9,3,15,20,7]<br>
输出: 

	    3
	   / \
	  9  20
        /  \
	   15   7
## 2 思路描述与代码    
### 2.1 思路描述（递归法）
最常见的构造树的方法就是递归了。二叉树的前序遍历的第一个节点肯定是根节点，该节点在中序遍历中是个分节点，在分节点左边的节点是左子树的所有节点，右边是右子树的所有节点。利用该思路构造二叉树。
```cpp
TreeNode* buildTree_recurse(preorder_begin, preorder_len, inorder_begin, inorder_len){
    若前序遍历长度为 0 ,返回空指针;
    构建根节点 root, 值为 *preorder_begin ;
    找到 *preorder_begin 在中序遍历中的位置 idx;
    //递归左右子树
    root->left  = buildTree_recurse(preorder_begin + 1, idx, inorder_begin, idx);
    root->right = buildTree_recurse(preorder_begin + idx + 1, preorder_len - idx - 1, inorder_begin + i + 1, inorder_len - idx - 1);
    返回 root;
}
```

### 2.2 代码
```cpp
typedef vector<int>::iterator iter;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree_recurse(preorder.begin(), preorder.size(), inorder.begin(), inorder.size());
}
TreeNode* buildTree_recurse(iter preorder_begin, int preorder_len, iter inorder_begin, int inorder_len){
    if(preorder_len == 0) return nullptr;
    TreeNode* root = new TreeNode(*preorder_begin);
    int i;
    for( i = 0; i < inorder_len; i++ ){
        if(*(inorder_begin + i) == *preorder_begin) break;
    }
    root->left = buildTree_recurse(preorder_begin + 1, i, inorder_begin, i);
    root->right = buildTree_recurse(preorder_begin + i + 1, preorder_len - i - 1, inorder_begin + i + 1, inorder_len - i - 1);
    return root;
}
```
    
## 3 思考与拓展
### 3.1 思考
本题主要利用二叉树前序和中序遍历的特点递归构造二叉树，该思路也能应用在由后序和中序构造二叉树。
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
递归法|O(n)|O(n)
#### 3.1.3 难点分析
1. 需要考虑边界条件即遍历长度为 0 的时候
2. 找到递归的表达式
### 3.2 拓展
如果让你从中序遍历和后序遍历构造二叉树呢？
