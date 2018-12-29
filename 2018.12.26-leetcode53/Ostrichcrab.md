```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size+1);
        dp[0] = nums[0];
        int ans = nums[0];
        for(int i = 1; i<size; i++){
            if(dp[i-1]>0) dp[i]=nums[i]+dp[i-1];
            else dp[i] = nums[i];
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
```
