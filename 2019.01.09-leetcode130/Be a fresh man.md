## 130_(被围绕的区域)Surrounded Regions
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。<br>
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
### 1.2 输入与输出
输入：
* vector< vector< char>>& board:给定二维区域的指针

输出：
* void:原地修改
### 1.3 样例
#### 1.3.1 样例1
输入: <br>
X X X X<br>
X O O X<br>
X X O X<br>
X O X X<br>
输出: <br>
X X X X<br>
X X X X<br>
X X X X<br>
X O X X<br>
解释： <br>
被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'<br> 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

## 2 思路描述与代码	
### 2.1 思路描述（DFS）
1. DFS编辑边界中的 'O'，将边界以及与边界的 'O' 相连的 'O' 标记为 '*'；
2. 然后遍历区域，若区域的值为 '*' ，则更新为 'O'，若区域的值为 O' 则更新为 'X'。

比如输入: <br>
X X X X<br>
X O O X<br>
X X O X<br>
X O X X<br>

经过步骤1处理后为<br>
X X X X<br>
X O O X<br>
X X O X<br>
X * X X<br>

经过步骤2处理后为<br>
X X X X<br>
X X X X<br>
X X X X<br>
X O X X<br>

### 2.2 代码
```cpp
//函数中涉及到的c++知识
//vector<vector<char>> board 是个长度、宽度可变的二维 char 数组，c++里面称为容器
//board.size() 可以获取行数， board[0].size() 可以获取列数
void solve(vector<vector<char>>& board) {
    int row = board.size();
    if(row == 0) return ;
    int col = board[0].size();
    if(col == 0) return ;
    //上下边界DFS
    for( int j = 0; j < col; j++ ){
        DFS(board, 0, j);
        DFS(board, row-1, j);
    }
    //左右边界DFS
    for( int i = 1; i < row - 1; i++ ){
        DFS(board, i, 0);
        DFS(board, i, col-1);
    }
    //根据遍历结果重新更新结果
    //如果是 '*' 则说明该点与边界的 'O' 相连，于是需要更新为 'O'
    //如果是 'O' 则说明该点不与边界的 'O' 相连，于是需要更新为 'X'
    for( int i = 0; i < row; i++ ){
         for( int j = 0; j < col; j++ ){
             if(board[i][j] == 'O') board[i][j] = 'X';
             else if(board[i][j] == '*') board[i][j] = 'O';
         }
    }
    
}
void DFS(vector<vector<char>>& board, int i, int j){
    //越界或者不是与边界0相连的0则返回
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') return ;
    //其他情况就是与边界0相连的0，然后标记为'*'
    board[i][j] = '*';
    DFS(board, i - 1, j);
    DFS(board, i + 1, j);
    DFS(board, i , j - 1);
    DFS(board, i , j + 1);
}
```
## 3 思考与拓展
### 3.1 思考
本题有两个思路，一个是求内部与边界0的连通区域，另外一个是上述描述。一个从内而外，一个从外到内，值得注意的是从外而内思路更清晰，代码也更容易书写。
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
DFS|O(mn)|O(mn)
#### 3.1.3 难点分析
1. 选定由内而外还是由外而内的思路；
2. 选用DFS还是BFS

### 3.2 拓展
可以尝试使用BFS解决该题。
