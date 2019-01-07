```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if(grid.length == 0){
            return 0;
        }
        boolean[][] judge = new boolean[grid.length][grid[0].length];
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                judge[i][j] = false;
            }
        }
        int area = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(!judge[i][j]&&grid[i][j] == 1){
                    area = Math.max(area, findArea(grid, i, j, judge));
                }
            }
        }
        return area;
    }
    public int findArea(int[][] grid, int x, int y, boolean[][] judge){
        if(grid[x][y] == 0){
            return 0;
        }
        if(judge[x][y]){
            return 0;
        }
        else{
            judge[x][y] = true;
            int up = 0, down = 0, left = 0, right = 0;
            if(x - 1 >= 0){
                up = findArea(grid, x - 1, y, judge);
            }
            if(x + 1 < grid.length){
                down = findArea(grid, x + 1, y, judge);
            }
            if(y - 1 >= 0){
                left = findArea(grid, x, y - 1, judge);
            }
            if(y + 1 < grid[x].length){
                right = findArea(grid, x, y + 1, judge);
            }
            return 1 + up + down + left + right;
        
        }
    }
}
```
