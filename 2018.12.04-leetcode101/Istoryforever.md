leetcode of 101
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
    bool isSymmetric(TreeNode* p1,TreeNode * p2){
        if((p1 == nullptr && p2!=nullptr) || (p2 == nullptr && p1!=nullptr)) return false;
        if(p1 == nullptr && p2 == nullptr) return true;
        if(p1->val != p2->val) return false;
        return isSymmetric(p1->left,p2->right) && isSymmetric(p1->right,p2->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root,root);   
    }
};
```
