# LeetCode 34
    class Solution {
    public int[] searchRange(int[] nums, int target) {
         int[] res = {-1, -1};
        if (nums == null || nums.length == 0) {
            return res;
        }
        int start=findStartPosition(nums, target);
        int end=findEndPosition(nums, target);
        res[0]=start;
        res[1]=end;
        return res;
    }
    private static int findEndPosition(int[] nums, int target) {
        int left=0;
        int right=nums.length-1;
        while (left < right) {
            int mid=left+(right-left)/2;
            if (nums[mid] < target) {
                left=mid+1;
            } else if (nums[mid] > target) {
                right=mid-1;
            } else {
                if (nums[mid + 1] != nums[mid]) {
                    return mid;
                } else {
                    left=mid+1;
                }
            }
        }
        return nums[left]!=target?-1:left;
    }
    private  static int findStartPosition(int[] nums, int target) {
        int left=0;
        int right=nums.length-1;
        while (left < right) {
            int mid=left+(right-left)/2;
            if (nums[mid] < target) {
                left=mid+1;
            } else if (nums[mid] > target) {
                right=mid-1;
            } else {
                if (mid==0||nums[mid - 1] != nums[mid]) {
                    return mid;
                } else {
                    right=mid-1;
                }
            }
        }
        return nums[left]!=target?-1:left;
    }
}
