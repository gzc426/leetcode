 1 /**
 2  ###Definition for an interval.
 
 3  ###public class Interval {
 
 4  ###     int start;
 
 5  ###    int end;
 
 6  ###   Interval() { start = 0; end = 0; }
 
 7  ###   Interval(int s, int e) { start = s; end = e; }
 
 8  ### }
 9  */
 ```
10 public class Solution {
11     public int eraseOverlapIntervals(Interval[] intervals) {
12         if(intervals.length == 0) return 0;
13         
14         Comparator<Interval> comp = new Comparator<Interval>() {
15             public int compare(Interval interval1, Interval interval2) {
16                 if(interval1.end > interval2.end) return 1;
17                 else if(interval1.end < interval2.end) return -1;
18                 else return 0;
19             }
20         };
21         
22         Arrays.sort(intervals, comp);
23         int lastend = intervals[0].end;
24         int remove = 0;
25         for(int i = 1; i < intervals.length; i++) {
26             if(intervals[i].end == lastend) remove++;
27             else if(intervals[i].start < lastend) remove++;
28             else lastend = intervals[i].end;
29         }
30         
31         return remove;
32     }
33 }

```
