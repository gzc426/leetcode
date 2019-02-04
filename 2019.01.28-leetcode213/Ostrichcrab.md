```
//This problem is a little tricky at first glance. However, if you have finished the House Robber problem, this problem can simply be decomposed into two House Robber problems.
// Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them together and thus the solution is now the maximum of

// Rob houses 0 to n - 2;
// Rob houses 1 to n - 1.
// The code is as follows. Some edge cases (n < 2) are handled explicitly.
class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = -1;
        vector<int> a;
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            a.push_back(nums[i]);
        }
        nums.pop_back();
        ans = robber(a)>robber(nums)?robber(a):robber(nums);
        return ans;
    }
    int robber(vector<int>& a) {
        int n = a.size();
        if(n==0) return 0;
        int dp[n+2];
        dp[0]=a[0];
        if(n==1) return a[0];
        dp[1]=max(a[0],a[1]);
        for(int i = 2; i < n; i++)
        {
            dp[i]=max(dp[i-2]+a[i],dp[i-1]);
        }
        return dp[n-1];
    }
};
```
