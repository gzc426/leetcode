```
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
    public TreeNode buildTreeHelper(int[] inorder, int is, int ie, int[] preorder, int ps){
        if(is>ie || ps>=preorder.length) return null;
        TreeNode root = new TreeNode(preorder[ps]);
        int rootAtIn = is;
        while(inorder[rootAtIn] != root.val) rootAtIn++;
        root.left = buildTreeHelper(inorder,is,rootAtIn-1,preorder,ps+1);
        root.right = buildTreeHelper(inorder,rootAtIn+1,ie,preorder,ps+rootAtIn-is+1);
        return root;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTreeHelper(inorder,0,inorder.length-1,preorder,0);
    }
}
```
