```java
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(candidates, target, 0, res, new ArrayList<Integer>());
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
            list.add(candidates[i]);
            dfs(candidates, target - candidates[i], i, res, list);
            list.remove(list.size() - 1);
        }
    }
}
```
