###leetcode 109. 将双向链表转换成BBST

####利用快慢指针，找到中间点的前一个点。

####然后将root设为中间点的值。

####此时将中间左边的链表切出来，进行递归。方法是mid-1的链表结点后继为空。

####左边链表从head开始

####右边链表从中间结点的下一个开始。


```
public TreeNode sortedListToBST(ListNode head) {

        //条件判断
        if(head==null) return null;
        if(head.next == null) return new TreeNode(head.val);

       //快慢指针        
        ListNode fast = head.next.next;
        ListNode slow = head;
        
        while(fast!=null && fast.next!=null){
            fast = fast.next.next;
            slow = slow.next;
        }

   //找到中点以及右边链表的头部      
        ListNode temp = slow.next.next;
        TreeNode root = new TreeNode(slow.next.val);
  
  //切断      
        slow.next = null;
  
  //递归
        root.left = sortedListToBST(head);
        root.right = sortedListToBST(temp);
        return root;
    }
  
 ```
