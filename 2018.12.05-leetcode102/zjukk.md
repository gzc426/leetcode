```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        while (!q.empty()) {
            int cap = q.size();
            vector<int> tmp;
            for (int i = 0; i < cap; ++i) {
                TreeNode* node = q.front();
                tmp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
            res.push_back(tmp);
        }
        return res;
    }
};
```
