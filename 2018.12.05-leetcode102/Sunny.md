```java
class Solution {
    
    private List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> levelOrder(TreeNode root) {
        levelOrder(root, 0);
        return result;
    }
    
    public void levelOrder(TreeNode node, int level) {
        if (node != null) {
            if (result.size() <= level) {
                result.add(new ArrayList<Integer>());
            }
            result.get(level).add(node.val);
            levelOrder(node.left, level+1);
            levelOrder(node.right, level+1);
        }
    }
}
```
