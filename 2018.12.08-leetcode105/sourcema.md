# LeetCode 105
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
        public TreeNode buildTree(int[] preorder, int[] inorder) {

            TreeNode node=preInArrGenerateTree(preorder,inorder,0,preorder.length-1,0,inorder.length-1);
            return node;
        }
        public  TreeNode preInArrGenerateTree(int[] preArr,int[] inArr,int preStart,int preEnd,
                                                    int inStart,int inEnd) {
            if (preStart>preEnd) {
                return null;
            }
            TreeNode head = new TreeNode(preArr[preStart]);
            int index = findHeadInArr(inArr, inStart, inEnd,preArr[preStart]);
            head.left = preInArrGenerateTree(preArr, inArr, preStart + 1, preStart+index-inStart, inStart, index - 1);
            head.right = preInArrGenerateTree(preArr, inArr, preStart+index-inStart+1, preEnd, index+1, inEnd);
            return head;
        }

        public  int findHeadInArr(int[] inArr, int inStart, int inEnd,int target) {
            int index=0;
            for (int i = inStart; i <=inEnd; i++) {
                if (inArr[i] == target) {
                    index=i;
                    break;
                }

            }
            return index;

        }
    }
