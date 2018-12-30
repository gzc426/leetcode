```java
class Solution {
    public void sortColors(int[] nums) {
        int zero = -1;//nums[0 ... zero] == 0
        int two = nums.length;//nums[two ... length - 1] == 2
        for(int i = 0; i < two;){
            if(nums[i] == 0){
                swap(nums, i++, ++zero);
            }
            else if(nums[i] == 2){
                swap(nums, i, --two);
            }
            else{
                i++;
            }
        }
    }
    public void swap(int[] nums, int a, int b){
        int temp = nums[b];
        nums[b] = nums[a];
        nums[a] = temp;
    }
}
```
