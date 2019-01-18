```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                if (grid[i][j] == 1) {
                    res = Math.max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }

    private int dfs(int[][] grid, int i, int j) {
        int sum = 1;
        grid[i][j] = 0;
        if (i - 1 >= 0 && grid[i - 1][j] == 1)
            sum += dfs(grid, i - 1, j);
        if (i + 1 < grid.length && grid[i + 1][j] == 1)
            sum += dfs(grid, i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == 1)
            sum += dfs(grid, i, j - 1);
        if (j + 1 < grid[0].length && grid[i][j + 1] == 1)
            sum += dfs(grid, i, j + 1);
        return sum;
    }
}
```
