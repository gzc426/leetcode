```java
  public void solve(char[][] board) {

        if (board.length==0) return;

        for (int i=0;i<board[0].length;i++){

            if (board[0][i]=='O'){
                findO(0,i,board);
            }
            if (board[board.length-1][i]=='O'){
                findO(board.length-1,i,board);
            }
        }
        for (int i=1;i<board.length-1;i++){
            if (board[i][0]=='O'){
                findO(i,0,board);
            }
            if (board[i][board[0].length-1]=='O'){
                findO(i,board[0].length-1,board);
            }
        }

        for (int i=0;i<board.length;i++){
            for (int j = 0; j < board[0].length; j++) {
                if(board[i][j]=='T') {
                    board[i][j]='O';
                    continue;
                }
                if(board[i][j]=='O') {
                    board[i][j]='X';
                    continue;
                }
            }
        }
    }

    public void findO(int x, int y, char[][]board){
        if (x>=0&&x<board.length&&y>=0&&y<board[0].length&&board[x][y]=='O'){
            board[x][y]='T';
            findO(x-1,y,board);
            findO(x+1,y,board);
            findO(x,y-1,board);
            findO(x,y+1,board);
        }
    }
```
