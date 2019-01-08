# LeetCode 153
    class Solution {
    public int findMin(int[] nums) {//典型的二分，数组进行了旋转，我们现在把数组分为两部分，
        // 前面部分是数组中元素较大的元素，后面部分呢是数组中元素较小的元素，如果中间部分的元素值大于首元素和
        //末尾元素说明当前位置在数组的前半部分，left应该等于mid+1，否则说明在数组后半部分right==mid;
        int left=0;
        int right=nums.length-1;
        while (left < right && nums[left] > nums[right]) {
            int mid=(left+right)>>1;
            if (nums[mid] >= nums[left] && nums[right] < nums[mid]) {
                left = mid + 1;
            } else {
                right=mid;
            }
        }
        return nums[left];
    }
}
