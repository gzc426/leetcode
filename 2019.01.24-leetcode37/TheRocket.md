```java
class Solution {
    public void solveSudoku(char[][] board) {
        // 记录某行的某位数字是否已经被摆放
        boolean[][] row = new boolean[9][9];
        // 记录某列的某位数字是否已经被摆放
        boolean[][] col = new boolean[9][9];
        // 记录 3x3 宫格内的某位数字是否已经被摆放
        boolean[][] block = new boolean[9][9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    row[i][num] = true;
                    col[j][num] = true;
                    // 化二维的 3x3 为一维的 0~8
                    block[i / 3 * 3 + j / 3][num] = true;
                }
            }
        }
        dfs(board, 0, 0, row, col, block);
    }

    private boolean dfs(char[][] board, int i, int j, boolean[][] row, boolean[][] col, boolean[][] block) {
        while (board[i][j] != '.') {
            if (++j == 9) {
                ++i;
                j = 0;
            }
            if (i == 9) {
                return true;
            }

        }
        // 化二维的 3x3 为一维的 0~8
        int blockIndex = i / 3 * 3 + j / 3;
        for (int k = 0; k < 9; ++k) {
            if (!row[i][k] && !col[j][k] && !block[blockIndex][k]) {
                // 设置访问标志
                row[i][k] = true;
                col[j][k] = true;
                block[blockIndex][k] = true;
                // 改变当前值
                board[i][j] = (char) ('1' + k);
                // 进入下一层，成功则直接返回
                if (dfs(board, i, j, row, col, block)) {
                    return true;
                }
                // 恢复
                row[i][k] = false;
                col[j][k] = false;
                block[blockIndex][k] = false;
                board[i][j] = '.';
            }
        }
        return false;
    }
}
```
