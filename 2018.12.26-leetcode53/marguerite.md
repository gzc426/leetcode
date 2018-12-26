###求和，然后判断和是否小于0，

###因为只要前面的和小于0，那么后面的数加上前面的和就一定比自身小，所以又重新求和，

###并和之前的最大子序和比较，取最大值。


```

class Solution {
public:
    int maxSubArray(vector<int>& nums) {  
        int ans = 0, maxn = INT_MIN;  
        int len = nums.size();
        for(int i = 0; i < len; i++){  
            if(ans < 0) ans = 0;  //如果前面的和小0，那么重新开始求和
            ans += nums[i];  
            maxn = max(maxn, ans);   
        }  
        return maxn;  
    }  
    
    
```
