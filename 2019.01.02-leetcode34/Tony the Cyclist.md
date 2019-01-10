```python
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if target not in nums:
            return [-1, -1]
        begin = nums.index(target)
        nums.reverse()
        end = len(nums) - 1 - nums.index(target)
        return [begin, end]
```
