# leetcode 417
    class Solution {
    private static int[][] d = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    private static int row;
    private static int col;
    public static List<int[]> pacificAtlantic(int[][] matrix) {
        List<int[]> res = new ArrayList<>();
        if (matrix == null || matrix.length == 0) {
            return res;
        }
        row=matrix.length;
        col=matrix[0].length;
        boolean[][] pacific = new boolean[row][col];
        boolean[][] atlantic = new boolean[row][col];
        for (int i = 0; i <row ; i++) {//从左右边界开始判断
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, col-1);
        }
        for (int i = 0; i <col ; i++) {//从左右边界开始判断
            dfs(matrix, pacific, 0, i);
            dfs(matrix, atlantic, row-1, i);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.add(new int[]{i, j});
                }
            }
        }
        return res;
    }

    private static void dfs(int[][] matrix, boolean[][] arr, int x, int y) {
        arr[x][y]=true;
        for (int i = 0; i < 4; i++) {
            int nextX=x+d[i][0];
            int nextY=y+d[i][1];
            if (nextX >= 0 && nextX < row && nextY >= 0 && nextY < col && !arr[nextX][nextY]
                    && matrix[nextX][nextY] >= matrix[x][y]) {
                dfs(matrix,arr,nextX,nextY);
            }
        }
    }
}
