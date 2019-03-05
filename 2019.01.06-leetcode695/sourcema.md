# LeetCode 695
    class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if (grid[0].length == 0 || grid.length == 0) {
            return 0;
        }
        int row=grid.length,col=grid[0].length;
        int max=0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    int count=dfs(grid, i, j);
                    max = Math.max(max, count);
                }
            }
        }
        return max;
    }
     private  int dfs(int[][] grid, int i, int j) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j]=0;
        return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j)
                + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
    }
}
