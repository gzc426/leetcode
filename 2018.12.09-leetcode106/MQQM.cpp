/*
  题目：
  根据一棵树的中序遍历与后序遍历构造二叉树。
  
  参考:
  https://blog.csdn.net/u014265347/article/details/76400400  
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {        
        int l1 = 0;
        int l2 = 0;
        int r1 = inorder.size() - 1;
        int r2 = postorder.size() - 1;
        return build(inorder, postorder, l1, r1, l2, r2);        
    }   
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l1, int r1, int l2, int r2){
        if(l2 > r2){
            return NULL;
        }
        
        int root_val = postorder[r2];
        TreeNode* root = new TreeNode(root_val);
        
        int idx;
        for(idx = l1; idx <= r1; idx++){
            if(inorder[idx] == root_val){
                break;
            }
        }
        root->left = build(inorder, postorder, l1, idx - 1, l2, l2 + (idx - l1) - 1);
        root->right = build(inorder, postorder, idx + 1, r1, l2 + (idx - l1), r2 - 1);        
        
        return root;
    }
};
