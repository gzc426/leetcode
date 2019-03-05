```java
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        dfs(0, nums, res, new ArrayList<>());
        return res;
    }

    private void dfs(int s, int[] nums, List<List<Integer>> res, ArrayList<Integer> list) {
        res.add(new ArrayList<>(list));
        for (int i = s; i < nums.length; ++i) {
            if (i > s && nums[i] == nums[i - 1]) {
                continue;
            }
            list.add(nums[i]);
            dfs(i + 1, nums, res, list);
            list.remove(list.size() - 1);
        }
    }
}
```
