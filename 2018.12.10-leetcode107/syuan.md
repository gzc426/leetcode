##### 题目

```
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]
```
##### 递归

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res=new ArrayList<>();
        if (root==null) {
            return res;
        }
        levelOrderBottomHelper(res,root,0);
        return res;
    }

    public void levelOrderBottomHelper(List<List<Integer>> list,TreeNode node,int level){
        if (node==null) {
            return;
        }
        if (list.size()<=level) {
            list.add(0,new ArrayList<Integer>());
        }
        list.get(list.size()-level-1).add(node.val);
        levelOrderBottomHelper(list,node.left,level+1);
        levelOrderBottomHelper(list,node.right,level+1);

    }
}
```
##### 非递归

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
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
            resList.add(0,tempList);
        }
        return resList;
    }
}
```
