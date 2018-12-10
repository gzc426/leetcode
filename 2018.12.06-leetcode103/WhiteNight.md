```java
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。
 * 即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行
 *
 */
public class Tree15 {
    public static class TreeNode {
        int data;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            data = val;
        }
    }

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        TreeNode pNode = root;
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        List<Integer> list = new ArrayList<>();
        List<List<Integer>> resultList = new ArrayList<>();

        if (pNode == null)
            return resultList;

        stack1.push(pNode);

        while (!stack1.isEmpty() || !stack2.isEmpty()){
            while (!stack1.isEmpty()){
                TreeNode tempNode = stack1.pop();
                if (tempNode.left != null){
                    stack2.push(tempNode.left);
                }
                if (tempNode.right != null){
                    stack2.push(tempNode.right);
                }
                list.add(tempNode.data);
                if (stack1.isEmpty()){
                    resultList.add(new ArrayList<>(list));
                    list.clear();
                }
            }

            while (!stack2.isEmpty()){
                TreeNode tempNode = stack2.pop();
                if (tempNode.right != null){
                    stack1.push(tempNode.right);
                }
                if (tempNode.left != null){
                    stack1.push(tempNode.left);
                }
                list.add(tempNode.data);
                if (stack2.isEmpty()){
                    resultList.add(new ArrayList<>(list));
                    list.clear();
                }
            }
        }

        return resultList;
    }

    public static void main(String[] args) {
        TreeNode p = new TreeNode(4);
        p.left = new TreeNode(9);
        p.right = new TreeNode(20);
        p.right.left = new TreeNode(15);
        p.right.right = new TreeNode(7);

        Tree15 t = new Tree15();
        List<List<Integer>> list= t.zigzagLevelOrder(p);

        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + " ");
        }
    }
}
```