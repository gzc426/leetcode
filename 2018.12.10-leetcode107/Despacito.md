# LeetCode 107 Binary Tree Level Order Traversal II
## 1. Description

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],

      3
     / \
    9  20
      /  \
     15   7
     
return its bottom-up level order traversal as:

```
[
  [15,7],
  [9,20],
  [3]
]
```

## 2. Solution
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None:
            return []
        tmp = [root, '#']
        level = []
        result = []
        while len(tmp) > 1:
            head = tmp.pop(0)
            if head != '#':
                level.append(head.val)
                if head.left:
                    tmp.append(head.left)
                if head.right:
                    tmp.append(head.right)
            else:
                tmp.append('#')
                result.insert(0, level)
                level = []
        result.insert(0, level)
        return result
```