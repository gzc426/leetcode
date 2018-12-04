## Leetcode 101


### 递归解法:

``` C++
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
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
    bool helper(TreeNode *left, TreeNode *right) {
	if (left == NULL && right == NULL) return true;
	if (left == NULL || right == NULL) return false;

	if (left->val != right->val) return false;
	return helper(left->left, right->right) && helper(left->right, right->left);

}
};

``` 

### 迭代解法:
``` C++
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
    bool isSymmetric(TreeNode* root) {
        	std::queue<TreeNode *> q;
	q.push(root);
	q.push(root);
	while (!q.empty()) {
		TreeNode* t1 = q.front();
        q.pop();
		TreeNode* t2 = q.front();
		q.pop();
		if (t1 == NULL && t2 == NULL)	continue;
		if (t1 == NULL || t2 == NULL)	return false;
		if (t1->val != t2->val)	return false;
		q.push(t1->left);
		q.push(t2->right);
		q.push(t1->right);
		q.push(t2->left);
	}
	return true;
    }
};

```
