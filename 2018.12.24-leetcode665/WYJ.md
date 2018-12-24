```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        if(nums.length == 0 || nums.length == 1){
            return true;
        }
        List<int[]> index = new ArrayList<>();
        for(int i = 0; i < nums.length - 1; i++){
            if(nums[i] > nums[i + 1]){
                if(i == 0){
                    index.add(new int[]{i, nums[i + 1]});
                }
                else if(nums[i - 1] > nums[i + 1]){
                    //index.add(new int[]{i, nums[i + 1]});
                    index.add(new int[]{i + 1, nums[i]});
                }
                else{
                    index.add(new int[]{i, nums[i + 1]});
                }
                
            }
        }
        if(index.size() == 0){
            return true;
        }
        for(int i = 0; i < index.size(); i++){
            int[] nums1 = nums.clone();
            int[] change = index.get(i);
            for(int j = 0; j < nums1.length; j++){
                if(j == change[0]){
                    nums1[j] = change[1];
                }
            }
            if(isNonde(nums1)){
                return true;
            }
        }
        return false;
    }
    public boolean isNonde(int[] nums){
        for(int i = 0; i < nums.length - 1; i++){
            if(nums[i] > nums[i + 1]){
                return false;
            }
        }
        return true;
    }
}
```
