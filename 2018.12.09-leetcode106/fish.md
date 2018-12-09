```
public class Solution {
    public static TreeNode binaryTree(TreeNode node, List<Integer> aftOrder, List<Integer> inOrder) {
        if (!aftOrder.isEmpty()){
            int size = aftOrder.size();
            Integer val = aftOrder.get(aftOrder.size() - 1);
            int index = inOrder.indexOf(val);

            List<Integer> leftAftOrder = aftOrder.subList(0, index);
            List<Integer> rightAftOrder = aftOrder.subList(index, size - 1);

            List<Integer> leftInOrder = inOrder.subList(0, index);
            List<Integer> rightInOrder = inOrder.subList(index + 1, size);

            if (node == null) {
                node = new TreeNode(val, null, null);
            }

            TreeNode leftNode = null, rightNode = null;
            if (!leftAftOrder.isEmpty()){
                leftNode = new TreeNode(leftAftOrder.get(leftAftOrder.size() - 1), null, null);
                node.setLeft(leftNode);
            }
            if (!rightAftOrder.isEmpty()){
                rightNode = new TreeNode(rightAftOrder.get(rightAftOrder.size() - 1), null, null);
                node.setRight(rightNode);
            }

            binaryTree(leftNode, leftAftOrder, leftInOrder);
            binaryTree(rightNode, rightAftOrder, rightInOrder);
        }
        return node;
    }

    public static void main(String[] args) {
        List<Integer> aftOrder = new ArrayList<>();
        aftOrder.add(22);
        aftOrder.add(16);
        aftOrder.add(9);
        aftOrder.add(15);
        aftOrder.add(7);
        aftOrder.add(20);
        aftOrder.add(3);
        List<Integer> inOrder = new ArrayList<>();
        inOrder.add(22);
        inOrder.add(9);
        inOrder.add(16);
        inOrder.add(3);
        inOrder.add(15);
        inOrder.add(20);
        inOrder.add(7);
        System.out.println(binaryTree(null, aftOrder, inOrder));
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
}