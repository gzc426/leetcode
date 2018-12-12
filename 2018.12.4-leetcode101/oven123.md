```java

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
    public boolean isSymmetric(TreeNode root) {
      
        return compareTree(root,root);
    }
    boolean compareTree(TreeNode tree1,TreeNode tree2){
        if(tree1==null&&tree2==null)//递归到最内层同时为空
            return true;
        if(tree1==null||tree2==null)//如果有其中一个为空但另一个不为空
            return false;
        return(tree1.val==tree2.val)
          &&compareTree(tree1.left,tree2.right)
            &&compareTree(tree1.right,tree2.left); 
        
           
    }
}

```
