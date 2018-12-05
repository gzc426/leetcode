leetcode of 104
```
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
    int maxDepth(TreeNode* root) {
         if(root == nullptr){
            return 0;
        }
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        int m = l > r ? l : r;
        return m+1;
    }
};
```
