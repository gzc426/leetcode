###107. Binary Tree Level Order Traversal

###Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

###给定二叉树，返回其节点值的自下而上级别顺序遍历。（从左到右，逐级从叶到根）。

###For example:

###Given binary tree {3,9,20,#,#,15,7},

###    3
      / \
     9  20
        /  \
       15   7
   
###return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

```
  public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> result = new LinkedList<List<Integer>>();

        if (root == null) {
            return result;
        }
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        int i = queue.size(); // 记录每层的结点个数
        TreeNode tempNode = null;
        List<Integer> singleLevel = new ArrayList<>();
        while (!queue.isEmpty()) {
            if (i == 0) {// 一层记录结束
                //
                result.addFirst(singleLevel);

                i = queue.size();
                singleLevel = new ArrayList<>();
            }
            tempNode = queue.poll();
            singleLevel.add(tempNode.val);

            --i;

            if (tempNode.left != null) {
                queue.add(tempNode.left);
            }
            if (tempNode.right != null) {
                queue.add(tempNode.right);
            }

        }
        result.addFirst(singleLevel);
        return result;
    }
```
