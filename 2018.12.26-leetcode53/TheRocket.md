```java
class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = nums[0];
        int curSum = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            curSum = curSum > 0 ? curSum + nums[i] : nums[i];
            maxSum = Math.max(maxSum, curSum);
        }
        return maxSum;
    }
}
```
