```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 0;
        for (;i < inorder.size(); ++i) {
            if (inorder[i] == preorder[0]) break;
        }
        int gen = i;
        vector<int> inorderLeft, preorderLeft,inorderRight,preorderRight;
        for (int i = 0; i < preorder.size(); ++i) {
            if (i < gen) inorderLeft.push_back(inorder[i]);
            if (i > gen) inorderRight.push_back(inorder[i]);
        }
        for (int i = 1; i < preorder.size(); ++i) {
            if (i <= inorderLeft.size()) preorderLeft.push_back(preorder[i]);
            else preorderRight.push_back(preorder[i]);
        }
        TreeNode* left = buildTree(preorderLeft,inorderLeft);
        TreeNode* right = buildTree(preorderRight,inorderRight);
        root->left = left;
        root->right = right;
        return root;
    }
};
```
