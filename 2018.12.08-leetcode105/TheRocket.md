```java
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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < inorder.length; ++i) {
            map.put(inorder[i], i);
        }
        return buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1, map);
    }

    private TreeNode buildTree(int[] preorder, int preBegin, int preEnd, int[] inorder, int inBegin, int inEnd, Map<Integer, Integer> map) {
        if (preBegin > preEnd || inBegin > inEnd) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[preBegin]);
        int i = map.get(root.val);
        int leftEnd = preBegin + i - inBegin;
        root.left = buildTree(preorder, preBegin + 1, leftEnd, inorder, inBegin, i - 1, map);
        root.right = buildTree(preorder, leftEnd + 1, preEnd, inorder, i + 1, inEnd, map);
        return root;
    }
}
```
