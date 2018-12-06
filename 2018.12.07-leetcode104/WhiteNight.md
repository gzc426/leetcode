>```java
>/**
> * 给定一个二叉树，找出其最大深度。
> *
> * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
> *
> * 说明: 叶子节点是指没有子节点的节点。
> *
> */
>public class Tree1
>{
>    public static class TreeNode
>    {
>        int data;
>        TreeNode left;
>        TreeNode right;
>        TreeNode(int val)
>        {
>            data = val;
>        }
>    }
>
>    public int maxDepth(TreeNode root)
>    {
>        if (root == null)
>            return 0;
>
>        int nleft = maxDepth(root.left);
>        int nright = maxDepth(root.right);
>
>        return nleft > nright ? nleft + 1 : nright + 1;
>    }
>
>    public static void main(String[] args)
>    {
>        TreeNode p = new TreeNode(1);
>        p.left = new TreeNode(2);
>        p.right = new TreeNode(3);
>        p.left.left = null;
>        p.left.right = null;
>        p.right.left = new TreeNode(4);
>        p.right.right = new TreeNode(5);
>
>        Tree1 t = new Tree1();
>        System.out.println(t.maxDepth(p));
>    }
>}
>```

