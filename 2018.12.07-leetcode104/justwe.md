class Solution {
    public int maxDepth(TreeNode root) {
       if(root==null)
           return 0;
        else{
            int lTree = maxDepth(root.left);
            int rTree = maxDepth(root.right);
            return java.lang.Math.max(lTree, rTree)+1;
        }
    }
}
