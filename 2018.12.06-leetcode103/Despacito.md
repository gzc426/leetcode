# LeetCode 103 Binary Tree Zigzag Level Order Traversal
## 1. Description
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

        3
       / \
      9  20
         / \
        15  7

return its zigzag level order traversal as:
```python
[
  [3],
  [20,9],
  [15,7]
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
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        l = [root, '#']
        result = []
        level = []
        flag = 1
        while len(l) > 1:
            curr = l.pop(0)
            if curr != '#':
                if flag == 1:
                    level.append(curr.val)
                else:
                    level.insert(0, curr.val)
                if curr.left:
                    l.append(curr.left)
                if curr.right:
                    l.append(curr.right)
            else:
                l.append('#')
                result.append(level)
                level = []
                flag *= -1
        result.append(level)
        return result
```
