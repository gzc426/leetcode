class Solution {
    private ListNode findNode(ListNode head){
        ListNode prev = head;
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null&&fast.next != null){
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        prev.next = null;
        return slow;
    }
    public TreeNode sortedListToBST(ListNode head) {
        if(head == null){
            return null;
        }
        ListNode mid = findNode(head);
        TreeNode node = new TreeNode(mid.val);
        if(mid == head){
            return node;
        }      
        node.left = sortedListToBST(head);
        node.right = sortedListToBST(mid.next);
        return node;
    }
}
