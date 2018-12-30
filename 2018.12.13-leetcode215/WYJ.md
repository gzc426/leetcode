```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        return quickSort(nums, 0, nums.length - 1, k);
    }
    private int quickSort(int[] nums, int L, int R, int k){
        int Lt = R + 1, Gt = L;
        int value = nums[L];
        int i = L + 1;
        while(i < Lt){
            if(nums[i] < value){
                swap(nums, i, --Lt);
            }
            else if(nums[i] == value){
                i++;
            }
            else{
                swap(nums, i++, ++Gt);
            }
        }
        swap(nums, Gt, L);
        if(k - 1 >= Gt && k - 1 < Lt){
            return nums[Gt];
        }
        else if(k - 1 < Gt){
            return quickSort(nums, L, Gt - 1, k);
        }
        else{
            return quickSort(nums, Lt, R, k);
        }
    }
    private void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```
