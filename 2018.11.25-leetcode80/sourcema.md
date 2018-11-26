# leetcode 80
    public int removeDuplicates(int[] nums) {
         if (nums == null || nums.length == 0 || nums.length < 3) {
            return nums.length;
        }
        int i=0;
        for (int j = 0; j < nums.length; j++) {
            if (i < 2 || nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
