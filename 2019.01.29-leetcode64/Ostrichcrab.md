```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n+1][m+1];
        dp[0][0]=grid[0][0];
        for(int i = 1; i < n; i++) dp[i][0]=grid[i][0]+dp[i-1][0];
        for(int i = 1; i < m; i++) dp[0][i]=grid[0][i]+dp[0][i-1];
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                dp[i][j] = min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
            }
        }
        return dp[n-1][m-1];
    }
};
```
