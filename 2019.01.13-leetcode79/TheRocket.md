```java
class Solution {
    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, int i, int j, String word, int index) {
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(index)) {
            return false;
        }
        if (index == word.length() - 1) {
            return true;
        }
        board[i][j] ^= 128;
        boolean flag = dfs(board, i - 1, j, word, index + 1) ||
                dfs(board, i + 1, j, word, index + 1) ||
                dfs(board, i, j - 1, word, index + 1) ||
                dfs(board, i, j + 1, word, index + 1);
        board[i][j] ^= 128;
        return flag;
    }
}
```
