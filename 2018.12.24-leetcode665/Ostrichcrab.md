```
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        for(int i = 1; i < size && res < 2; i++){
            if(nums[i]>=nums[i-1]) continue;
            if(i-2>=0 && nums[i]<nums[i-2]){
                nums[i] = nums[i-1];
            }else{
                nums[i-1] = nums[i];
            }
            res++;
        }
        return res<=1;
    }
};
```
