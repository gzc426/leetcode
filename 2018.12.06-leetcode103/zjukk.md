```
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bfs(res,root,0,true);
        return res;
    }
    void bfs(vector<vector<int>>& res, TreeNode* root, int level, bool fromLeft) {
        if (!root) return;
        if (level == res.size()) res.push_back({});
        if (fromLeft) res[level].push_back(root->val);
        else res[level].insert(res[level].begin(),root->val);
        bfs(res,root->left,level+1,!fromLeft);
        bfs(res,root->right,level+1,!fromLeft);
    }
};
```
