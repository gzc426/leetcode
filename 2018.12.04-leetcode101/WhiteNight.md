>```java
>/**
> *给定一个二叉树，检查它是否是镜像对称的。
> *
> */
>public class Tree9
>{
>    public static class TreeNode
>    {
>        int data;
>        TreeNode left;
>        TreeNode right;
>
>        TreeNode(int val) {
>            data = val;
>        }
>    }
>
>    public boolean isSymmetric(TreeNode root)
>    {
>        if (root == null)
>            return true;
>        return checkIsSymmetric(root.left, root.right);
>    }
>
>    public static boolean checkIsSymmetric(TreeNode leftNode, TreeNode rightNode)
>    {
>        if (leftNode == null && rightNode == null)
>            return true;
>        if ((leftNode == null && rightNode != null) || (leftNode != null && rightNode == null))
>            return false;
>        if (leftNode.data != rightNode.data)
>            return false;
>        return checkIsSymmetric(leftNode.left, rightNode.right) && checkIsSymmetric(leftNode.right, rightNode.left);
>    }
>
>    public static void main(String[] args)
>    {
>        TreeNode p = new TreeNode(1);
>        p.left = new TreeNode(2);
>        p.right = new TreeNode(2);
>        p.left.left = new TreeNode(3);
>        p.right.right = new TreeNode(3);
>
>        TreeNode q = new TreeNode(1);
>        q.left = new TreeNode(2);
>        q.right = new TreeNode(2);
>        q.left.right = new TreeNode(3);
>        q.right.right = new TreeNode(3);
>
>        Tree9 t = new Tree9();
>        System.out.println(t.isSymmetric(p));
>        System.out.println(t.isSymmetric(q));
>
>    }
>
>}
>```