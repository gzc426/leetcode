# LeetCode 53
    class Solution {
    public int maxSubArray(int[] nums) {//简单的dp思想，如果累加和<0，保存最大值，重新进行累加
         if (nums == null || nums.length == 0) {
            return 0;
        }
        int sum=0,max=Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            max = Math.max(sum, max);
            sum=sum<0?0:sum;
        }
        return max;
    }
}
