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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(0,nums.size()-1,nums);
    }
    
    TreeNode* buildBST(int l,int r,vector<int>& nums)
    {
        if(l>r)
            return nullptr;
        int k=l+(r-l+1)/2;
        TreeNode* root=new TreeNode(nums[k]);
        root->left=buildBST(l,k-1,nums);
        root->right=buildBST(k+1,r,nums);
        return root;
        
    }
};
```
