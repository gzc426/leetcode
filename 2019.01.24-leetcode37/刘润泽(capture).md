```java
    public void solveSudoku(char[][] board) {

        int[] next = findNext(0, 0, board);
        huisu(next[0],next[1],board);

    }

    public boolean huisu(int i, int j, char[][] board){

        System.out.println(i+" "+j);

        int[] other = findOther(i, j, board);

        for (int m=1;m<other.length;m++){
            if (other[m]==0){
                board[i][j]=(char) (m+48);
                if (findNext(i,j,board)!=null){
                    int[] next = findNext(i,j,board);
                    if (huisu(next[0],next[1],board)){
                        return true;
                    }else{
                        board[i][j]='.';
                    }
                }else{
                    return true;
                }
            }
        }

        return false;
    }

    public int[] findNext(int i, int j, char[][]board){
        for (;i<9;i++){
            for (;j<9;j++){
                if (board[i][j]=='.'){
                    return new int[]{i,j};
                }

            }
            if (j==9) j=0;
        }
        return null;
    }

    /**
     * 查询当前(i,j)可以填的数字集合
     * @param i
     * @param j
     * @param board
     * @return
     */
    public int[] findOther(int i, int j, char[][] board){

        int[] currChars = new int[10];
        int tempI = i;
        int tempJ = j;
        for (int m=0;m<3;m++){
            for (int n=0;n<3;n++){
                if (board[tempI][tempJ]!='.'){
                    currChars[board[tempI][tempJ]-48] = 1;
                }
                if (tempI%3==2){
                    tempI=tempI-2;
                    continue;
                }
                tempI++;
            }
            if (tempJ%3==2){
                tempJ=tempJ-2;
            }
            tempJ++;
        }
        for (int x=0;x<board.length;x++){
            if (board[x][j]!='.'&&currChars[board[x][j]-48] == 0){
                currChars[board[x][j]-48] = 1;
            }
        }
        for (int y=0;y<board.length;y++){
            if (board[i][y]!='.'&&currChars[board[i][y]-48] == 0){
                currChars[board[i][y]-48] = 1;
            }
        }
        return currChars;
    }
```
