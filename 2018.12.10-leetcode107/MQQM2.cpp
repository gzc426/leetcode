/*
  题目：
  给定一个二叉树，返回其节点值自底向上的层次遍历。（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
  
  参考：
  https://blog.csdn.net/Snow_Jie/article/details/80875360
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
    vector<vector<int>> rst;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {        
        levelTra(root, 0);
        return vector<vector<int>>(rst.rbegin(), rst.rend());//反向遍历rst，生成新的vector<vector<int>>容器对象  
    }
    void levelTra(TreeNode* root, int level){
        if(root == NULL){
            return;
        }
        if(level == rst.size()){
            rst.push_back(vector<int>());
        }
        rst[level].push_back(root->val);
        levelTra(root->left, level+1);
        levelTra(root->right, level+1);
    }
};
