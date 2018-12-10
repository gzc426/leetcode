```java
class Solution {
    
    private List<List<Integer>> result = new ArrayList<>();
    
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        levelOrderBottom(root, 0);
        return result;
    }
    
    public void levelOrderBottom(TreeNode node, int level) {
        if (node != null) {
            if (result.size() <= level) {
                result.add(0, new ArrayList<>());
            }
            result.get(result.size() - 1 - level).add(node.val);
            levelOrderBottom(node.left, level+1);
            levelOrderBottom(node.right, level+1);
        }
    }
}
```
