```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length <= 1){
            return 0;
        }
        for(int i = prices.length - 1; i > 0; i--){
            prices[i] = prices[i] - prices[i - 1];
        }
        prices[0] = 0;
        return maxSubProfit(prices, 0, prices.length - 1);
    }
    public int maxSubProfit(int[] prices, int begin, int end){
        if(begin == end){
            return prices[begin];
        }
        else{
            int mid = (begin + end) / 2;
            int leftSum = maxSubProfit(prices, begin, mid);
            int rightSum = maxSubProfit(prices, mid + 1, end);
            int crossSum = maxCrossProfit(prices, begin, mid, end);
            return Math.max(Math.max(leftSum, rightSum), crossSum);
        }
    }
    public int maxCrossProfit(int[] prices, int begin, int mid, int end){
        int leftSum = Integer.MIN_VALUE;
        int sum = 0;
        for(int i = mid; i >= begin; i--){
            sum += prices[i];
            if(sum > leftSum){
                leftSum = sum;
            }
        }
        int rightSum = Integer.MIN_VALUE;
        sum = 0;
        for(int i = mid + 1; i <= end; i++){
            sum += prices[i];
            if(sum > rightSum){
                rightSum = sum;
            }
        }
        return leftSum + rightSum;
    }
}
```
