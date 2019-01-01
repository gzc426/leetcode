```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size == 0) return 0;
        int profit = 0;
        for(int i = 1; i < size; i++){
            profit += prices[i]>prices[i-1]?prices[i]-prices[i-1]:0;
        }
        return profit;
    }
};
```
