/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		String i1 = String.valueOf(l1.val);
		while (l1.next != null) {
			i1 = i1.concat(String.valueOf(l1.next.val));
			l1 = l1.next;
		}
		String i2 = String.valueOf(l2.val);
		while (l2.next != null) {
			i2 = i2.concat(String.valueOf(l2.next.val));
			l2.next = l2.next.next;
		}

		long l = Long.parseLong(i1)+Long.parseLong(i2);
		char[] charArr = String.valueOf(l).toCharArray();

		ListNode current;
		ListNode temp = new ListNode(charArr[charArr.length-1] -'0');
		for (int i =charArr.length-2;i>=0;i--){
			current=new ListNode(charArr[i]-'0');
			current.next = temp;
			temp = current;
		}
		return temp;
    }
}
