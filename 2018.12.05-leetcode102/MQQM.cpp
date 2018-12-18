/*
  题目：
  给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
  
  做法：用队列。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        if(root == NULL){
            return rst;
        }        
        
        queue<TreeNode*> que;        
        que.push(root);     
        while( !que.empty() ){            
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
        
        return rst;
    }
};
