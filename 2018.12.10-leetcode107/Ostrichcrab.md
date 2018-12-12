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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int> > result;
        if(root == NULL) return result;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> tmp;
            for(int i = 0; i < size; i++){
                TreeNode* t = que.front();
                if(t->left) que.push(t->left);
                if(t->right) que.push(t->right);
                tmp.push_back(t->val);
                que.pop();
            }
            result.push_back(tmp);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
```
