# LeetCode 51
    class Solution {
    List<List<String>> result = new ArrayList<>();
    StringBuilder point = new StringBuilder();
    HashSet<Integer> col = new HashSet<>();
    HashSet<Integer> pie = new HashSet<>();
    HashSet<Integer> na = new HashSet<>();

    public List<List<String>> solveNQueens(int n) {
        for (int i = 0; i < n; i++) point.append('.');
        dfs(n, new ArrayList<Integer>());
        return result;
    }

     void dfs(int n, List<Integer> list) {
        if (list.size() == n) {
            List<String> line = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                point.replace(list.get(i), list.get(i) + 1, "Q");
                line.add(point.toString());
                point.replace(list.get(i), list.get(i) + 1, ".");
            }
            result.add(line);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (col.contains(i)|| pie.contains(list.size()-i) || na.contains(list.size()+i)) {
                continue;
            }
            col.add(i);
            pie.add(list.size() - i);
            na.add(list.size() + i);
            list.add(i);
            dfs(n, list);
            list.remove(list.size()-1);
            col.remove(i);
            pie.remove(list.size() - i);
            na.remove(list.size() + i);
        }
     }
}
