```java
class Solution {

    private int i = 0;
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || preorder.length == 0)
            return null;
        int val = preorder[i];
        int index = inorder.length - 1;
        for (; index >= 0; index--) {
            if (inorder[index] == val) {
                break;
            }
        }
        if (index >= 0) {
            TreeNode node = new TreeNode(val);
            i++;
            if (inorder.length > 1 && i < preorder.length) {
                node.left = buildTree(preorder, Arrays.copyOfRange(inorder, 0, index));
                if (i < preorder.length) {
                    node.right = buildTree(preorder, Arrays.copyOfRange(inorder, index+1, inorder.length));
                }
            }
            return node;
        }
        return null;
    }
}
```
