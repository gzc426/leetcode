leetcode of 107
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
struct DNODE{
    int depth;
    TreeNode * p;
    DNODE(int d,TreeNode * p){
        this->depth = d;
        this->p = p;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<DNODE> q;         
        DNODE dn(0,root);
        q.push(dn);
        int depth = 0;
        vector<vector<int>>ans;
        if(root == nullptr) return ans;
        vector<int>cur;
        while(!q.empty()){
            dn=q.front();
            q.pop();
            if(dn.p->left){
                q.push(DNODE(dn.depth+1,dn.p->left));
            }
            if(dn.p->right){
                q.push(DNODE(dn.depth+1,dn.p->right));
            }
            if(depth == dn.depth){
                cur.push_back(dn.p->val);
            }else if(depth != dn.depth){
                ans.push_back(cur);
                vector<int>().swap(cur);
                cur.push_back(dn.p->val);
                depth = dn.depth;
            }
        }
        ans.push_back(cur);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```
