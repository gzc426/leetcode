# leetcode 200
    class Solution {
    static int count=0;
    static int[] parent;
    public static int numIslands(char[][] arr) {//并查集解法
        if (arr.length == 0||arr[0].length == 0 ) {
            return 0;
        }
        int length=arr.length * arr[0].length;
        int width=arr[0].length;
        parent = new int[length];
        for (int i = 0; i < length; i++) {
            int x=i/width;
            int y=i%width;
            if (arr[x][y] - '0' == 1) {
                count++;
            }
            parent[i]=i;
        }
        for (int i = 0; i < length; i++) {//为什么考查右边和下方 1 0
            int x=i/width;                                   //1 1如果不考察下方，右下角的1就无法抵消啦
            int y=i%width;
            int down=x+1;
            int right=y+1;
            if (right < width && arr[x][y] - '0' == 1 && arr[x][right] - '0' == 1) {
                union(i, i+1);
            }
            if (down < arr.length && arr[x][y] - '0' == 1 && arr[down][y] - '0' == 1) {
                union(i, i+width);
            }
        }
        return count;

    }

    public static void union(int p,int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }
        parent[rootQ]=rootP;
        count--;
    }

    public static int find(int e) {
        while (parent[e] != e) {
            parent[e] = parent[parent[e]];//让子节点直接连接父节点
            e = parent[e];
        }
        return e;
    }
}
