```java
class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum < S || ((S + sum) & 1) == 1) {
            return 0;
        }
        return subsetSum(nums, (S + sum) >> 1);
    }

    private int subsetSum(int[] nums, int sum) {
        int[] dp = new int[sum + 1];
        dp[0] = 1;
        for (int num : nums) {
            for (int i = sum; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }
        return dp[sum];
    }
}
```
