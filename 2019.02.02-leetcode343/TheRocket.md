```java
class Solution {
    public int integerBreak(int n) {
        int[] dp = new int[n + 1];
        int half = n >> 1;
        for (int i = 1; i <= half; ++i) {
            for (int j = i; i + j <= n; ++j) {
                dp[i + j] = Math.max(dp[i + j], Math.max(i, dp[i]) * Math.max(j, dp[j]));
            }
        }
        return dp[n];
    }
}
```
