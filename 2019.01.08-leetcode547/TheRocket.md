```java
class Solution {
    public int findCircleNum(int[][] M) {
        int n = M.length;
        UnionFind uf = new UnionFind(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (M[i][j] == 1) {
                    uf.union(i, j);
                }
            }
        }
        return uf.count();
    }

    private class UnionFind {
        private int[] f;
        private int count;

        public UnionFind(int n) {
            f = new int[n];
            for (int i = 0; i < n; ++i) {
                f[i] = i;
            }
            count = n;
        }

        private int find(int x) {
            if (x != f[x]) {
                f[x] = find(f[x]);
            }
            return f[x];
        }

        public void union(int p, int q) {
            int i = find(p);
            int j = find(q);
            if (i != j) {
                f[i] = j;
                --count;
            }
        }

        public int count() {
            return count;
        }
    }
}
```
