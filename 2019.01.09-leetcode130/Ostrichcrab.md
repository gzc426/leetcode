```
class Solution {
public:
    int n,m;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    vector<vector<char> >flag;

    void bfs(vector<vector<char> >& board,int x,int y){
        queue<pair<int,int> >q;
        q.push(make_pair(x,y));
        flag[x][y]=1;
        
        while(!q.empty()){
            int qx=q.front().first;
            int qy=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int tx=qx+dx[i];
                int ty=qy+dy[i];
                if(tx>=0&&tx<n&&ty>=0&&ty<m&&flag[tx][ty]==0&&board[tx][ty]=='O'){
                    q.push(make_pair(tx,ty));
                    flag[tx][ty]=1;
                }
            }
        }
    }

    void solve(vector<vector<char> >& board) {
        if(board.empty()){
            return ;
        }
        n=board.size();
        m=board[0].size();
        flag.resize(n);
        for(int i=0;i<n;i++){
            flag[i].resize(m,0);
        }
        
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'&&flag[0][i]==0){
                bfs(board,0,i);
            }
            if(board[n-1][i]=='O'&&flag[n-1][i]==0){
                bfs(board,n-1,i);
            }
        }
        
        for(int i=1;i<=n-2;i++){
            if(board[i][0]=='O'&&flag[i][0]==0){
                bfs(board,i,0);
            }
            if(board[i][m-1]=='O'&&flag[i][m-1]==0){
                bfs(board,i,m-1);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&flag[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};
```
