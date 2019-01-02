```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums.length == 0){
            return new int[] {-1, -1};
        }
        int l = 0, r = nums.length - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        int start = l;
        if(nums[l] == target){
            r = nums.length - 1;
            while(l < r){
                int mid = l + (r - l) / 2;
                if(mid == l){
                    mid += 1;
                }
                if(nums[mid] > target){
                    r = mid - 1;
                }
                else{
                    l = mid;
                }
            }
            int end = r;
            return new int[] {start, end};
        }
        return new int[] {-1, -1};
    }
}
```
