# leetcode 79
    class Solution {
    public boolean exist(char[][] board, String word) {
        if (board[0].length == 0 || board.length == 0) {
            return false;
        }
        int row=board.length,col=board[0].length,count=0;
        boolean flag=false;
        go:
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                flag=dfs(board,word,i,j,count);
                if (flag) {
                    break go;
                }
            }
        }
        return flag;
    }
    private  boolean dfs(char[][] board, String word,int i, int j, int count) {
        if (count == word.length()) {
            return true;
        }
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || word.charAt(count) != board[i][j]) {
            return false;
        }
        board[i][j]^=256;
        boolean flag=dfs(board,word,i+1,j,count+1)||dfs(board,word,i-1,j,count+1)
                ||dfs(board,word,i,j+1,count+1)||dfs(board,word,i,j-1,count+1);
        board[i][j]^=256;
        return flag;
    }
}
