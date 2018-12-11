/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.List;
import java.util.Stack;

class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> list = new LinkedList<>();
        Stack<List<Integer>> stack = new Stack<>();
        if (root == null)
            return list;
        levelOrderBottom(root,stack,0);
        while (!stack.empty())
            list.add(stack.pop());
        return list;
    }

    private void levelOrderBottom(TreeNode root, Stack<List<Integer>> stack, int level) {
        if (root == null){
            return;
        }
        if (stack.size() == level){
            List<Integer> temp = new LinkedList<>();
            temp.add(root.val);
            stack.push(temp);
        }else {
            stack.get(level).add(root.val);
        }
        levelOrderBottom(root.left,stack,level+1);
        levelOrderBottom(root.right,stack,level+1);
    }
}
