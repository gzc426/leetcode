```java
class Solution {
    public int maxProfit(int[] prices) {
        return reMaxProfit(prices, 0);
    }
    private int reMaxProfit(int[] prices, int pos){
        if(pos >= prices.length){
            return 0;
        }
        int profit = 0;
        for(int buyDay = pos; buyDay < prices.length; buyDay++){
            int maxProfit = 0;
            for(int sellDay = buyDay + 1; sellDay < prices.length; sellDay++){
                if(prices[buyDay] < prices[sellDay]){
                    maxProfit = Math.max(maxProfit, prices[sellDay] - prices[buyDay] + reMaxProfit(prices, sellDay + 1));
                }
            }
            profit = Math.max(maxProfit, profit);
        }
        return profit;
        
    }
}
```
