```java
class Solution {
    public int maxSubArray(int[] nums) {
        return findMaxSub(nums, 0, nums.length - 1);
    }
    public int findMaxSub(int[] nums, int begin, int end){
        if(begin == end){
            return nums[begin];
        }
        else{
            int mid = (begin + end) / 2;
            int leftSum = findMaxSub(nums, begin, mid);
            int rightSum = findMaxSub(nums, mid + 1, end);
            int crossSum = findMaxCrossing(nums, begin, mid, end);
            return Math.max(Math.max(leftSum, rightSum), crossSum);
        }
    }
    public int findMaxCrossing(int[] nums, int begin, int mid, int end){
        int leftSum = Integer.MIN_VALUE;
        int sum = 0;
        for(int i = mid; i >= begin; i--){
            sum += nums[i];
            if(sum > leftSum){
                leftSum = sum;
            }
        }
        int rightSum = Integer.MIN_VALUE;
        sum = 0;
        for(int i = mid + 1; i <= end; i++){
            sum += nums[i];
            if(sum > rightSum){
                rightSum = sum;
            }
        }
        return leftSum + rightSum;
    }
}
```
