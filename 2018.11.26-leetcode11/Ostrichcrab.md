```
class Solution {
public:
    int max(int a, int b){return a>b?a:b;}
    int min(int a, int b){return a<b?a:b;}
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        ans = max(ans,min(height[l],height[r])*(r-l));
        while(l<r){
            if(height[l]>height[r]){
                r--;
                ans = max(ans,min(height[l],height[r])*(r-l));
            }else{
                l++;
                ans = max(ans,min(height[l],height[r])*(r-l));
            }
        }
        return ans;
    }
};
```
