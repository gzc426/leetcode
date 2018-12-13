# c++
```cpp
class Solution {
public:
    static bool cmp(int a, int b) {
        return a > b;
    }
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[k-1];
    }
};
```
