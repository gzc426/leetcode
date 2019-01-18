给定的一个二维网格的地图（’1’（陆地）和0（水）），计数岛的数量。岛屿是四面环水，是由相邻的陆地水平或垂直连接而形成的。

可以假设该网格的所有四个边都被水包围。采用深度优先遍历，把访问过的改为‘0’，继续遍历

```
public class 岛屿的数量 {
	public int numIslands(char[][] grid) {
		if (grid == null || grid.length == 0 
				|| grid[0].length == 0)
			return 0;
		int rows = grid.length;
		int cols = grid[0].length;
		int count = 0;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				// 注意char
				if (grid[i][j] == '1') {
					count++;
					dfsSearch(grid, i, j, rows, cols);
				}
		return count++;
	}
 
	// 每遇到'1'后, 开始向四个方向 递归搜索. 搜到后变为'0',
	// 因为相邻的属于一个island. 然后开始继续找下一个'1'.
	private void dfsSearch(char[][] grid, 
			int i, int j, int rows, int cols) {
		if (i < 0 || i >= rows || j < 0 || j >= cols)
			return;
		if (grid[i][j] != '1')
			return;
		// 也可以才用一个visited数组，标记遍历过的岛屿
		grid[i][j] = '0';
		dfsSearch(grid, i + 1, j, rows, cols);
		dfsSearch(grid, i - 1, j, rows, cols);
		dfsSearch(grid, i, j + 1, rows, cols);
		dfsSearch(grid, i, j - 1, rows, cols);
 
	}
}


```
