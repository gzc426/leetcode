```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxn = 0;
        int minn = 100000;
        int dest = 0;
        for(int i = 0; i < prices.length; i++){
            minn = minn < prices[i]? minn: prices[i];
            maxn = prices[i];
            dest = maxn-minn > dest? maxn-minn: dest;
        }
        return dest;
    }
}
```
