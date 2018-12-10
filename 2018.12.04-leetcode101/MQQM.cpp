/*
  题目：
  给定一个二叉树，检查它是否是镜像对称的。
  
  做法：
  给定对应位置上的两个节点，递归判断这两个节点是否一致。
  
  参考：
  https://www.cnblogs.com/xiaozhuyang/p/7376749.html
*/

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
        if( root == NULL ){
            return true;
        }
        
        return isEqual(root->left, root->right);            
    }
    bool isEqual(TreeNode* left, TreeNode* right){//给定的两个节点已经是对应位置上的节点
        if( left == NULL && right == NULL ){//两个节点都是空
            return true;
        }
        if( left == NULL || right == NULL ){//有一个节点是空
            return false;
        }
        if( left->val != right->val ){//两个节点都存在，但是不相同
            return false;
        }
        
        return isEqual(left->left, right->right) && isEqual(left->right, right->left);       
    }
};
