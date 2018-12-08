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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == NULL) return res;
        q.push(root);
        bool rever = false;//代表当前在第几层
        while(!q.empty()) {//每次循环都是一层
            vector<int> t; // 临时数组
            //q<TreeNode*> temq;
            int len = q.size();
            for(int i=0;i < len;i++){
                TreeNode*temNode = q.front();
                q.pop();
                t.push_back(temNode->val);
                if(temNode->left) q.push(temNode->left);
                if(temNode->right) q.push(temNode->right);
                //t.push_back(temNode->val);
            }
            
            if(rever) {
                reverse(t.begin(), t.end());
            }
            res.push_back(t);
            rever = !rever;
        }
        return res;
    }
};
```
