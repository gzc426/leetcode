# c++
```cpp
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
        if(head == nullptr) return nullptr;
        return buildTree(head, nullptr);
    }
    TreeNode* buildTree(ListNode* head, ListNode* end) {
        if(head == end) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = buildTree(head, slow);
        node->right = buildTree(slow->next, end);
        return node;
    }
};
```
