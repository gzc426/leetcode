```java
  public int maxProfit(int[] prices) {

            int maxProfit=0;
            int tempProfit=0;

            for (int i=1;i<prices.length;i++){
                if((prices[i]-prices[i-1])+tempProfit>0){
                    tempProfit=tempProfit+(prices[i]-prices[i-1]);
                    if(tempProfit>maxProfit) maxProfit=tempProfit;
                }else{
                tempProfit=0;}
            }

            return maxProfit;
        }

```
