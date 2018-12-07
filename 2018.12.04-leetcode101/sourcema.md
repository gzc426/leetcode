# LeetCode 101
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
        public boolean isSymmetric(TreeNode root) {
            if (root == null) {
                return true;
            }
            return symmetric(root.left, root.right);
        }
        private boolean symmetric(TreeNode p, TreeNode q) {
            if (p == null && q == null) {
                return true;
            }
            if ((p == null && q != null) || (p != null && q == null) || p.val != q.val) {
                return false;
            }
            return symmetric(p.left, q.right) && symmetric(p.right, q.left);
        }
    }
