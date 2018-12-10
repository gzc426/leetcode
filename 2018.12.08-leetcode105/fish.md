```
public class Solution {
  public static TreeNode binaryTree(TreeNode node, List<Integer> preOrder, List<Integer> inOrder) {
    if (!preOrder.isEmpty()) {
      Integer val = preOrder.get(0);
      int preIndex = preOrder.indexOf(val);
      int inIndex = inOrder.indexOf(val);
      List<Integer> plOrder = preOrder.subList(preIndex + 1, inIndex + 1);
      List<Integer> prOrder = preOrder.subList(inIndex + 1, preOrder.size());

      List<Integer> ilOrder = inOrder.subList(0, inIndex);
      List<Integer> irOrder = inOrder.subList(inIndex + 1, inOrder.size());
      if (node == null) {
        node = new TreeNode(val, null, null);
      }
      TreeNode lnode = null,rnode = null;
      if (!plOrder.isEmpty()){
        lnode = new TreeNode(plOrder.get(0), null, null);
      }
      if (!prOrder.isEmpty()) {
        rnode = new TreeNode(prOrder.get(0), null, null);
      }
      node.setLeft(lnode);
      node.setRight(rnode);
      binaryTree(lnode, plOrder, ilOrder);
      binaryTree(rnode, prOrder, irOrder);
    }
    return node;
  }

  public static void main(String[] args) {
    List<Integer> preOrder = new ArrayList<>();
    preOrder.add(1);
    preOrder.add(4);
    preOrder.add(6);
    preOrder.add(8);
    preOrder.add(9);
    preOrder.add(10);
    preOrder.add(11);
    List<Integer> inOrder = new ArrayList<>();
    inOrder.add(6);
    inOrder.add(4);
    inOrder.add(1);
    inOrder.add(9);
    inOrder.add(8);
    inOrder.add(10);
    inOrder.add(11);
    System.out.println(binaryTree(null, preOrder, inOrder));
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