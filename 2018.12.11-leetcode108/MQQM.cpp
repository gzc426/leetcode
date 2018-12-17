/*
  题目：
  将一个按照升序排列的有序数组，转换为一棵高度平衡的二叉搜索树。
  本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
  
  做法：
  因为是升序排列的数组，所以可以取区间内最中间的元素生成根节点，左子树为前半部分元素，右子树为后半部分元素。
  
  参考：
  https://www.cnblogs.com/liez/p/5304562.html
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size()-1);
    }
    TreeNode* createBST(vector<int>& nums, int left, int right){
        if(left>right){
            return NULL;
        }
        
        int mid=(left+right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left=createBST(nums, left, mid-1);
        root->right=createBST(nums, mid+1, right);

        return root;
    }
};
