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
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums == null || nums.length == 0) return null;
		return buildAVLTree(nums, 0, nums.length - 1);
    }
    private static TreeNode buildAVLTree(int[] nums, int start, int end) {
		if (start > end) return null;
		if (start == end) return new TreeNode(nums[start]);
		int mid = (start + end) / 2;
		TreeNode node = new TreeNode(nums[mid]);
		node.left = buildAVLTree(nums, start, mid - 1);
		node.right = buildAVLTree(nums, mid + 1, end);
		return node;
	}
}
