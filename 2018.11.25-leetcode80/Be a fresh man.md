```cpp
class Solution {
public:
    //双下标一次遍历扫描
    int maxArea(vector<int>& height) {
        int height_len = height.size();
        int start = 0;
        int end = height_len - 1;
        int max_area = 0;
        while( start < end ){
            max_area = max(max_area, min(height[start], height[end]) * (end - start));
            //更新 start 和 end
            if(height[start] < height[end])
                start++;
            else end--;
        }
        return max_area;
    }
};
```
