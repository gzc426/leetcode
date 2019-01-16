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
    void dfs(TreeNode* root, vector<string> &str, string strpath)
    {
        if(root->left==nullptr&&root->right==nullptr){
            str.push_back(strpath);
            return;
        }
        if(root->left){
            dfs(root->left,str,strpath+"->"+to_string(root->left->val));
        }
        if(root->right){
            dfs(root->right,str,strpath+"->"+to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==nullptr) return res;
        dfs(root,res,to_string(root->val));
        return res;
    }
};
```
