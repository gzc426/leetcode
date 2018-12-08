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
    public int maxDepth(TreeNode root) {
        int left;
        int right;
        if (root == null){
            return 0;
        }
        else {
            left = maxDepth(root.left) + 1;
            right = maxDepth(root.right) + 1;
        }
        return left > right ? left : right;
    }
}
```
