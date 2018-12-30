# LeetCode 108
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
        public TreeNode sortedArrayToBST(int[] arr) {
            if (arr.length == 0 || arr == null) {
                return null;
            }
            TreeNode root=generate(arr, 0, arr.length - 1);
            return root;
        }
        public  TreeNode generate(int[] arr, int start, int end) {
            if (start > end) {
                return null;
            }
            int mid=(start+end)/2;
            TreeNode head = new TreeNode(arr[mid]);
            head.left = generate(arr, start, mid - 1);
            head.right = generate(arr, mid + 1, end);
            return head;
        }
    }
