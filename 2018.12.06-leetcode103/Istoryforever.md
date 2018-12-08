leetcode of 103
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
struct DN{
    TreeNode * p;
    int depth;
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        bool flag = true;
        int depth = 0;
        queue<DN> q;
        vector<int>t;
        q.push(DN{root,0});
        while(!q.empty()){
            DN dn = q.front();       
            q.pop();
            if(dn.depth == depth){
                t.push_back(dn.p->val);
            }else{
                depth = dn.depth;
                if(!flag) reverse(t.begin(),t.end());
                ans.push_back(t);
                flag=!flag;
                t.clear();
                t.push_back(dn.p->val);
            }
            
            if(dn.p->left) q.push(DN{dn.p->left,depth+1});
            if(dn.p->right) q.push(DN{dn.p->right,depth+1});
         
            if(q.empty()) 
            {
                if(!flag) reverse(t.begin(),t.end());
                ans.push_back(t);
            }
        }
       
        return ans;
        
        
    }
};
```
