```java
class Solution {
    private boolean[][] used;
    public boolean exist(char[][] board, String word) {
        if(word.length() == 0 || board.length == 0 ||board[0].length == 0){
            return false;
        }
        used = new boolean[board.length][board[0].length];
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                dfs(board, word, 0, i, j);
            }
        }
        return res.size() != 0;
    }
    private boolean dfs(char[][] board, String word, int index, int i, int j){
        if(index == word.length()){
            return true;
        }
        if(i < 0||i >= board.length||j < 0||j >= board[0].length||used[i][j]){
            return false;
        }
        if(index < word.length()&&board[i][j]!=word.charAt(index)){
            return false;
        }

        used[i][j] = true;
        if(dfs(board, word, index + 1, i - 1, j)
            ||dfs(board, word, index + 1, i + 1, j)
            ||dfs(board, word, index + 1, i, j - 1)
            ||dfs(board, word, index + 1, i, j + 1)){
            return true;
        }
        used[i][j] = false;
        return false;
    } 
}
```
