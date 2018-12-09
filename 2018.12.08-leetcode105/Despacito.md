# LeetCode 105 Construct Binary Tree from Preorder and Inorder Traversal
## 1. Description
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]

inorder = [9,3,15,20,7]

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
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder) == 0:
            return None
        if len(preorder) == 1:
            return TreeNode(preorder.pop(0))
        root = TreeNode(preorder.pop(0))
        root.left = self.buildTree(preorder[:inorder.index(root.val)], inorder[:inorder.index(root.val)])
        root.right = self.buildTree(preorder[inorder.index(root.val):], inorder[inorder.index(root.val)+1:])
        return root
```