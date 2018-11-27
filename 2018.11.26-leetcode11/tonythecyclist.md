## Java

```
class Solution {
    public int maxArea(int[] height) {
        int l = 0, r = height.length - 1;
        int s = (r-l) * (height[l] > height[r]? height[r]: height[l]);
        while (l < r){
            if (height[l] < height[r]){
                l++;
            }
            else {
                r--;
            }
            s = Math.max(s, (r-l) * (height[l] > height[r]? height[r]: height[l]));
        }
        return s;

    }
}
```



## Python
```
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype:
        """
        l = 0
        r = len(height) - 1
        h = (height[r] if (height[l] > height[r]) else height[l])
        s = h * (r - l)
        while l < r:
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
            h = (height[r] if (height[l] > height[r]) else height[l])
            s = max(s, (r-l)*h)
        return s
```
