/*
  题目：
  在未排序的数组中找到第k大的元素。
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};
