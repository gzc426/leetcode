# C++
```cpp
class Solution {
public:
    vector<vector<int>> res;
    void check(TreeNode* root, int depth){
        if(root == NULL) return ;
        if(res.size() == depth)
        {
            res.push_back(vector<int>());
        }
        res[depth].push_back(root->val);
        check(root->left, depth + 1);
        check(root->right, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        check(root, 0);
        return res;
    }
};
```
