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
        if (head==null)return null;
		ListNode current = head;
		List<Integer> arr = new ArrayList<>();
		while (current !=null){
			arr.add(current.val);
			current = current.next;
		}

		return buildAVLTree(arr, 0, arr.size()-1);
    }
    private static TreeNode buildAVLTree(List<Integer> list, int start, int end){
		if (start> end)return null;
		int mid = (start+end)/2;
		TreeNode node = new TreeNode(list.get(mid));
		node.left =buildAVLTree(list, start, mid-1);
		node.right =buildAVLTree(list, mid+1, end);
		return node;
	}
}
