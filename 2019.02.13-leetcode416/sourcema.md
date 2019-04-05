# leetcode 416
    public  boolean canPartition2(int[] nums) {
        if (nums.length == 0) {
            return true;
        }
        if (nums.length == 1) {
            return false;
        }
        int ret=0;
        for (int i:nums){
            ret+=i;
        }
        if ((ret & 1) == 1) {
            return false;
        }
        int mid=ret/2;
        boolean[] dp = new boolean[mid + 1];
        for (int i = 0; i < dp.length; i++) {
            dp[i]=nums[0]==i;
        }
        for (int i = 1; i < nums.length; i++) {
            for (int j = mid; j >=nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[mid];//1 2 5 WA [2,2,3,5] WA
    }
