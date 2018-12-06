# LeetCode 106 Construct Binary Tree from Inorder and Postorder Traversal
## 1. Description

Given inorder and postorder traversal of a tree, construct the binary tree.

**Note:**

You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]

postorder = [9,15,7,20,3]

Return the following binary tree:

      3
     / \
    9  20
      /  \
     15   7

## 2. Solution
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if len(postorder) == 0:
            return None
        if len(postorder) == 1:
            return TreeNode(postorder[0])
        root = TreeNode(postorder.pop())
        root.left = self.buildTree(inorder[:inorder.index(root.val)], postorder[:inorder.index(root.val)])
        root.right = self.buildTree(inorder[inorder.index(root.val)+1:], postorder[inorder.index(root.val):])
        return root
```