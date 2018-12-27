# LeetCode 121
    class Solution {
    public int maxProfit(int[] stocks) {//找数组中前后差值最大的结果
        if (stocks.length == 0 || stocks == null) {
            return 0;
        }
        int[] mins = new int[stocks.length];
        int[] maxs = new int[stocks.length];
        mins[0] = stocks[0];
        maxs[stocks.length-1] = stocks[stocks.length-1];
        int res=Integer.MIN_VALUE;
        for (int i = 1; i < stocks.length; i++) {
            mins[i] = Math.min(mins[i - 1], stocks[i]);
        }
        for (int i =stocks.length-2 ; i >=0; i--) {
            maxs[i] = Math.max(maxs[i + 1], stocks[i]);
        }
        for (int i = 0; i < stocks.length; i++) {
            res = Math.max(res, maxs[i] - mins[i]);
        }
        return res;
    }
}
