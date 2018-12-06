# leetcode 101 Symmetric Tree
## 1. Description
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

                  1
                 / \
                2   2
               / \ / \
              3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

                  1
                 / \
                2   2
                 \   \
                 3    3

**Note:**

Bonus points if you could solve it both recursively and iteratively.

## 2. Solution
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        return self.comroot(root.left, root.right)
    
    def comroot(self, left, right):
        if left == None and right == None:
            return True
        elif left == None or right == None:
            return False
        elif left.val != right.val:
            return False
        return self.comroot(left.left, right.right) and self.comroot(left.right, right.left)
```