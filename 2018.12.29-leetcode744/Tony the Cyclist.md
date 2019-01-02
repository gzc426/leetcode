```python
class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        for x in letters:
            if x >target:
                return x
        return letters[0]
```
