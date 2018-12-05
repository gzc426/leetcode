>```java
>/**
> * 二叉树的层次遍历1
> * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
> *
> */
>public class Tree10
>{
>    public static class TreeNode
>    {
>        int data;
>        TreeNode left;
>        TreeNode right;
>
>        TreeNode(int val)
>        {
>            data = val;
>        }
>    }
>
>    public List<List<Integer>> levelOrder(TreeNode root)
>    {
>        //JAVA泛型，List里面存储List，就可以有[[3], [9, 20], [15, 7]]
>        List<List<Integer>> list = new ArrayList<>();
>        List<Integer> temp = new ArrayList<>();
>
>        Queue<TreeNode> queue = new LinkedList<>();
>
>        if (root != null)
>        {
>            queue.offer(root);
>        }
>
>        int width = 1;
>
>        while (!queue.isEmpty())
>        {
>            TreeNode node = queue.poll();
>            temp.add(node.data);
>            width--;
>
>            if (node.left != null)
>                queue.add(node.left);
>
>            if (node.right != null)
>                queue.add(node.right);
>
>            if (width == 0)
>            {
>                list.add(temp);
>                temp = new ArrayList<>();
>                width = queue.size();
>            }
>
>        }
>
>        return list;
>    }
>
>    public static void main(String[] args)
>    {
>        TreeNode p = new TreeNode(3);
>        p.left = new TreeNode(9);
>        p.right = new TreeNode(20);
>        p.right.left = new TreeNode(15);
>        p.right.right = new TreeNode(7);
>
>        Tree10 t = new Tree10();
>
>        List<List<Integer>> list= t.levelOrder(p);
>        for (int i = 0; i < list.size(); i++)
>        {
>            System.out.print(list.get(i) + " ");
>        }
>
>    }
>
>}
>```

