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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root == NULL) return result;
        que.push(root);
        while(!que.empty()){
            vector<int> tmp;
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* t = que.front();
                que.pop();
                tmp.push_back(t->val);
                if(t->left) que.push(t->left);
                if(t->right) que.push(t->right);
            }
            result.push_back(tmp);
        }
        for(int i = 0; i < result.size(); i++){
            if(i&1) reverse(result[i].begin(),result[i].end());
        }
        return result;
    }
};
```
