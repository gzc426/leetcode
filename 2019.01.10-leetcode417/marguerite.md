给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
提示：
输出坐标的顺序不重要
m 和 n 都小于150
 
示例：
给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).

##题目思路很明确，用两个数组来记录哪些点可以去大西洋，
##哪些可以去太平洋，然后将又能去大西洋，又能去太平洋的点输出。判断哪些点能去的思路用启发式的方式递归做。

```
public class Solution {
    public List<int[]> pacificAtlantic(int[][] matrix) {
 
        List<int[]> results = new ArrayList<int[]>();
        int m = matrix.length;
        if(m == 0) return results;
        int n = matrix[0].length;
        int[][] toAtlantic = new int[m][n];
        int[][] toPacific = new int[m][n];
 
        for(int i = 0; i< m; i ++){
            toAtlantic[i][n-1] = 1;
            toPacific[i][0] = 1;
            reactiveCell(matrix,toAtlantic,i,n-1,m,n);
            reactiveCell(matrix,toPacific,i,0,m,n);
        }
        for(int i = 0; i < n; i ++){
            toAtlantic[m-1][i] = 1;
            toPacific[0][i] = 1;
            reactiveCell(matrix,toAtlantic,m-1,i,m,n);
            reactiveCell(matrix,toPacific,0,i,m,n);
        }
 
        for(int i = 0; i < m; i ++)
            for(int j = 0 ; j < n ; j ++){
                if(toAtlantic[i][j] == 1 && toPacific[i][j] == 1){ int[]result = new int[]{i,j}; results.add(result);}
            }
        return  results;
    }
 
    public void reactiveCell(int[][] matrix,int[][] markMatrix,int i,int j,int m,int n){
 
        if( i > 0 && matrix[i-1][j] >= matrix[i][j] && markMatrix[i-1][j] == 0) {markMatrix[i-1][j] = 1;reactiveCell(matrix,markMatrix,i-1,j,m,n);}
        if( i < m-1 && matrix[i+1][j] >= matrix[i][j] && markMatrix[i+1][j] == 0) {markMatrix[i+1][j] = 1;reactiveCell(matrix,markMatrix,i+1,j,m,n);}
        if( j > 0 && matrix[i][j-1] >= matrix[i][j] && markMatrix[i][j-1] == 0) {markMatrix[i][j-1] = 1; reactiveCell(matrix,markMatrix,i,j-1,m,n);}
        if( j < n-1 && matrix[i][j+1] >= matrix[i][j] && markMatrix[i][j+1] == 0) {markMatrix[i][j+1] = 1;reactiveCell(matrix,markMatrix,i,j+1,m,n);}
    }
}

```
