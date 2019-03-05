```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        int curSell = 0;
        int preSell = 0;
        int buy = -prices[0];
        for (int i = 1; i < prices.length; ++i) {
            int tmp = curSell;
            curSell = Math.max(curSell, buy + prices[i]);
            buy = Math.max(buy, preSell - prices[i]);
            preSell = tmp;
        }
        return curSell;
    }
}
```
