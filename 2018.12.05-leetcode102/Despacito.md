# leetcode 102 Binary Tree Level Order Traversal
## 1. Description
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

            3
           / \
          9  20
             / \
            15  7
            
 return its level order traversal as:
```python
[
  [3],
  [9, 20],
  [15, 7] 
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
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        l = [root, '#']
        result = []
        level = []
        while len(l) > 1:
            curr = l.pop(0)
            if curr != '#':
                level.append(curr.val)
                if curr.left:
                    l.append(curr.left)
                if curr.right:
                    l.append(curr.right)
            else:
                l.append('#')
                result.append(level)
                level = []
        result.append(level)
        return result
```
