```
public class Solution {
    private static LinkedList<List<Integer>> result = new LinkedList<>();

    public static void traversalBinaryTree(TreeNode node) {
        if (node != null) {
            List<Integer> list = new ArrayList<>(node.getVal());
            list.add(node.getVal());
            result.addFirst(list);

            TreeNode left = node.getLeft();
            TreeNode right = node.getRight();
            traversalBinaryTree(left, 1);
            traversalBinaryTree(right, 1);
        }
    }

    public static void traversalBinaryTree(TreeNode node, int level) {
        if (node != null) {
            List<Integer> list;
            if (result.size() == level) {
                list = new ArrayList<>();
                result.addFirst(list);
            }else {
                list = result.get(result.size() - 1- level);
            }
            list.add(node.getVal());

            TreeNode left = node.getLeft();
            TreeNode right = node.getRight();

            traversalBinaryTree(left, level + 1);
            traversalBinaryTree(right, level + 1);
        }
    }

    public static void main(String[] args) {
        TreeNode r3r = new TreeNode(7, null, null);
        TreeNode r3l = new TreeNode(15, null, null);

//        TreeNode l3r = new TreeNode(18, null, null);
//        TreeNode l3l = new TreeNode(22, null, null);

        TreeNode l2r = new TreeNode(20, r3l, r3r);
        TreeNode l2l = new TreeNode(9, null, null);
        TreeNode root = new TreeNode(3, l2l, l2r);
        traversalBinaryTree(root);
        System.out.println(result);
    }
}

@Data
@AllArgsConstructor
@NoArgsConstructor
@ToString
class TreeNode {
    private int val;
    private TreeNode left;
    private TreeNode right;
