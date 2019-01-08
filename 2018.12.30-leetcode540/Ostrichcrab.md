```
int x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size-1;
        while(left<right){
            int mid = (left + right) >> 1;
            if(mid & 1){
                if(nums[mid] == nums[mid-1]) left = mid + 1;
                else if(nums[mid] == nums[mid+1]) right = mid - 1;
                else return nums[mid];
            }else{
                if(nums[mid] == nums[mid-1]) right = mid - 2;
                else if(nums[mid] == nums[mid+1]) left = mid + 2;
                else return nums[mid];
            }
        }
        return nums[left];
    }
};
```
