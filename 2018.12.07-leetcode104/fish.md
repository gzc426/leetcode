```
public class Solution {
    public static int deepOfTree(TreeNode treeNode, int level){
        if (treeNode == null) {
            return level;
        }
        int left = deepOfTree(treeNode.getLeft(), level + 1);
        int right = deepOfTree(treeNode.getRight(), level + 1);
        return  left > right ? left : right;
    }
    public static void main(String[] args) {
        TreeNode r4r = new TreeNode(21, null, null);
        TreeNode r4l = new TreeNode(22, null, null);

        TreeNode r3r = new TreeNode(7, null, null);
        TreeNode r3l = new TreeNode(15, r4l, r4r);
        TreeNode l2r = new TreeNode(20, r3l, r3r);
        TreeNode l2l = new TreeNode(9, null, null);
        TreeNode root = new TreeNode(3, l2l, l2r);
        System.out.println(deepOfTree(root, 0));
    }
}
@Data
@AllArgsConstructor
@NoArgsConstructor
class TreeNode{
    private int val;
    private TreeNode left;
    private TreeNode right;
}