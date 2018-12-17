```python
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort(reverse=True)
        return nums[k-1]
```
```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        // 经过调优的快速排序法
        Arrays.sort(nums);
        return nums[nums.length-k];
    }
}
```
