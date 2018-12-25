

```
public class OneHundredAndTwentyTwo {

    public static int maxProfit(int[] prices) {
        int sum = 0;
        for(int i = prices.length - 1;i>0;i--) {
            if(prices[i] <= prices[i-1]) {
                continue;
            } else {
                sum += prices[i] - prices[i-1];
            }
        }
        return sum;
    }
    public static void main(String[] args) {
        int[] nums = new int[] {7,6,5,9,1,3};
        System.out.println(maxProfit(nums));
    }
}

```
