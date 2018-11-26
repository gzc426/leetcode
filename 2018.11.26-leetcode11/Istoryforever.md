```
const int x=[]{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
class Solution {
    const int inf = 0x3f3f3f;
public:
    int maxArea(vector<int>& height) {
        int ans = -inf;
        int l = 0;
        int r = height.size() - 1;
        while(l < r){
            int w = r - l;
            int h = height[l] < height[r]? height[l]:height[r];
            int c =w * h;
            if(ans < c) ans = c;
            while(l < r && height[l] <= h ) l++;
            while(l < r && height[r] <= h ) r--;
        }
        return ans;
        
    }
};
```
