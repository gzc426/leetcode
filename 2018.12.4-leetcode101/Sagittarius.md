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
bool isSymmetric1(TreeNode* r1,TreeNode* r2)
{
    if(!r1&&!r2)
            return true;
    else if((r1&&!r2)||(!r1&&r2))
            return false;
    else
    {
        if(r1->val!=r2->val)
            return false;
        else 
            return isSymmetric1(r1->left,r2->right)&&isSymmetric1(r1->right,r2->left);
    }
    
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        else
            return isSymmetric1(root->left,root->right);
    }
};
```
