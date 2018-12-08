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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rebuildTree(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder);
    }
    
    TreeNode* rebuildTree(int preL,int preR,int inL,int inR,vector<int>& preorder,vector<int>& inorder)
    {
        if(preL>preR)
            return nullptr;
        TreeNode* root=new TreeNode(preorder[preL]);
        int k;
        for(int i=0;i<=inR;i++)
        {
            if(preorder[preL]==inorder[i])
            {
                k=i;
                break;
            }
        }
        int numPre=k-inL;
        root->left=rebuildTree(preL+1,preL+numPre,inL,k-1,preorder,inorder);
        root->right=rebuildTree(preL+numPre+1,preR,inL+numPre+1,inR,preorder,inorder);
        
        return root;
    }
};
```
