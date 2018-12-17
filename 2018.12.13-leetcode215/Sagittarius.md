```
static  auto io_sync_off = [] () {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(),nums.end()-k,nums.end());
        return nums[nums.size()-k];
    }
};

```
