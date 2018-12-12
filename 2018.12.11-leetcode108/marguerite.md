LeetCode：108. 将有序数组转换为二叉搜索树（Java）

####将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

####本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

###给定有序数组: [-10,-3,0,5,9],
 
####一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 
      0
     / \
   -3   9  
   /   /
   
 -10  5
 
####这个题有点类似二分查找，根节点在正中间，左子树的根节点在左边一半数组的正中间，右子树的根节点在右边一半数组的正中间；于是可以递归解决：先确定根节点，然后构造左子树，然后构造右子树， 结束条件类似二分查找(low > high)。

```
/***
definition for a binary tree node.
public class TreeNode{
          int val;
          TreeNode left;
          TreeNode right;
          TreeNode(int x){val =x;}
}
**/

class Solution{
        public TreeNode sortedArrayToBST(int[] nums){
        if(nums == null){
            return null;
        }
        return convertTree(nums,0,nums.length-1);
        }
        
        public TreeNode convertTree(int[] nums,int l,int r){//l：数组左边；r：数组右边，包括l和r
        if(l<=r){
             int mid =(l+r)/2;
             TreeNode newNode = new TreeNode(nums[mid]);
             newNode.left = convertTree(nums,l,mid-1);
             newNode.right = convertTree(nums,mid+1,r);
             return newNode;
        }
        else{
            return null;
            }
        }
}
```
