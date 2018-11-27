class Solution {
    int index = 0;
    int j = 1;
    int i = 0;
    
    public int removeDuplicates(int[] nums) {
        while(i <= nums.length - 1) { 
            if(j < nums.length && nums[i] == nums[j]) {
                if(j - i == 1) {
                    nums[index++] = nums[i];
                }
                j++;
            }
            else {
                 nums[index++] = nums[j - 1];
                 i = j;
                 j++;
            }
        }
        return index;
    }
}
