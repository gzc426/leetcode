[104. 二叉树的最大深度][https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/]

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，
```
   3
   / \
  9  20
    /  \
   15   7
```
返回它的最大深度 3 。

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
//     public int maxDepth(TreeNode root) {
//         if(root == null) return 0;
//         return getDepth(root.left,root.right,1);
//     }
    
//     public int getDepth(TreeNode node1,TreeNode node2,int high){
//         if(node1 == null && node2 == null) return high;
//         high++;
//         if(node1 == null) return getDepth(node2.left,node2.right,high);
//         if(node2 == null) return getDepth(node1.left,node1.right,high);
//         return Math.max(getDepth(node1.left,node1.right,high),getDepth(node2.left,node2.right,high));
//     }
    
    public int maxDepth(TreeNode root) {
        if(root == null) return 0;
        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        return 1 + (left > right ? left : right);
    }
}
```
