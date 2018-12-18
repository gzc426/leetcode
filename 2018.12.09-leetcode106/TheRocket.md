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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < inorder.length; ++i) {
            map.put(inorder[i], i);
        }
        return buildTree(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1, map);
    }

    private TreeNode buildTree(int[] inorder, int inBegin, int inEnd, int[] postorder, int postBegin, int postEnd, Map<Integer, Integer> map) {
        if (inBegin > inEnd || postBegin > postEnd) {
            return null;
        }
        TreeNode root = new TreeNode(postorder[postEnd]);
        int i = map.get(root.val);
        int leftEnd = postBegin + i - inBegin - 1;
        root.left = buildTree(inorder, inBegin, i - 1, postorder, postBegin, leftEnd, map);
        root.right = buildTree(inorder, i + 1, inEnd, postorder, leftEnd + 1, postEnd - 1, map);
        return root;
    }
}
```
