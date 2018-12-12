##### 题目

```
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
```
##### 代码
递归
```
public boolean isSymmetric(TreeNode root) {
        if (root==null) {
            return true;
        }else{
            return isSymmetric(root.left,root.right);
        }
    }

    public boolean isSymmetricCore(TreeNode leftNode, TreeNode rightNode){
        if (leftNode==null && rightNode==null) {
            return true;
        }
        if (leftNode.val!=rightNode.val || leftNode==null || rightNode==null) {
            return false;
        }
        return isSymmetricCore(leftNode.left,rightNode.right) && isSymmetricCore(leftNode.right,rightNode.left);
    }
```
##### 非递归法

```
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root.left);
        stack.push(root.right);
        while(!stack.empty()) {
            TreeNode right = stack.pop();
            TreeNode left = stack.pop();
            if (left == null && right == null) continue;
            else if (left == null || right == null || right.val != left.val) return false;
            stack.push(left.left);
            stack.push(right.right);
            stack.push(left.right);
            stack.push(right.left);
        }
        return true;
    }
}
```
