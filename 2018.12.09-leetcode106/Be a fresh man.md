## 106_(从中序与后序遍历序列构造二叉树)Construct Binary Tree from Inorder and Postorder Traversal
## 1 问题描述、输入输出与样例
### 1.1 问题描述
根据一棵树的中序遍历与后序遍历构造二叉树。<br>
__注意__:
你可以假设树中没有重复的元素。
### 1.2 输入与输出
输入：
* vector<int>& inorder：中序遍历的序列的引用
* vector<int>& postorder：后序遍历的序列的引用

输出：
* TreeNode*：构造的二叉树的根节点
### 1.3 样例
#### 1.3.1 样例1
输入：中序遍历 inorder = [9,3,15,20,7]，后序遍历 postorder = [9,15,7,20,3]<br>
输出: 

	    3
	   / \
	  9  20
        /  \
	   15   7
## 2 思路描述与代码    
### 2.1 思路描述（递归法）
最常见的构造树的方法就是递归了。二叉树的后序遍历的最后节点肯定是根节点，该节点在中序遍历中是个分节点，在分节点左边的节点是左子树的所有节点，右边是右子树的所有节点。利用该思路构造二叉树。
```cpp
TreeNode* buildTree_recurse(inorder_begin, inorder_len, postorder_begin, postorder_len){
    若中序遍历长度为 0 ,返回空指针;
    构建根节点 root, 值为 *(postorder_begin + postorder_len - 1) ;
    找到 *(postorder_begin + postorder_len - 1) 在中序遍历中的位置 idx;
    //递归左右子树
    root->left = buildTree_recurse(inorder_begin, idx, postorder_begin, idx);
    root->right = buildTree_recurse(inorder_begin + idx + 1, inorder_len - idx - 1, postorder_begin + idx, postorder_len - idx - 1);
    返回 root;
}
```

### 2.2 代码
```cpp
typedef vector<int>::iterator iter;
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTree_recurse(inorder.begin(), inorder.size(), postorder.begin(), postorder.size());
}
TreeNode* buildTree_recurse(iter inorder_begin, int inorder_len, iter postorder_begin, int postorder_len){
    if(inorder_len == 0) return nullptr;
    TreeNode* root = new TreeNode(*(postorder_begin + postorder_len - 1));
    int i;
    for( i = 0; i < inorder_len; i++ ){
        if(*(inorder_begin + i) == *(postorder_begin + postorder_len - 1)) break;
    }
    root->left = buildTree_recurse(inorder_begin, i, postorder_begin, i);
    root->right = buildTree_recurse(inorder_begin + i + 1, inorder_len - i - 1, postorder_begin + i, postorder_len - i - 1);
    return root;
    }
```
    
## 3 思考与拓展
### 3.1 思考
本题主要利用二叉树中序和后序遍历的特点递归构造二叉树，思路与利用前序和后序遍历构造二叉树一致。
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
如果让你从前序遍历和后序遍历构造二叉树呢？如果能，构造的二叉树是唯一的吗？
