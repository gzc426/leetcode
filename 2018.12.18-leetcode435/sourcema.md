# leetcode 435
    class Solution {
    public int eraseOverlapIntervals(Interval[] intervals) {
        if (intervals == null || intervals.length == 0||intervals.length==1) {
            return 0;
        }

        Arrays.sort(intervals, new Comparator<Interval>() {//不按照start比较，按照end比较
            @Override
            public int compare(Interval o1, Interval o2) {
                return o1.end-o2.end;
            }
        });
        int count=0;
        int index=1;
        for (int i = 0; index < intervals.length; index++) {
            if (intervals[i].end > intervals[index].start) {
                count++;
            } else {
                i=index;
            }
        }
        return count;
    }
}
