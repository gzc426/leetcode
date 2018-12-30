```java
class Solution {
    List<List<Integer>> result = new ArrayList<>();
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        zigzagLevelOrder(root, 0, false);
        return result;
    }
    
    public void zigzagLevelOrder(TreeNode node, int level, boolean inverse) {
        if (node != null) {
            if (result.size() <= level) {
                result.add(new ArrayList<>());
            }
            if (inverse) {
                result.get(level).add(0, node.val);
            }
            else {
                result.get(level).add(node.val);
            }
            zigzagLevelOrder(node.left, level+1, !inverse);
            zigzagLevelOrder(node.right, level+1, !inverse);
        }
    }
}
```
