```python
class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) == 0:
            return True
        if len(s) > len(t):
            return False
        index = 0
        for i in range(len(t)):
            if t[i] == s[index]:
                index += 1
                if index == len(s):
                    return True
        return False
```
