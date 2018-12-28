```java
  /**
  * 时间复杂度为O(n)
  **/
  public static int maxSubArray(int[] nums) {

        int maxSubArray=nums[0];
        int tempSubArray=nums[0];

        for (int i=1;i<nums.length;i++){

            if (tempSubArray<0){
                tempSubArray = nums[i];
            }else {
                tempSubArray = tempSubArray + nums[i];
            }
            if (tempSubArray>maxSubArray)maxSubArray=tempSubArray;
            if (i==nums.length-1) return maxSubArray;

        }

        return maxSubArray;
    }
```
