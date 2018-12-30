```java
class Solution {
    private int i = 0;
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (postorder == null || postorder.length == 0)
            return null;
        if (postorder.length > i && inorder.length > 0) {
            int n = inorder.length-1;
            for (; n>=0; n--) {
                if (inorder[n] == postorder[postorder.length-1-i])
                    break;
            }
            if (n>=0) {
                TreeNode node = new TreeNode(postorder[postorder.length-1-i]);
                i++;
                if (postorder.length > i) {
                    node.right = buildTree(Arrays.copyOfRange(inorder, n+1, inorder.length), postorder);
                    if (postorder.length > i) {
                        node.left = buildTree(Arrays.copyOfRange(inorder, 0, n), postorder);
                    }
                }
                return node;
            }
        }
        return null;
    }
}
```
