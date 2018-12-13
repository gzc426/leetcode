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
    TreeNode* work(vector<int> nums){
        int size = nums.size();
        if(size==0) return NULL;
        TreeNode* root = new TreeNode(nums[size/2]);
        vector<int> nums_left = vector<int>(nums.begin(),nums.begin()+size/2);
        vector<int> nums_right = vector<int>(nums.begin()+size/2+1,nums.end());
        root->left = work(nums_left);
        root->right = work(nums_right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* t = head;
        vector<int> nums;
        while(t->next){
            nums.push_back(t->val);
            t = t->next;
        }
        nums.push_back(t->val);
        int size = nums.size();
        //for(int i = 0; i < size; i++) cout<<nums[i]<<endl;
        TreeNode* root = work(nums);
        return root;
    }
};
```
