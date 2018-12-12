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
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int in_left, int in_right, int post_left, int post_right){
        if (in_left > in_right || post_left > post_right)
            return NULL;
        int rootVal = postorder[post_right];// 后序序遍历中的最后一个节点为当前树的根节点
        TreeNode* root = new TreeNode(rootVal);
        // 在中序序列中找到当前根节点
        int index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), rootVal));
        // 算出左子树和右子树的节点个数
        int left_num = index - in_left;
        int right_num = in_right - index;
        // 最后递归构建左右子树
        root->left = buildTree(inorder, postorder, in_left, index - 1, post_left, post_left + left_num - 1);
        root->right = buildTree(inorder, postorder, index + 1, in_right, post_left + left_num, post_right - 1);
        return root;
    } 
};

```
