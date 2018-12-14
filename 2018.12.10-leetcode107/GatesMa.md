# c++
```cpp
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
    vector<vector<int>> res;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        check(root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    void check(TreeNode* root, int depth) {
        if(root == NULL) return;
        if(res.size() == depth) {
            res.push_back(vector<int>());
        }
        res[depth].push_back(root->val);
        check(root->left, depth+1);
        check(root->right, depth+1);
    }
};
```
