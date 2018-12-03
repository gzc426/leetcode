leetcode of 102
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
struct DataNode{
    TreeNode * p;
    int depth;
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<DataNode> q;
        int depth = 0;
        q.push(DataNode{root,depth});
        vector<int>t;
        while(!q.empty()){
            DataNode dn = q.front();    
            q.pop();
            if(depth == dn.depth){
                t.push_back(dn.p->val);
            }else{
                depth = dn.depth; 
                ans.push_back(t);
                t.clear();
                t.push_back(dn.p->val);
            }      
            if(dn.p->left != nullptr)
               q.push(DataNode{dn.p->left,depth+1});
            if(dn.p->right != nullptr) 
                q.push(DataNode{dn.p->right,depth+1});
            
        }
        ans.push_back(t);
        return ans;
        
    }
};
```
