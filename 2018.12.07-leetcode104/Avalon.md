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
        if (root == null) return 0;
		int nodedeep = 0;
		LinkedList<TreeNode> list = new LinkedList<>();
		list.add(root);
		TreeNode current;
		int len;
		List<Integer> intlist = new ArrayList<>();
		while (!list.isEmpty()) {
			len = list.size();
			for (int i = 0; i < len; i++) {
				current = list.poll();
				if (current.left!=null)
					list.add(current.left);
				if (current.right!=null)
					list.add(current.right);
			}
			nodedeep++;
		}
		return nodedeep;
    }
}
