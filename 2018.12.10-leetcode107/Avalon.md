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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> tempresult = new ArrayList<>();
		if (root == null) return tempresult;
		Queue<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		TreeNode current;
		while (!queue.isEmpty()) {
			List<Integer> tl = new ArrayList<>();
			//List<TreeNode> tn = new ArrayList<>();
			int len = queue.size();
			for (int i = 0; i < len; i++) {
				current = queue.poll();
				tl.add(current.val);
				if (current.left != null)
					queue.add(current.left);
				if (current.right != null)
					queue.add(current.right);
			}
			tempresult.add(tl);
		}
		List<List<Integer>> result = new ArrayList<>();
		int trlen = tempresult.size();
		for (int i=trlen-1;i>=0;i--){
			result.add(tempresult.get(i));
		}
		return result;
    }
}
