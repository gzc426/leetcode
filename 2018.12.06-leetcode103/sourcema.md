# leetcode 103
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
        public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
            List<List<Integer>> lists = new ArrayList<>();
            if (root == null) {
                return lists;
            }
            dfs(lists, root, 0);
            return lists;
        }
        private static void dfs(List<List<Integer>> lists, TreeNode root, int level) {
            if (root == null) {
                return;
            }
            if (lists.size() < level + 1) {
                lists.add(new ArrayList<Integer>());
            }
            if (((level + 1) & 1) == 0) {
                lists.get(level).add(0,root.val);
            }else {
                lists.get(level).add(root.val);
            }
            dfs(lists,root.left,level+1);
            dfs(lists,root.right,level+1);
        }
    }
