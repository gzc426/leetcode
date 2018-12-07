leetcode of 106
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
    TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder,int s,int t,int & i) {
        if(s == t) return nullptr;
        TreeNode * root = new TreeNode(postorder[i--]);
        int val = root->val;
        if(s >= t-1) return root;
        int index = find(inorder.begin()+s,inorder.begin()+t,val) - inorder.begin();
        if(index != t-1){
            root->right = buildTree(inorder,postorder,index+1,t,i);
        }
        if(index != s){
            root->left = buildTree(inorder,postorder,s,index,i);
        }
      
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = inorder.size()-1;
        return buildTree(inorder,postorder,0,inorder.size(),i);
    }
};
```
