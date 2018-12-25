```
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval a, Interval b){
        if(a.end != b.end)
            return a.end<b.end;
        else
            return a.start<b.start;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        int ans = 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int last = intervals[0].end;
        int size = intervals.size();
        for(int i = 1; i < size; i++){
            if(intervals[i].start < last){
                ans++;
            }else{
                last = intervals[i].end;
            }
        }
        // for(int i = 0; i < size; i++){
        //     cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
        // }
        return ans;
    }
};
```
