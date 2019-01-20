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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();
        if (root != null) {
            dfs(root, String.valueOf(root.val), res);
        }
        return res;
    }

    private void dfs(TreeNode root, String path, List<String> res) {
        if (root.left == null && root.right == null) {
            res.add(path);
            return;
        }
        if (root.left != null) {
            dfs(root.left, path + "->" + root.left.val, res);
        }
        if (root.right != null) {
            dfs(root.right, path + "->" + root.right.val, res);
        }
    }
}
```
