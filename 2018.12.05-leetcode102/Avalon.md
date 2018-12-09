/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        //List<TreeNode> templist=new ArrayList<TreeNode>();//这个list 没有实现对应接口
        LinkedList<TreeNode> llist = new LinkedList<TreeNode>();//但是这个 linkedlist 实现了 deque 接口
        //LinkedList<TreeNode> templist = new LinkedList<TreeNode>();//临时队列-用于存放同一排
        if (root == null)return list;
        llist.add(root);
        TreeNode current;
        while (!llist.isEmpty() ) {
            List<Integer> templist = new ArrayList<Integer>();
            int templen = llist.size();
            for (int i=0;i<templen;i++){
                current = llist.poll();
                templist.add(current.val);
                if (current.left != null)
                    llist.add(current.left);
                if (current.right != null)
                    llist.add(current.right);
            }
            list.add(templist);
        }

        return list;
    }
}
