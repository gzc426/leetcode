```java
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        if (strs == null || strs.length == 0) {
            return 0;
        }
        int[][] dp = new int[m + 1][n + 1];
        for (String str : strs) {
            int[] nums = count(str);
            for (int i = m; i >= nums[0]; --i) {
                for (int j = n; j >= nums[1]; --j) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - nums[0]][j - nums[1]] + 1);
                }
            }
        }
        return dp[m][n];
    }

    private int[] count(String str) {
        int[] nums = new int[2];
        for (char c : str.toCharArray()) {
            if (c == '0') {
                ++nums[0];
            } else {
                ++nums[1];
            }
        }
        return nums;
    }
}
```
