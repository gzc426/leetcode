
###遇到临时最小的，就保存（1），计算后面比它大的差，

###保留最大（6-1），遇到后面如果有更小的（0），就保存（0），重复上面工作即可。

```


public int maxProfit2(int[] prices) {
        if(prices==null||prices.length<=1){
        	return 0;
        }
        int res=0,temp,inv;
        temp=prices[0];
        for(int i=1;i<prices.length;i++){
        	inv=prices[i];
        	if(temp>inv){
        		temp=inv;
        	}else{
        		inv=inv-temp;
        		res=res>inv?res:inv;
        	}
        }
        return res;


```
