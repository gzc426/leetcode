```
class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.first!=b.first) return a.second<b.second;
        return a.first < b.second;
    }
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int size = points.size();
        if(size == 0)return 0;
        int ans = 1;
        sort(points.begin(),points.end(),cmp);
        int last = points[0].second;
        for(int i = 1; i < size; i++){
            if(points[i].first > last){
                ans++;
                last = points[i].second;
            }
        }
        return ans;
    }
};
```
