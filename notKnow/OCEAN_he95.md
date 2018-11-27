```
class Solution {
    public int maxProfit(int[] prices) {
        int max = 0;
        //如果只有一个元素，直接返回0
        if(prices.length==1){
            return 0;
        }
        //如果有两个元素，并且第二个比第一个大的话，返回第二个减去第一个的值
        if(prices.length==2 && (prices[1]>prices[0])){
            return prices[1]-prices[0];
        }
        //三个以上的元素就要考虑对于max的更新
        for(int i=0;i<prices.length;i++){
            for(int j=i+1;j<prices.length;j++){
                if((prices[j]-prices[i])>max){
                    max = prices[j]- prices[i];
                }
            }
        }
        return max;
    }
}
```
