```java
class Solution {
    public int findMinArrowShots(int[][] points) {
        if(points.length == 0){
            return 0;
        }
        Comparator<int[]> cmp = new Comparator<int[] >(){
            public int compare(int[] points1, int[] points2){
                return points1[1] - points2[1];
            }
        };
        Arrays.sort(points, cmp);
        int end = points[0][1];
        int count = 1;
        for(int i = 1; i < points.length; i++){
            if(points[i][0] > end){
                count++;
                end = points[i][1];
            }
        }
        return count;

    }
}
```
