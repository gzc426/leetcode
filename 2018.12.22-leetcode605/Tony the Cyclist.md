```python
class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        cot = 0
        if 0 not in flowerbed:
            return 0 == n
        if len(flowerbed) == 1:
            if flowerbed[0] == 0:
                return 0 <= n
            else:
                return 0 == n
        if 1 not in flowerbed:
            num = len(flowerbed) + 2
            if  num % 2 != 0:
                cot += num / 2 
            else: 
                cot += num / 2 - 1
            if cot >= n:
                return True
            else:
                return False
        start = flowerbed.index(0)
        res = []
        for i in range(len(flowerbed)):
            if flowerbed[i] == 1:
                tmp = flowerbed[start: i]
                if start == 0:
                    tmp = [0] + tmp
                res.append(tmp)
                start = i + 1
            if i == len(flowerbed)-1:
                tmp = flowerbed[start: ]
                tmp = tmp + [0]
                res.append(tmp)
        print res
        for i in range(len(res)):
            if len(res[i]) == 0:
                continue
            elif len(res[i]) % 2 == 0:
                cot += len(res[i]) / 2 - 1
            else:
                cot += len(res[i]) / 2
        print cot
        if cot >= n:
            return True
        else:
            return False
```
