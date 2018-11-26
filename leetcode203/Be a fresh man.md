203. 移除链表元素
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6输出: 1->2->3->4->5


点解？
思路：有两种方法，一种方法是使用递归，另一种是使用虚拟头结点。
递归就是不断指向下一个节点，返回的时候 如果是相同的那么就返回当前节点下一个，如果不相同就返回当前节点。
虚拟头结点：就是先创建一个为空的节点，先指向头结点，再让头结点往前移。然后不断的指向下一个循环，如果相同则直接指向下一个的下一个(跳过相同的节点)，不相同则把头节点后移。

代码
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        //使用递归
//         if(head==null) return null;        
//         head.next=removeElements(head.next,val);
//         return head.val==val ? head.next : head;

        //使用虚拟头结点
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        head=dummy;

        while(head.next!=null){
            if(head.next.val==val){
                head.next=head.next.next;
            }else{
                head=head.next;
            }
        }
        return dummy.next;
    }
}
