```python
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if len(nums) < 2:
            pass
        else:
            index_0 = 0
            index_2 = len(nums) - 1
            i = 0
            # j = len(nums)-1
            while i < index_2 + 1 and i <= len(nums)-1:
                if nums[i] == 0:
                    nums[index_0], nums[i] = nums[i], nums[index_0]
                    index_0 += 1
                    i += 1
                elif nums[i] == 2:
                    nums[index_2], nums[i] = nums[i], nums[index_2]
                    index_2 -= 1
                else:
                    i += 1
```
