# LeetCode 452
    class Solution {
    public int findMinArrowShots(int[][] points) {//按照每个坐标的end排序，然后看与当前坐标重叠的坐标最远到哪，超出当前坐标范围更新count，更新坐标位置
         if (points == null || points.length == 0 || points[0].length == 0) {
            return 0;
        }
        if (points.length == 1) {
            return 1;
        }
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });
        int count = 1;
        int index = 1;
        for (int i = 0; index < points.length; index++) {
            if (points[i][1] >= points[index][0]) {
                continue;
            } else {
                count++;
                i = index;
            }
        }
        return count;
    }
}
