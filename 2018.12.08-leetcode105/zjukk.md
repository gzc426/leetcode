```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight) {
        if (pLeft > pRight) return NULL;
        int i;
        TreeNode* root = new TreeNode(preorder[pLeft]);
        for (i = iLeft; i <= iRight; ++i) {
            if (inorder[i] == root->val) break;
        }
        //i-iLeft == size(left)
        root->left = buildTree(preorder, pLeft+1, pLeft-iLeft+i, inorder, iLeft, i-1);
        root->right = buildTree(preorder, pLeft-iLeft+i+1, pRight, inorder, i+1, iRight);
        return root;
    }
};
```
