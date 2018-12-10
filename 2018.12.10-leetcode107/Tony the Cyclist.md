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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        ArrayDeque<TreeNode> d = new ArrayDeque<>();
        List<List<Integer>> lists = new ArrayList<>();
        List<Integer> tmp = new ArrayList<>();
        if (root == null){
            return lists;
        }
        d.addFirst(root);
        int length = d.size();
        while (!d.isEmpty()){
            TreeNode node = d.pollLast();
            tmp.add(node.val);
            length --;
            if (node.left != null){
                d.addFirst(node.left);
            }
            if (node.right != null){
                d.addFirst(node.right);
            }
            if (length == 0){
                lists.add(new ArrayList<>(tmp));
                length = d.size();
                tmp.clear();

            }
        }
        Collections.reverse(lists);
        return lists;
    }
}
```
