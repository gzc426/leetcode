# LeetCode 122  
    class Solution {
    public int maxProfit(int[] prices) {//只要有差价就进行交易
        if (prices==null||prices.length==0||prices.length==1) {
			return 0;
		}
        int res=0;
        for (int i = 0; i < prices.length-1; i++) {
			if (prices[i+1]-prices[i]>0) {
				res+=prices[i+1]-prices[i];
			}
		}
        return res;
    }
}
