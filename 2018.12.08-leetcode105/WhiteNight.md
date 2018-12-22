```java
public class Tree16 {
    public static class TreeNode {
        int data;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            data = val;
        }
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || inorder == null || preorder.length == 0)
            return null;
        return buildCore(preorder, 0,preorder.length - 1,inorder, 0, inorder.length - 1);
    }

    private TreeNode buildCore(int[] preorder, int preSt, int preEnd, int[] inorder, int inSt, int inEnd){
        int rootValue = preorder[preSt];
        TreeNode root = new TreeNode(rootValue);

        if (preSt == preEnd)
            return root;

        int rootInorder = inSt;
        while (inorder[rootInorder] != rootValue && rootInorder <= inEnd)
            rootInorder++;

        int leftLength = rootInorder - inSt; //左子树的长度
        int leftPreEnd = preSt + leftLength; //前序序列中左子树的最后一个节点

        // 左子树非空
        if (leftLength > 0){
            root.left = buildCore(preorder,preSt+1, leftPreEnd, inorder, inSt, rootInorder-1);
        }

        // 右子树非空
        // preEnd 和preSt是前序数组的结尾和开头，相减就是长度，如果左子树长度小于整个长度，那么说明右子树肯定存在。
        // 那么对右子树也进行同样的构建树的操作。
        if (leftLength < preEnd - preSt){
            root.right = buildCore(preorder, leftPreEnd+1, preEnd, inorder, rootInorder+1, inEnd);
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
        Tree16 t = new Tree16();
        int[] preorder = {3, 9, 20, 15, 7};
        int[] inorder = {9, 3, 15, 20, 7};
        TreeNode resTree = t.buildTree(preorder, inorder);
        t.inOrder(resTree);
    }
}
```