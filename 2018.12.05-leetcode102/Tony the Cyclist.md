```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.*;
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null){
            return new ArrayList<>();
        }
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> tmp = new ArrayList<>();
        ArrayDeque<TreeNode> d = new ArrayDeque<>();
        tmp.add(root.val);
        list.add(new ArrayList<>(tmp));
        tmp.clear();
        if (root.left != null){
            d.addFirst(root.left);
        }
        if (root.right != null){
            d.addFirst(root.right);
        }
        int level = d.size();
        while (!d.isEmpty()){
            TreeNode node = d.pollLast();
            tmp.add(node.val);
            level--;
            if (node.left != null){
                d.addFirst(node.left);
            }
            if (node.right != null){
                d.addFirst(node.right);
            }
            if (level == 0){
                if (!tmp.isEmpty())
                    list.add(new ArrayList<>(tmp));
                level = d.size();
                tmp.clear();
            }
        }
        return list;
    }
}
```
