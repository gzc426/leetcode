```java
  public List<int[]> pacificAtlantic(int[][] matrix) {
        
        List<int[]> res = new ArrayList<>();
        boolean[] booleans = new boolean[]{false,false};
        if (matrix.length==0)return res;
        int[][] matrixDemo = new int[matrix.length][matrix[0].length];
        for (int i=0;i<matrix.length;i++){
            for (int j=0;j<matrix[0].length;j++){
                findArea(j,i,matrix,booleans,matrixDemo);
                if (booleans[0]&&booleans[1]){
                    res.add(new int[]{i,j});
                }
                booleans[0]=false;
                booleans[1]=false;
                clear(matrixDemo);
            }
        }
        return res;
    }

    public void findArea(int x, int y ,int[][] matrix, boolean[] booleans, int[][] matrixDemo){

        if (x==0||y==0){
            if (!booleans[0]) booleans[0]=true;
        }
        if (x==matrix[0].length-1||y==matrix.length-1){
            if (!booleans[1]) booleans[1]=true;
        }
        if (booleans[0]&&booleans[1]) return;
        if (matrixDemo[y][x]==0) {
            matrixDemo[y][x]=1;
            if (x > 0 && matrix[y][x] >= matrix[y][x - 1]) findArea(x - 1, y, matrix, booleans, matrixDemo);
            if (x < matrix[0].length - 1 && matrix[y][x] >= matrix[y][x + 1]) findArea(x + 1, y, matrix, booleans, matrixDemo);
            if (y > 0 && matrix[y][x] >= matrix[y - 1][x]) findArea(x, y - 1, matrix, booleans, matrixDemo);
            if (y < matrix.length - 1 && matrix[y][x] >= matrix[y + 1][x]) findArea(x, y + 1, matrix, booleans, matrixDemo);
        }
    }

    public void clear(int[][] matrixDemo){
        for (int i=0;i<matrixDemo.length;i++) {
            for (int j = 0; j < matrixDemo[0].length; j++) {
                if (matrixDemo[i][j]!=0) matrixDemo[i][j]=0;
            }
        }
    }
    
```
