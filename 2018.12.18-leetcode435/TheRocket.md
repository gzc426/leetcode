```java
/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public int eraseOverlapIntervals(Interval[] intervals) {
        if (intervals == null || intervals.length <= 1) {
            return 0;
        }
        Arrays.sort(intervals, Comparator.comparingInt(o -> o.end));
        int res = 0;
        int pre = intervals[0].end;
        for (int i = 1; i < intervals.length; ++i) {
            if (intervals[i].start < pre) {
                ++res;
            } else {
                pre = intervals[i].end;
            }
        }
        return res;
    }
}
```
