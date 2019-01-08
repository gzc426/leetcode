```
class Solution {
public:
 
    int dfs(vector<vector<int>>& grid, int x0, int y0){
        int n, m, sum=1;
        n = grid.size();
        m = grid[0].size();
 
        grid[x0][y0] = 0; //当前元素设置为0，避免再次搜索到
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
 
        for(int i=0; i<4; i++){
            int x = x0 + dir[i][0];
            int y = y0 + dir[i][1];
            if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==1)
                sum+=dfs(grid, x, y);
        }
        return sum;
 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int mx = 0, n, m;
        n = grid.size();
        m = grid[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)   
                    mx = max(dfs(grid,i,j), mx);
            }
        return mx;
    }
};

```
