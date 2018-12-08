leetcode of 105
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
   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int s,int t,int &i) {
        if(i == preorder.size()) return nullptr;
        int val = preorder[i++];
        TreeNode * root = new TreeNode(val);
        if(s >= t - 1){
            return root;
        }
        int index = find(inorder.begin()+s,inorder.begin()+t,val) - inorder.begin();
        if(index != s){
            root->left = buildTree(preorder,inorder,s,index,i);
        }
        if(index != t - 1){
            root->right = buildTree(preorder,inorder,index+1,t,i);
        }
        return root;
    
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int i=0;
        return   buildTree(preorder,inorder,0,preorder.size(),i);
    }
};
```
