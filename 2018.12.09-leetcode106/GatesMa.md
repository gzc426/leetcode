# c++
```cpp
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
        return driver(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* driver(vector<int>& postorder, vector<int>& inorder, int p_lo, int p_hi, int i_lo, int i_hi) {
        if (p_lo > p_hi) return NULL;
        if (p_lo == p_hi) return new TreeNode(postorder[p_hi]);
        int node_val = postorder[p_hi];
        int index_in = this->find(inorder, i_lo, i_hi, node_val);
        int pre_left_len = index_in - i_lo;
        TreeNode* node = new TreeNode(node_val);
        node->left = driver(postorder, inorder, p_lo, p_lo + pre_left_len - 1, i_lo, index_in - 1);
        node->right = driver(postorder, inorder, p_lo + pre_left_len, p_hi - 1, index_in + 1, i_hi);
        return node;
    }
    int find(vector<int>& vec, int low, int high, int val) {
        for (int i = low; i <= high; ++i) {
            if (vec[i] == val) return i;
        }
        return -1;
    }
};
```
