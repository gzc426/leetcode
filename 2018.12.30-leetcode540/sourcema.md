# leetcode 540
    class Solution {
    public int singleNonDuplicate(int[] nums) {
       int start = 0, end = nums.length - 1;
        while (start < end) {
            int mid=(start+end)>>1;
            if ((mid&1)==1) mid--;
            if ( nums[mid] == nums[mid + 1]) {
                start = mid + 2;//如果mid是--之后的值，mid+1 mid可能又回到原来的值可能造成死循环
            } else if ( mid-1>=0&&nums[mid] == nums[mid - 1]) {
                end=mid-1;
            } else {
                return nums[mid];
            }
        }
        return nums[start];
    }
}
