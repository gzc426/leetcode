/*
  题目：
  在未排序的数组中找到第k大的元素。
  
  做法：快速排序，分治
  
  参考：
  https://blog.csdn.net/a2331046/article/details/53466152?utm_source=blogxgwz2
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findElement(nums, k, 0, nums.size()-1);
    }
    int findElement(vector<int>& nums, int k, int low, int high) {
        int left = low;
        int right = high;
        int key = nums[left];
        while (left < right) {
            while (left < right && nums[right] < key) --right;
            nums[left] = nums[right];
            while (left < right && nums[left] >= key) ++left;//注意：这里是>=
            nums[right] = nums[left];
        }
        nums[left] = key;
        //一趟快速排序结束，一个元素归位。该元素下标为left，其左边都比它大，其右边都比它小。
        if (left < (k-1)) {//比如，已经归位的是第4大的元素，欲找第6大的元素。(这里说的第k大从1开始算起，所以减1)
            return findElement(nums, k, left+1, high);
        }
        else if (left > (k-1)) {
            return findElement(nums, k, low, left-1);
        }
        else {//key就是欲找的第k大的元素。
            return key;
        }
    }    
};
