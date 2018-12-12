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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length == 0 || postorder.length == 0)
            return null;
        return build(inorder,0,inorder.length-1,postorder,0,postorder.length-1);
    }

    private TreeNode build(int[] inorder, int start1, int end1, int[] postorder, int start2, int end2) {
        int rootValue = postorder[end2];
        TreeNode root = new TreeNode(rootValue);
        if (start2 == end2)
            return root;
        int temp = start1;
        while (inorder[temp] != rootValue && temp <= end1){
            temp++;
        }
        int leftLength = temp - start1;
        int leftEnd = start2 + leftLength - 1;
        if (leftLength > 0)
            root.left = build(inorder,start1,temp-1,postorder,start2,leftEnd);
        if (leftLength < end2 - start2)
            root.right = build(inorder,temp+1,end1,postorder,leftEnd+1,end2-1);
        return root;
    }
}
