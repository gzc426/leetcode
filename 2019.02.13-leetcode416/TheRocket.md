```java
public boolean canPartition(int[] nums) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    if ((sum & 1) == 1) {
        return false;
    }
    sum /= 2;
    boolean[] dp = new boolean[sum + 1];
    dp[0] = true;
    for (int num : nums) {
        for (int i = sum; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
            if (dp[sum]) {
                return true;
            }
        }
    }
    return false;
}
```
