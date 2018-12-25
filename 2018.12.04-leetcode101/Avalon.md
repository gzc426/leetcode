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
        if (root == null ){
			return true;
		}
		
        return isSymmetric(root.left, root.right);
    }
    
    public static boolean isSymmetric(TreeNode nodeA, TreeNode node_A){
		if (node_A == null && nodeA == null) {
			return true;
		}
        if (node_A != null && nodeA != null) {
			return node_A.val == nodeA.val && isSymmetric(nodeA.left, node_A.right) && isSymmetric(nodeA.right, node_A.left);
		}
		return false;
	}
}
