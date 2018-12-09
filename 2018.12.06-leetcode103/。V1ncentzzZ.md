[103. 二叉树的锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
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
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if(root == null) return result;
        executor(root, result, 0);
        return result;
    }
    
    public void executor(TreeNode node,List<List<Integer>> result,int high){
        if(node == null) return;
        if(result.size() <= high) result.add(new ArrayList<>());
        if(high % 2 == 0){
           result.get(high).add(node.val); 
        }else {
            result.get(high).add(0,node.val); 
        }
        executor(node.left, result, high+1); 
        executor(node.right, result, high+1);
    }
}
```
