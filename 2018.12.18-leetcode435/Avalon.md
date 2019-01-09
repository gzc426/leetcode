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
        //按照停止位置进行排序
		Arrays.sort(intervals, (x, y) -> x.end - y.end);

		//
		int count = 0, j = 1;//j-下一个
		for (int i = 0; j < intervals.length; j++) {
			if (intervals[i].end > intervals[j].start) {//当后一个产生重叠区域时
				count++;
			}else i=j;//当不重叠的时候，需要把j的位置作为比较方
		}
		return count;
    }
}
