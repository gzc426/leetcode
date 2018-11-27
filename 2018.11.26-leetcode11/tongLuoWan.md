```
class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length-1;
        int result = 0;
        while(i < j){
            int h = Math.min(height[i], height[j]);
            result = Math.max(result, (j-i) * h);
            while (i < j && h == height[i]) ++i;
            while (i < j && h == height[j]) --j;
        }
        return result;
    }
}
```
