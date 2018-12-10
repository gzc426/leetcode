class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& inorder, int iLeft, int iRight, vector<int>& postorder, int pLeft, int pRight) {
        if (iLeft > iRight) return NULL;
        TreeNode* root = new TreeNode(postorder[pRight]);
        int i = iLeft;
        for (; i <= iRight; ++i) {
            if (inorder[i] == root->val)
                break;
        }
        root->left = buildTree(inorder,iLeft,i-1,postorder,pLeft,pLeft-iLeft+i-1);
        root->right = buildTree(inorder,i+1,iRight,postorder,pLeft-iLeft+i,pRight-1);
        return root;
    }
};
