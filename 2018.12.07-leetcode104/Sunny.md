```java
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        return Math.max(maxDepth(root.left, 1), maxDepth(root.right, 1));
    }
    
    public int maxDepth(TreeNode node, int level) {
        if (node != null) {
            level = Math.max(maxDepth(node.left, level+1), maxDepth(node.right, level+1));
        }
        return level;
    }
}
```
