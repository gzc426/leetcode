递归
```java
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null){
            return true;
        }
        else {
            if (check(root.left, root.right)){
                return true;
            }
            else {
                return false;
            }
        }
    }

    public static boolean check(TreeNode node1, TreeNode node2){
        if (node1 == null && node2 == null){
            return true;
        }
        else if (node1 == null || node2 == null){
            return false;
        }
        return node1.val == node2.val && check(node1.right, node2.left) && check(node1.left, node2.right);
    }
}
```
非递归
```java
import java.util.*;
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if ((root == null) || (root.left == null && root.right == null)){
            return true;
        }
        else if (root.left == null || root.right == null){
            return false;
        }
        else {
            ArrayDeque<TreeNode> d = new ArrayDeque<TreeNode>();
            d.addFirst(root.left);
            d.addLast(root.right);
            while (d.size() != 0){
                TreeNode leftnode = d.pollFirst();
                TreeNode rightnode = d.pollLast();
                if (leftnode == null && rightnode == null){
                    return true;
                }
                else if (leftnode == null || rightnode == null){
                    return false;
                }
                else if (leftnode.val != rightnode.val){
                    return false;
                }
                else {
                    if (rightnode.right != null && leftnode.left != null){
                        d.addLast(rightnode.right);
                        d.addFirst(leftnode.left);
                    }
                    else if (rightnode.right == null && leftnode.left == null){

                    }
                    else {
                        return false;
                    }
                    if (rightnode.left != null && leftnode.right != null){
                        d.addFirst(rightnode.left);
                        d.addLast(leftnode.right);
                    }
                    else if (rightnode.left == null && leftnode.right == null){

                    }
                    else {
                        return false;
                    }
                }
            }
            return true;
        }
    }
}
```
