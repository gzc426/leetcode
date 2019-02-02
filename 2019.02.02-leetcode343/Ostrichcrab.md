```
class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i = 2; i <= n; i++)
        {
            dp[i]=-1;
            for(int j = 1; j < i; j++)
            {
                dp[i]=max(dp[i-j]*j,max(dp[i],j*(i-j)));
            }
        }
        return dp[n];
    }
};
```
