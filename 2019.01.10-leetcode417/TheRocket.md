```java
class Solution {
    public List<int[]> pacificAtlantic(int[][] matrix) {
        List<int[]> res = new ArrayList<>();
        if (matrix == null || matrix.length == 0) {
            return res;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        boolean[][] fromPacific = new boolean[m][n];
        boolean[][] fromAtlantic  = new boolean[m][n];
        for (int i = 0; i < m; ++i) {
            dfs(matrix, fromPacific, i, 0);
            dfs(matrix, fromAtlantic, i, n - 1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(matrix, fromPacific, 0, i);
            dfs(matrix, fromAtlantic, m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (fromPacific[i][j] && fromAtlantic[i][j]) {
                    res.add(new int[] {i, j});
                }
            }
        }
        return res;
    }

    private void dfs(int[][] matrix, boolean[][] fromOcean, int i, int j) {
        if (fromOcean[i][j]) {
            return;
        }
        fromOcean[i][j] = true;
        if (i - 1 >= 0 && matrix[i - 1][j] >= matrix[i][j]) {
            dfs(matrix, fromOcean, i - 1, j);
        }
        if (i + 1 < matrix.length && matrix[i + 1][j] >= matrix[i][j]) {
            dfs(matrix, fromOcean, i + 1, j);
        }
        if (j - 1 >= 0 && matrix[i][j - 1] >= matrix[i][j]) {
            dfs(matrix, fromOcean, i, j - 1);
        }
        if (j + 1 < matrix[0].length && matrix[i][j + 1] >= matrix[i][j]) {
            dfs(matrix, fromOcean, i, j + 1);
        }
    }
}
```
