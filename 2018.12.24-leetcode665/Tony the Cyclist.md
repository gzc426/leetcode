```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        if(nums.length < 2){
            return true;
        }
        int cot = 0;
        int index;
        if(nums[0] > nums[1]){
            cot = 1;
        }
        int len = nums.length - 1;
        for (int i = 1; i < len; i ++){
            if (cot > 1){
                return false;
            }
            if (nums[i] > nums[i+1]){
                if(nums[i-1] >= nums[i+1]){
                    nums[i+1] = nums[i];
                    
                }
                else {
                    nums[i] = nums[i-1];
                }
                //len--;
                //i--;
                cot++;
            }
        }
        if (cot > 1){
                return false;
        }
        return true;
    }
}
```
