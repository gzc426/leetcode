/*
  题目：
  给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
  
  做法：判断是奇数层还是偶数层。
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        if(root==NULL){
            return rst;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        bool even=false;
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
            
            if(even){//偶数层
                reverse(levelvec.begin(), levelvec.end());
                even=false;
            }else{               
                even=true;
            }       
            rst.push_back(levelvec); 
        }      
        
        return rst;
    }       
};
