# LeetCode 106
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
        public TreeNode buildTree(int[] inorder, int[] postorder) {
            TreeNode node=InPosArrGenerateTree(inorder,postorder,0,inorder.length-1,0,postorder.length-1);
            return node;
        }
        public TreeNode InPosArrGenerateTree(int[] inArr,int[] posArr,int inStart,int inEnd,
                                                    int posStart,int posEnd) {//中序和后序
            if (posStart>posEnd) {
                return null;
            }
            TreeNode head = new TreeNode(posArr[posEnd]);
            int index = findHeadInArr(inArr, inStart, inEnd,posArr[posEnd]);
            head.left = InPosArrGenerateTree(inArr, posArr, inStart,index-1, posStart, posStart+index-1-inStart);
            head.right = InPosArrGenerateTree(inArr, posArr, index+1, inEnd, posStart+index-inStart, posEnd-1);
            return head;
        }
        public int findHeadInArr(int[] inArr, int inStart, int inEnd,int target) {
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
