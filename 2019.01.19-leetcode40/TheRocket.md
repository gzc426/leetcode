```java
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        dfs(candidates, target, 0, res, new ArrayList<>());
        return res;
    }

    private void dfs(int[] candidates, int target, int s, List<List<Integer>> res, ArrayList<Integer> list) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.add(new ArrayList<>(list));
            return;
        }
        for (int i = s; i < candidates.length; ++i) {
            // 不允许重复使用
            if (i > s && candidates[i] == candidates[i - 1]) {
                continue;
            }
            list.add(candidates[i]);
            // 传入下一层的起始参数为 i + 1
            dfs(candidates, target - candidates[i], i + 1, res, list);
            list.remove(list.size() - 1);
        }
    }
}
```
