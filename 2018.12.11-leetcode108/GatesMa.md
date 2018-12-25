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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return buildTree(nums, 0, nums.size()-1);
    }
    TreeNode* buildTree(vector<int>& nums,int n_l, int n_r) {
        if(n_l > n_r) return NULL;
        int mid = (n_l + n_r) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree(nums, n_l, mid-1);
        node->right = buildTree(nums, mid+1, n_r);
        return node;
    }
};
```
