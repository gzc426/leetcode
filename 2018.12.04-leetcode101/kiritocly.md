    private static boolean solution(TreeNode root) {
        if (root == null) {
            return true;
        } else {
            //二叉树对称的条件
            //（1）左子树和右子树对称
            //（2）左子树的左子树和右子树的右子树对称
            //（3）左子树的右子树和右子树的左子树对称
            //递归判断
            return judge(root.leftNode, root.rightNode);
        }

    }

    private static boolean judge(TreeNode leftNode, TreeNode rightNode) {
        if (leftNode == null && rightNode == null) {
            return true;
        } else if (leftNode == null || rightNode == null) {
            return false;
        }
        //条件（1）
        if (leftNode.value != rightNode.value) {
            return false;
        }
        //条件（2）
        boolean flag1 = judge(leftNode.leftNode, rightNode.rightNode);
        //条件（3）
        boolean flag2 = judge(leftNode.rightNode, rightNode.leftNode);
        if (flag1 && flag2) {
            return true;
        }
        return false;
    }
