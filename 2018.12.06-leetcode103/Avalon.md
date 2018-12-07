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
        List<List<Integer>> result = new ArrayList<>();
		if (root == null) return result;
		LinkedList<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		TreeNode current;
		List<Integer> tempilist;
		int ilistlen;
		boolean isleftbegin = true;
		while (!queue.isEmpty()) {
			List<Integer> intlist = new ArrayList<>();
			int qlen = queue.size();
			for (int i = 0; i < qlen; i++) {
				current = queue.poll();
				intlist.add(current.val);
				if (current.left != null)
					queue.add(current.left);
				if (current.right != null)
					queue.add(current.right);
			}
			if (!isleftbegin) {
				tempilist = new ArrayList<>();
				ilistlen = intlist.size();
				for (int i=0;i<ilistlen;i++){
					tempilist.add(intlist.get(ilistlen-1-i));
				}
				intlist = tempilist;
			}
			result.add(intlist);
            isleftbegin = !isleftbegin;
		}
		return result;
    }
}
