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
    vector<int> a;
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        lot(root,0);
            
        return a.size();
        
    }
    void lot(TreeNode* node,int level)
    {
        if(!node)
            return ;
        if(a.size()<level+1)
            a.push_back(0);
        lot(node->left,level+1);
        lot(node->right,level+1);
    }
    
};
static int optimize = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}();
```
