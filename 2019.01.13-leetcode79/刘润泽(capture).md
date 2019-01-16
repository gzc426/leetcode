```java
  public boolean exist(char[][] board, String word) {

        if (board.length==0) return false;
        int[][] boardBak = new int[board.length][board[0].length];

        char[] chars = word.toCharArray();
        for (int i=0;i<board.length;i++){
            for (int j=0;j<board[0].length;j++){
                if (board[i][j]==chars[0]) if (deepsearch(i,j,board,boardBak,chars,0)) return true;
            }
        }
        return false;
    }

    public boolean deepsearch(int i, int j, char[][] board, int[][] boardBak, char[] chars, int deep){

        if (i<0||i>=board.length||j<0||j>=board[0].length) return false;
        if (boardBak[i][j]==1) return false;
        boolean up=false,down=false,left=false,right=false;

        if (board[i][j]==chars[deep]){
            boardBak[i][j]=1;
            if (chars.length==deep+1) {
                return true;
            }
            up=(deepsearch(i-1,j,board,boardBak,chars,deep+1));
            if (!up) down=deepsearch(i+1,j,board,boardBak,chars,deep+1);
            if (!(up||down))left=deepsearch(i,j-1,board,boardBak,chars,deep+1);
            if (!(up||down||left))right=deepsearch(i,j+1,board,boardBak,chars,deep+1);
        }
        if (up||down||left||right) {
            return true;
        }else {
            boardBak[i][j]=0;
            return false;
        }
    }
```
