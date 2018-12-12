```java
import java.util.*;

/**
 * 二叉树的层次遍历2
 *给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 *
 */
public class Tree11
{
    public static class TreeNode {
        int data;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            data = val;
        }
    }

    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        Stack<List<Integer>> stack = new Stack<>();

        if (root != null) {
            queue.offer(root);
        }

        while (!queue.isEmpty()) {
            //temp初始化要放在此处，每次循环之后要置空
            List<Integer> temp = new ArrayList<>();
            int level = queue.size();

            for (int i = 0; i < level; i++) {
                if (queue.peek().left != null)
                    queue.offer(queue.peek().left);

                if (queue.peek().right != null)
                    queue.offer(queue.peek().right);

                temp.add(queue.poll().data);
            }
            stack.push(temp);
        }

        while (!stack.isEmpty()) {
            list.add(stack.pop());
        }

        return list;
    }

    public static void main(String[] args) {
        TreeNode p = new TreeNode(4);
        p.left = new TreeNode(9);
        p.right = new TreeNode(20);
        p.right.left = new TreeNode(15);
        p.right.right = new TreeNode(7);

        Tree11 t = new Tree11();
        List<List<Integer>> list= t.levelOrderBottom(p);

        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + " ");
        }
    }
}
```