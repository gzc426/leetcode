```java
  public static int[] searchRange(int[] nums, int target) {

        if (nums.length==0) return new int[]{-1,-1};
        int start=0;
        int end=nums.length-1;
        int mid;
        while (start<=end){
            mid=start+(end-start)/2;
            if (nums[mid]>target){
                end=mid-1;
                continue;
            }
            if (nums[mid]<target){
                start=mid+1;
                continue;
            }
            int left=mid;
            int right=mid;
            while (true){

                if (left>0&&nums[left]==nums[left-1]){
                    left=left-1;
                    continue;
                }
                break;
            }
            while (true){

                if (right<nums.length-1&&nums[right]==nums[right+1]){
                    right=right+1;
                    continue;
                }
                break;
            }
            return new int[]{left,right};
        }
        return new int[]{-1,-1};
    }
```
