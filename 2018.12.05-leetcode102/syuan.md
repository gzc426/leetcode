##### 题目
```
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]


```
##### 代码
循环
```
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
        List<List<Integer>> resList=new ArrayList<>();
        Queue<TreeNode> queue=new LinkedList<>();
        if (root==null) {
            return resList;
        }

        queue.offer(root);
        while(!queue.isEmpty()){
            int length=queue.size();
            List<Integer> tempList=new ArrayList<>();
            for (int i=0; i<length; i++) {
                if (queue.peek().left!=null) {
                    queue.offer(queue.peek().left);
                }
                if (queue.peek().right!=null) {
                    queue.offer(queue.peek().right);
                }
                tempList.add(queue.poll().val);
            }
            resList.add(tempList);
        }
        return resList;
    }
}
```
递归

```
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
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        levelOrderHelper(res, root, 0);
        return res;
    }

    public void levelOrderHelper(List<List<Integer>> res,TreeNode root,int length){
        if (root==null) {
            return;
        }
        if (length>=res.size()) {
            res.add(new ArrayList<Integer>());
        }
        res.get(length).add(root.val);
        levelOrderHelper(res,root.left,length+1);
        levelOrderHelper(res,root.right,length+1);
    }

}
```
