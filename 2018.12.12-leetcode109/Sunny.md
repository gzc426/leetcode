```java
class Solution {

    private List<Integer> list = new ArrayList<>();

    public TreeNode sortedListToBST(ListNode head) {
        if (head == null)
            return null;
        addToList(head, 0);
        return sortedListToBST(list);
    }

    private void addToList(ListNode node, int index) {
        if (node != null) {
            list.add(node.val);
            addToList(node.next, index+1);
        }
    }

    private TreeNode sortedListToBST(List<Integer> nums) {
        if (nums == null || nums.size() == 0)
            return null;
        int i = nums.size() / 2;
        TreeNode node = new TreeNode(nums.get(i));
        if (i > 0) {
            node.left = sortedListToBST(nums.subList(0, i));
            if (i+1 < nums.size()) {
                node.right = sortedListToBST(nums.subList(i+1, nums.size()));
            }
        }
        return node;
    }
}
```
