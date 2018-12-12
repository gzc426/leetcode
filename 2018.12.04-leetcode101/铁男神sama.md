



## 101.对称二叉树

>[https://leetcode-cn.com/problems/symmetric-tree/](https://leetcode-cn.com/problems/symmetric-tree/)

### 一、题目

给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 `[1,2,2,3,4,4,3]` 是对称的。

```
                    1
                   / \
                  2   2
                 / \ / \
                3  4 4  3
```

但是下面这个 `[1,2,2,null,3,null,3]` 则不是镜像对称的:

```
                    1
                   / \
                  2   2
                   \   \
                   3    3
```

### 二、思路

- 二叉树问题锁定递归

- 如何判定一棵树是否镜像：整棵树镜像=左子树镜像&&右子树镜像
  - [ ] 条件一：左孩子为空&&右孩子为空（没有孩子的情况）
  - [ ] 条件二：左孩子值==右孩子值（有两个孩子的情况）；（只有一个孩子的肯定不能互为镜像）
  - [ ] 条件三：左左值==右右值&&左右值==右左值

- 出口：root==null 返回true

### 三、题解

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
	public boolean isSymmetric(TreeNode root) {
            if (root == null)return true;//出口条件
            return isMirror(root.left, root.right);
	}
	
	public boolean isMirror(TreeNode left,TreeNode right){
            if(left==null&&right==null)return true;
            if(left==null||right==null)return false;
            if(left.val!=right.val)return false;
            return isMirror(left.left,right.right)&&isMirror(left.right,right.left);
    }
}
```



