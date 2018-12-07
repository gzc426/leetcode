# leetcode 104
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
        public int maxDepth(TreeNode root) {
           if (root == null) {
                return 0;
            }
            return getDepth(root,0);
        }
        public static int getDepth(TreeNode root,int level) {
            if (root == null) {
                return level;
            }
            int left = getDepth(root.left, level + 1);
            int right = getDepth(root.right, level + 1);
            return Math.max(left,right);
        }


    }
