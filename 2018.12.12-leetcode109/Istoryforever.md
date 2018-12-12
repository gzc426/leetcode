leetcode of 109
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
    ListNode * getHalfListNode(ListNode *head){
        ListNode * p1,*p2;
        ListNode * d= new ListNode(-1);
        d->next = head;
        p1 = d;
        p2 = head;
        while(p2 && p2->next){
            p2 = p2->next->next;
            p1 = p1->next;
        }
        delete d;
        return p1;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return new TreeNode(head->val);
        ListNode * split = getHalfListNode(head);
        ListNode * cur = split->next;
        TreeNode * root = new  TreeNode (cur->val);
        ListNode * right = cur->next;
        split->next = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(right);
        return root;
        
    }
};
```
