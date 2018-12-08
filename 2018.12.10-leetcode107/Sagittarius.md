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
    vector<vector<int>> a;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return a;
        
        lot(root,0);
        for(int i=0;i<a.size()/2;i++)
        {
            vector<int> v1;
            v1=a[i];
            a[i]=a[a.size()-1-i];
            a[a.size()-1-i]=v1;
        }
        return a;
    }
    void lot(TreeNode* node,int level)
    {
        if(a.size()<level+1)
        {
            vector<int> v1;
            v1.push_back(node->val);
            a.push_back(v1);
        }
        else
            a[level].push_back(node->val);

        if(node->left)
        lot(node->left,level+1);
        if(node->right)
        lot(node->right,level+1);
    }
};
```
