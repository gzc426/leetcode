class Solution {
    public int maxDepth(TreeNode root) {
         if (root == null)
            return 0;
        return depth(root);
    }

    private int depth(TreeNode root) {
        if (root == null)
            return 0;
        int left = depth(root.left);
        int right = depth(root.right);
        return left > right ? left+1 : right+1;
    }
}
