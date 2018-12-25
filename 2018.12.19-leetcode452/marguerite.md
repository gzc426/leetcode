  
  这道题目是活动选择问题(Activity-Selection Problem)的变形。活动选择问题是《算法导论》里面关于贪心算法的第一个问题。这个问题是这样的。有一组活动，
  每个活动都有一个开始时间S和结束时间F，假设一个人在同一时间只能参加一个活动，找出出一个人可以参加的最多的活动数量。例如。
  
假设现在有6个活动，下面是6个活动的起始和结束时间。 
 start[]  =  {1, 3, 0, 5, 8, 5};
 finish[] =  {2, 4, 6, 7, 9, 9};
 一个人一天最多能参见的活动为
 {0, 1, 3, 4}
 
关于活动选择问题就不在详细解说了。这道题非常算是变形。将所有的气球按照终止位置排序，开始从前向后扫描。以第一个气球的终止位置为准,
只要出现的气球起始位置小于这个气球的终止位置，代表可以一箭使这些气球全部爆炸；当出现一个气球的起始位置大于第一
个气球的终止位置时再以这个气球的终止位置为准，找出所有可以再一箭爆炸的所有气球；以此类推。。。


  ```
  public int findMinArrowShots(int[][] points) {
        if (points == null || points.length == 0 || points[0].length == 0) {
            return 0;
        }
        Arrays.sort(points, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[1] - b[1];
            }
        });

        long lastEnd = Long.MIN_VALUE;
        int minArrows = 0;
        for (int i = 0; i < points.length; i++) {
            if (lastEnd < points[i][0]) {
                lastEnd = points[i][1];
                minArrows++;
            }
        }
        return minArrows;
    }
```
