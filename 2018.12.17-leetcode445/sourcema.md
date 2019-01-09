# LeetCode 445
    class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null || l2 == null) {
            return l1==null?l2:l1;
        }
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        int ca=0;
        ListNode node=null;
        while (l1 != null) {
            stack1.push(l1.val);
            l1=l1.next;
        }
        while (l2 != null) {
            stack2.push(l2.val);
            l2=l2.next;
        }
        while (!stack1.isEmpty() || !stack2.isEmpty()) {
            int s1=stack1.isEmpty()?0:stack1.pop();
            int s2=stack2.isEmpty()?0:stack2.pop();
            ListNode cur = new ListNode((s1 + s2 + ca) % 10);
            cur.next=node;
            node=cur;
            ca=(s1+s2+ca)/10;
        }
        if (ca == 1) {
            ListNode cur = new ListNode(1);
            cur.next=node;
            node=cur;
        }
        return node;
    }
}
