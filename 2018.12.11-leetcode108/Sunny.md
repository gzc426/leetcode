```java
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums == null || nums.length == 0)
            return null;
        int i = nums.length / 2;
        TreeNode node = new TreeNode(nums[i]);
        if (i > 0) {
            node.left = sortedArrayToBST(Arrays.copyOfRange(nums, 0, i));
            if (i+1 < nums.length) {
                node.right = sortedArrayToBST(Arrays.copyOfRange(nums, i+1, nums.length));
            }
        }
        return node;
    }
}
```
