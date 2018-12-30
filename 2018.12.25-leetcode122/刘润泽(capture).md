```java
  public static int maxProfit(int[] prices) {

        int profit=0;
        int buyPosition=0;
        boolean isbuy = false; //还没有买入

        for (int i=0;i<prices.length-1;i++){
            if (!isbuy) {
                if (prices[i]<prices[i+1]){

                    buyPosition = i;
                    isbuy = true;
                    continue;
                }
                continue;
            }
            if (prices[i]>=prices[i+1]){

                isbuy=false;
                profit=profit+(prices[i]-prices[buyPosition]);
                continue;
            }
            if (i==prices.length-2&&isbuy){
                return profit+(prices[prices.length-1]-prices[buyPosition]);
            }

            continue;

        }

        return profit;
    }
```
