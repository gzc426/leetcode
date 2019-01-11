```
class Solution {
public:
    vector<pair<int,int>> res;
    vector<vector<int>> visited;
    void dfs(vector<vector<int>>& matrix, int x, int y, int pre, int preval){
        if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() ||
          matrix[x][y]<pre || (visited[x][y]&preval)==preval)
            return ;
        visited[x][y] |= preval;
        if(visited[x][y] == 3) res.push_back({x,y});
        dfs(matrix,x+1,y,matrix[x][y],visited[x][y]);
        dfs(matrix,x-1,y,matrix[x][y],visited[x][y]);
        dfs(matrix,x,y+1,matrix[x][y],visited[x][y]);
        dfs(matrix,x,y-1,matrix[x][y],visited[x][y]);
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        visited.resize(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            dfs(matrix,i,0,INT_MIN,1);
            dfs(matrix,i,n-1,INT_MIN,2);
        }
        for(int i = 0; i < n; i++){
            dfs(matrix,0,i,INT_MIN,1);
            dfs(matrix,m-1,i,INT_MIN,2);
        }
        return res;
    }
};
```
