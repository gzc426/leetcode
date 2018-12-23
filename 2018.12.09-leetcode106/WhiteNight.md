```java
/**
 * 从中序与后序遍历序列构造二叉树
 */
public class Tree17 {
    public static class TreeNode {
        int data;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            data = val;
        }
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (postorder == null || inorder == null || postorder.length == 0)
            return null;
        return buildCore(postorder, 0,postorder.length - 1,inorder, 0, inorder.length - 1);
    }

    private TreeNode buildCore(int[] postorder, int postSt, int postEnd, int[] inorder, int inSt, int inEnd){
        int rootValue = postorder[postEnd];
        TreeNode root = new TreeNode(rootValue);

        if (postSt == postEnd)
            return root;

        int rootInorder = inSt;
        while (inorder[rootInorder] != rootValue && rootInorder <= inEnd)
            rootInorder++;

        int leftLength = rootInorder - inSt; //左子树的长度
        int leftPostEnd = postSt + leftLength - 1; //后序序列中左子树的最后一个节点

        // 左子树非空
        if (leftLength > 0){
            root.left = buildCore(postorder,postSt, leftPostEnd, inorder, inSt, rootInorder-1);
        }

        // 右子树非空
        if (leftLength < postEnd - postSt){
            root.right = buildCore(postorder, leftPostEnd+1, postEnd-1, inorder, rootInorder+1, inEnd);
        }

        return root;
    }

    private void inOrder(TreeNode root){
        if (root != null){
            inOrder(root.left);
            System.out.print(root.data + " ");
            inOrder(root.right);
        }
    }

    public static void main(String[] args) {
        Tree17 t = new Tree17();
        int[] inorder = {9, 3, 15, 20, 7};
        int[] postorder = {9, 15, 7, 20, 3};
        TreeNode resTree = t.buildTree(inorder, postorder);
        t.inOrder(resTree);
    }
}
```