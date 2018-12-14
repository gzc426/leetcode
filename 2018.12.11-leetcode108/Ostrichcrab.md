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
        if(nums.size()==0) return NULL;
        TreeNode* root = new TreeNode(nums[nums.size()/2]);
        vector<int> nums_left = vector<int>(nums.begin(),nums.begin()+nums.size()/2);
        vector<int> nums_right = vector<int>(nums.begin()+nums.size()/2+1,nums.end());
        root->left = sortedArrayToBST(nums_left);
        root->right = sortedArrayToBST(nums_right);
        return root;
    }
};
```
