# leetcode 547
    class Solution {
    static int[] parent;
    static int count;

    public static int findCircleNum(int[][] friends) {
        if (friends == null || friends.length == 0 || friends[0].length == 0) {
            return 0;
        }
        parent = new int[friends.length];
        count = friends.length;
        for (int i = 0; i < friends.length; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < friends.length; i++) {
            for (int j = i+1; j < friends.length; j++) {
                if (friends[i][j] == 1) {
                    union(i, j);
                }
            }
        }
        return count;
    }

    public static void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }
        parent[rootQ] = rootP;
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
