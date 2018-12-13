



## 104.二叉树最大深度

> [https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

### 一、题目

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

**说明:** 叶子节点是指没有子节点的节点。

**示例：**给定二叉树 `[3,9,20,null,null,15,7]`，

```
                3
               / \
              9  20
                /  \
               15   7
```

返回它的最大深度 3 。

### 二、思路

- 二叉树问题锁定递归
- 最大深度=左子树最大深度，右子树最大深度，中的大的那个
- 递归出口：root==null 返回0

### 三、题解

#### 递归解法

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public int maxDepth(TreeNode root) {
         if(root==null) return 0;
         return Math.max(maxDepth(root.left),maxDepth(root.right))+1;
    }
```

#### 非递归解法

```java
public int maxDepth(TreeNode root) {
        if(root==null) return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int level=1;
        while(!q.isEmpty()){
            int size = q.size();
            while(size-->0){
                TreeNode popNow = q.poll();
                if(popNow.left!=null){
                    q.offer(popNow.left);
                }
                 if(popNow.right!=null){
                    q.offer(popNow.right);
                }
            }
            level++;
        }
        return level-1;
    }
```

