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
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
    int depth(TreeNode* root) {
        if(root == NULL) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        return l > r ? l + 1 : r + 1;
    }
};
```
