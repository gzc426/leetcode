# leetcode 665
    class Solution {
    public boolean checkPossibility(int[] nums) {
       if (nums == null || nums.length == 0||nums.length==1) {
            return true;
        }
        boolean flag=false;
        boolean visited=false;
        for (int i = 1; i <nums.length; i++) {
            if (nums[i] < nums[i - 1]) {
                if (!flag) {
                    if (i == nums.length - 1 || (i + 1 < nums.length && nums[i - 1] <= nums[i + 1])) {
                        nums[i] = nums[i - 1];
                    } else {
                        if (i - 2 >= 0 && nums[i] < nums[i - 2]) {
                            return false;
                        }
                    }
                    flag = true;
                } else {
                    flag=false;
                    break;
                }
                visited=true;
            }
        }
        return !visited?true:flag;
    }
}
