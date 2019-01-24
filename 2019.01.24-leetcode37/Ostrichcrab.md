```
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board, 0);
    }
    bool solve(vector<vector<char> > &board, int position)
    {
        if(position == 81)
            return true;

        int row = position / 9;
        int col = position % 9;
        if(board[row][col] == '.')
        {
            for(int i = 1; i <= 9; i ++)
            {//try each digit
                board[row][col] = i + '0';
                if(check(board, position))
                    if(solve(board, position + 1))
                    //only return valid filling
                        return true;
                board[row][col] = '.';
            }
        }
        else
        {
            if(solve(board, position + 1))
            //only return valid filling
                return true;
        }
        return false;
    }
    bool check(vector<vector<char> > &board, int position)
    {
        int row = position / 9;
        int col = position % 9;
        int gid;
        if(row >= 0 && row <= 2)
        {
            if(col >= 0 && col <= 2)
                gid = 0;
            else if(col >= 3 && col <= 5)
                gid = 1;
            else
                gid = 2;
        }
        else if(row >= 3 && row <= 5)
        {
            if(col >= 0 && col <= 2)
                gid = 3;
            else if(col >= 3 && col <= 5)
                gid = 4;
            else
                gid = 5;
        }
        else
        {
            if(col >= 0 && col <= 2)
                gid = 6;
            else if(col >= 3 && col <= 5)
                gid = 7;
            else
                gid = 8;
        }

        //check row, col, subgrid
        for(int i = 0; i < 9; i ++)
        {
            //check row
            if(i != col && board[row][i] == board[row][col])
                return false;
            
            //check col
            if(i != row && board[i][col] == board[row][col])
                return false;
            
            //check subgrid
            int r = gid/3*3+i/3;
            int c = gid%3*3+i%3;
            if((r != row || c != col) && board[r][c] == board[row][col])
                return false;
        }
        return true;
    }
};
```
