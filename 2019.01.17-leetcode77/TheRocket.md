```java
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> list = new ArrayList<>(k);
        dfs(n, k, 1, res, list);
        return res;
    }

    private void dfs(int n, int k, int s, List<List<Integer>> res, List<Integer> list) {
        if (list.size() == k) {
            res.add(new ArrayList<>(list));
            return;
        }
        for (int i = s; i <= n; ++i) {
            list.add(i);
            dfs(n, k, i + 1, res, list);
            list.remove(list.size() - 1);
        }
    }
}
```
