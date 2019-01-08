```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return true;
        }
        boolean changed = false;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i - 1] > nums[i]) {
                if (changed) {
                    return false;
                }
                changed = true;
                if (i - 2 >= 0 && nums[i - 2] > nums[i]) {
                    nums[i] = nums[i - 1];
                } else {
                    nums[i - 1] = nums[i];
                }
            }
        }
        return true;
    }
}
```
