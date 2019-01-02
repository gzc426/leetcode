```java
class Solution {
    public void sortColors(int[] nums) {
        int l = 0;
        int r = nums.length;
        int i = 0;
        while (i < r) {
            if (nums[i] < 1)        swap(nums, i++, l++);
            else if (nums[i] > 1)   swap(nums, i, --r);
            else                    ++i;
        }
    }
    
    private static void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
```
