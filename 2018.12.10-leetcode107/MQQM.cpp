/*
  题目：
  给定一个二叉树，返回其节点值自底向上的层次遍历。（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
  
  做法：与第102题一样，返回前反转。
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> rst;
        if(root == NULL){
            return rst;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int len=que.size();
            
            vector<int> levelvec;
            for(int i=0; i<len; i++){
                TreeNode* p=que.front();
                que.pop();         
                levelvec.push_back(p->val);
                
                if(p->left != NULL){                
                    que.push(p->left);                    
                }
                if(p->right != NULL){
                    que.push(p->right); 
                }   
            }
            rst.push_back(levelvec);            
        }
                
        reverse(rst.begin(), rst.end());//反转rst
        return rst;
    }
};
