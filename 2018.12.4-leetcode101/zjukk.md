```
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return help(root->left,root->right);
    }
    bool help(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if ((!left && right) || (left && !right)) return false;
        if (left->val != right->val) return false;
        else return help(left->left,right->right) && help(left->right,right->left);
    }
};
```
