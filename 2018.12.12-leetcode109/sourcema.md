# LeetCode 109
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) { val = x; }
     * }
     */
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     *     int val;
     *     TreeNode left;
     *     TreeNode right;
     *     TreeNode(int x) { val = x; }
     * }
     */
    class Solution {
        public TreeNode sortedListToBST(ListNode head) {
            if (head == null) {
                return null;
            }
            if (head.next == null) {
                return new TreeNode(head.val);
            }
            int n=0;
            ListNode cur=head;
            List<Integer> list = new ArrayList<>();
            while (cur != null) {
                list.add(cur.val);
                cur= cur.next;
            }
            int[] arr =new int[list.size()];
            for (int i = 0; i < arr.length; i++) {
                arr[i] = list.get(i);
            }
            TreeNode root = constructBST(arr, 0, arr.length - 1, new TreeNode(0));
            return root;
        }
        private TreeNode constructBST(int[] arr, int left, int right, TreeNode head) {
            if (left>right||head == null) {
                return null;
            }
            int mid=(left+right)>>1;
            head = new TreeNode(arr[mid]);
            head.left = constructBST(arr, left, mid - 1, head);
            head.right = constructBST(arr, mid + 1, right, head);
            return head;
        }
    }
