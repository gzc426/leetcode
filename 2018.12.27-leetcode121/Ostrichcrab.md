```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int size = prices.size();
        if(size==0) return 0;
        int minn = prices[0];
        for(int i = 1; i < size; i++){
            ans = ans > prices[i]-minn ? ans : prices[i]-minn;
            minn = minn > prices[i] ? prices[i] : minn;
        }
        return ans;
    }
};
```
