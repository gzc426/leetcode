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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root == nullptr) return result;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> tmp;
            for(int i = 0; i < size; i++){
                TreeNode* t = que.front();
                que.pop();
                tmp.push_back(t->val);
                if(t->left) que.push(t->left);
                if(t->right) que.push(t->right);
            }
            result.push_back(tmp);
        }
        return result;
    }
};
```
