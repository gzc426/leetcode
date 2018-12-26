```java
class Solution {
    public int maxSubArray(int[] nums) {
        int [] n = new int[nums.length];
        n[0] = nums[0];
        for (int i = 1; i < nums.length; i++){
            nums[i] = (nums[i] + nums[i-1]) < nums[i]? nums[i]: (nums[i] + nums[i-1]);
        }
        int max = nums[0];
        for (int i = 1; i < nums.length; i++){
            max = nums[i] > max? nums[i]: max;
        }
        return max;
    }
}
```
