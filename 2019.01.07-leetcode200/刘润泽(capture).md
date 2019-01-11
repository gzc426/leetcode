```java
  public int numIslands(char[][] grid) {

        int count=0;
        for (int i=0;i<grid.length;i++){
            for (int j=0;j<grid[0].length;j++){

                if (grid[i][j]==49){
                    findArea(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }

    public void findArea(int x, int y, char[][] grid){

        if (x<grid.length&&x>=0&&y>=0&&y<grid[0].length&&grid[x][y]==49){
            grid[x][y]=48;
            findArea(x-1,y,grid);
            findArea(x+1,y,grid);
            findArea(x,y-1,grid);
            findArea(x,y+1,grid);
        }
    }
```
