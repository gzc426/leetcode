```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int size = nums.size();
        if(!size) return ans;
        int l = 0, r = size-1;
        int mid = -1;
        if(target<nums[l]|| target>nums[r]) return ans;
        while(l<=r)
        {
            mid = (l+r)>>1;
            if(nums[mid]==target){
                int pos = mid;
                while(nums[pos]==target && pos<size) pos++;
                ans[1] = pos-1;
                while(nums[mid]==target && mid>-1) mid--;
                ans[0] = mid+1;
                return ans;
            }
            else if(nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        return ans;
    }
};
```
