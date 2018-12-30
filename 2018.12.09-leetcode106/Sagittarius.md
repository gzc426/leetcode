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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return rebuildTree(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder);
    }
    TreeNode* rebuildTree(int inL,int inR,int postL,int postR,vector<int>& inorder,vector<int>& postorder)
    {
        if(inL>inR)
            return nullptr;
        TreeNode* root=new TreeNode(postorder[postR]);
        int k;
        for(int i=0;i<=inR;i++)
            if(inorder[i]==postorder[postR])
            {
                k=i;
                break;
            }
        int nump=k-inL;
        root->left=rebuildTree(inL,k-1,postL,postL+nump-1,inorder,postorder);
        root->right=rebuildTree(k+1,inR,postL+nump,postR-1,inorder,postorder);
        
        return root;
    }
};
```
