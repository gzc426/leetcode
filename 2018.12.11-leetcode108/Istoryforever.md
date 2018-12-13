leetcode of 108
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
    int depth(TreeNode * root){
        if(root == nullptr) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    void fix(TreeNode * root){
        int leftd = depth(root->left);
        int rightd = depth(root->right);
        if(rightd - leftd > 1){
            //执行左旋
            TreeNode *parent =new TreeNode(0) ;
            *parent = *root;
            TreeNode * cur = root->right;
            TreeNode * left= root->right->left;
            * root = * cur;
            parent->right = root->left;
            root->left = parent;
            delete cur;
        }
        if(leftd - rightd > 1){
            //执行右旋
            TreeNode *parent =new TreeNode(0) ;
            *parent = *root;
            TreeNode * cur = root->left;
            TreeNode * right = cur->right;
            *root = *cur;
            parent->left = right;
            root->right = parent;
            delete cur;
        }
    }
    void insert(TreeNode * &root,int val){
        if(root == nullptr){
            root = new TreeNode(val);
            return;
        }
        if(root->val < val){
            if(root->right)
                insert(root->right,val);
            else
                root->right = new TreeNode(val);
        }else{
            if(root->left)
                insert(root->left,val);
            else
                root->left = new TreeNode(val);
        }
        fix(root);
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * root = nullptr;
        for(auto i : nums){
            insert(root,i);
        }
        return root;        
    }
};
```
