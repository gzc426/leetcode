```````
public class Solution {
    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        if (root == null) {
            return list;
        }
        levelOrder(list, root, 0);
        return list;
    }

    public static void levelOrder(List<List<Integer>> list, TreeNode node, int level) {
        if (node == null) {
            return;
        }
        if (list.size() < level + 1) {
            List<Integer> levelEle = new ArrayList<>();
            list.add(levelEle);
        }
        list.get(level).add(node.getVal());
        levelOrder(list, node.getLeft(), level + 1);
        levelOrder(list, node.getRight(), level + 1);
    }

    public static void main(String[] args) {
        TreeNode r3r = new TreeNode(7, null, null);
        TreeNode r3l = new TreeNode(15, null, null);
        TreeNode l2r = new TreeNode(20, r3l, r3r);
        TreeNode l2l = new TreeNode(9, null, null);
        TreeNode root = new TreeNode(3, l2l, l2r);
        System.out.println(levelOrder(root));
    }
}

@Data
@AllArgsConstructor
@NoArgsConstructor
class TreeNode {
    private Integer val;
    private TreeNode left;
    private TreeNode right;
}