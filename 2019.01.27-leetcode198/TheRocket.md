```java
class Solution {
    public int rob(int[] nums) {
        int pre2 = 0;
        int pre1 = 0;
        int cur = 0;
        for (int num : nums) {
            cur = Math.max(pre2 + num, pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
}
```
