```
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int mid = 0;
        while(l<r)
        {
            mid = (l+r)>>1;
            if(nums[mid]>nums[r]) l = mid+1;
            else r = mid;
        }
        return nums[r];
    }
};
```
