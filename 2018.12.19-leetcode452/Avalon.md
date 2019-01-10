class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points == null || points.length == 0) return 0;
		//对二位数组进行排序
		Arrays.sort(points, (x, y) -> x[1] - y[1]);

		//开始落实比较方案
		//1-无重叠区域
		int count = 0, j = 1;
		for (int i = 0; j < points.length; j++) {
			if (points[i][1] >= points[j][0]) {//被比较方的结束大于比较方的开始--重叠了-》

			} else {
				count++;//因为这个是后结算的，所以需要在最后return 的时候自加
				i = j;
			}
		}

		return ++count;//当最后一个出现的时候是木有进行判断
    }
}
