# c++
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    /**重载这个函数*/
    //表示 前序为preorder，从下标p_l到p_r，中序为inorder，下标从i_l到i_r构建 树
    TreeNode* buildTree(vector<int>& preorder, vector<int> inorder, int p_l, int p_r, int i_l, int i_r) {
        if(p_l > p_r) return NULL;
        if(p_l == p_r) return new TreeNode(preorder[p_l]);
        int index = find(inorder, i_l, i_r, preorder[p_l]);//根节点在中序遍历中的位置
        TreeNode* node = new TreeNode(preorder[p_l]);
        int pre_left_len = index - i_l;//左子树的长度
        // preorder[p_lo+1 ... p_lo+pre_left_len]是先序数组中与现结点左子树对应的部分。
        // inorder[i_lo ... index_in-1]是中序数组中与现结点左子树对应的部分。
        node->left = buildTree(preorder, inorder, p_l+1, p_l+pre_left_len, i_l, index - 1);
        node->right = buildTree(preorder, inorder, p_l+pre_left_len+1, p_r, index+1, i_r);
        return node;
    }
    
    int find(vector<int>& inorder, int l, int r, int node_val) {
        for(int i =l;i <= r;i++){
            if(inorder[i] == node_val) return i;
        }
        return -1;
    }
};
```
