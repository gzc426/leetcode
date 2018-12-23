```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head,NULL);
    }
    TreeNode* buildBST(ListNode* head,ListNode* tail)
    {
        if(head==tail)
            return NULL;
        
        if(head->next==tail)
        {
            TreeNode* root=new TreeNode(head->val);
            return root;
        }
        ListNode* mid=head;
        ListNode* fast=head;
        while(fast!=tail&&fast->next!=tail)
        {
            mid=mid->next;
            fast=fast->next->next;
        }
        TreeNode* root=new TreeNode(mid->val);
        root->left=buildBST(head,mid);
        root->right=buildBST(mid->next,tail);
        return root;
    }
};
```
