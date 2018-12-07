[102. 二叉树的层次遍历] (https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]


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
 // TODO 解题关键：传递树高度
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if(root == null) return result;
        executor(root,result,0);
        return result;    
    }
    
    public void executor(TreeNode node,List<List<Integer>> result,int high){
        if(node == null) return;
        if(result.size() < high+1) result.add(new ArrayList<>());
        result.get(high).add(node.val);
        high++;
        executor(node.left,result,high);
        executor(node.right,result,high);
    }
}
```
