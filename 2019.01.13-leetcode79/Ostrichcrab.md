```
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int x, int y, int len)
    {
        if(len == word.length()) return true;
        if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y]!=word[len]) 
            return false;
        board[x][y]^=128;
        bool res = dfs(board,word,x-1,y,len+1)||
                   dfs(board,word,x+1,y,len+1)||
                   dfs(board,word,x,y+1,len+1)||
                   dfs(board,word,x,y-1,len+1) ;
        board[x][y]^=128;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};
```
