```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        while(head != NULL && head->val == val){
            head = head->next;
        }
        if(head==NULL) return NULL;
        ListNode* node = head;
        while(node->next != NULL){
            if(node->next->val==val)
                node->next = node->next->next;
            else
                node = node->next;
        }
        return head;
    }
};
```
