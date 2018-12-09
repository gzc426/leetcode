/*
  题目：
  根据一棵树的前序遍历与中序遍历构造二叉树。
  
  参考：
  https://blog.csdn.net/u014265347/article/details/76400062
*/

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
        int l1 = 0;
        int l2 = 0;
        int r1 = preorder.size() - 1;
        int r2 = inorder.size() - 1;
        return build(preorder, inorder, l1, r1, l2, r2);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2){
        if (l1 > r1){//中序遍历中，根前面没有元素，那么l1>r1        
            return NULL;
        }
             
        int root_val = preorder[l1];//中序遍历中根的索引
        TreeNode* root = new TreeNode(root_val);
        
        int idx;//确定根在中序遍历中的索引
        for (idx = l2; idx <= r2; idx++){
            if (inorder[idx] == root_val){
                break;
            }
        }        
        root->left = build(preorder, inorder, l1 + 1, l1 + (idx - l2), l2, idx - 1);
        root->right = build(preorder, inorder, l1 + idx - l2 + 1, r1, idx + 1, r2);
        
        return root;
    }
};
