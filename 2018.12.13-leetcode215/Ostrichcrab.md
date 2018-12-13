```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];
    }
};
```

```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        nth_element(nums.begin(),nums.begin()+size-k,nums.end());
        return nums[size-k];
    }
};
```
