##班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。

##所谓的朋友圈，是指所有朋友的集合。

##给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。

##你必须输出所有学生中的已知的朋友圈总数。

##示例 1:

##输入: 

##[[1,1,0],
## [1,1,0],
## [0,0,1]]

##输出: 2 

##说明：已知学生0和学生1互为朋友，他们在一个朋友圈。

##第2个学生自己在一个朋友圈。所以返回2。

##示例 2:

##输入: 
##[[1,1,0],
##[1,1,1],
## [0,1,1]]

##输出: 1

##说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。

##注意：

##N 在[1,200]的范围内。

##对于所有学生，有M[i][i] = 1。

#如果有M[i][j] = 1，则有M[j][i] = 1。

```
public int findCircleNum(int[][] M) {
		if (M == null && M.length == 0)
			return 0;
		int n = M.length;
		boolean[] visited = new boolean[n];
		int count = 0;
		//如果dfs大于0，说明有未遍历的结点
		//只需要遍历所有结点
		for (int i = 0; i < n; i++)
			if (dfs(M, i, visited) > 0)
				count++;
		return count;
	}
 
	private int dfs(int[][] mat, int i, boolean[] visited) {
		if (visited[i])
			return 0;
		visited[i] = true;
		int count = 1;
		for (int j = 0; j < visited.length; j++)
			if (i != j && mat[i][j] == 1)
				count += dfs(mat, j, visited);
		return count;
	}
  
几次深度优先遍历能遍历所有值为1 的结点，图的连通性。（for 是所有结点，M[i][j]==1这个判断相当于i的邻接点，深度优先遍历）

public class Solution {
    public void dfs(int[][] M, int[] visited, int i) {
        for (int j = 0; j < M.length; j++) {
            if (M[i][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                dfs(M, visited, j);
            }
        }
    }
    public int findCircleNum(int[][] M) {
        int[] visited = new int[M.length];
        int count = 0;
        for (int i = 0; i < M.length; i++) {
            if (visited[i] == 0) {
                dfs(M, visited, i);
                count++;
            }
        }
        return count;
    }

广度优先遍历：
Queue<Integer> q = new LinkedList<>();
	public void bfs(int[][] M, int[] visited, int i) {
		// visit[i];
		q.offer(i);
		visited[i] = 1;
		while (!q.isEmpty()) {
			int node = q.poll();
			for (int j = 0; j < M.length; j++) {
				// 未被访问过且是邻接点,注意是node的邻接点
				if (visited[j] == 0 && M[node][j] == 1) {
					// visit[j];
					q.offer(j);
					visited[j] = 1;
				}
			}
		}
 
	}
  
	public int findCircleNum(int[][] M) {
		int[] visited = new int[M.length];
		int count = 0;
		for (int i = 0; i < M.length; i++) {
			if (visited[i] == 0) {
				bfs(M, visited, i);
				count++;
			}
		}
		return count;
	}
```
